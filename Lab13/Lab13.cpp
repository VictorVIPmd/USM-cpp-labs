#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>
#include <string>

struct Payload {
    void* content;

    template<typename T>
    T* extract() {
        return static_cast<T*>(content);
    }
};

using HandlerFunction = std::function<void(Payload*)>;

struct Callback {
    size_t id;
    HandlerFunction function;

    Callback(size_t id, HandlerFunction&& function) : id(id), function(std::move(function)) {}
};

struct EventDescriptor {
    size_t id;
    std::string label;

    EventDescriptor() : id(0), label("") {}

    EventDescriptor(size_t id, std::string&& label) : id(id), label(std::move(label)) {}
};

struct CallbackDescriptor {
    size_t id;
};

struct EventManager {
    std::unordered_map<size_t, std::vector<Callback>> callbacks;
    std::unordered_map<size_t, EventDescriptor> events;
    size_t nextEventId = 1;
    size_t nextCallbackId = 1;

    EventDescriptor& registerEvent(std::string&& eventName) {
        EventDescriptor event(nextEventId++, std::move(eventName));
        return events[event.id] = std::move(event);
    }

    CallbackDescriptor attachCallback(size_t eventId, HandlerFunction&& function) {
        if (events.find(eventId) == events.end()) {
            throw std::invalid_argument("Invalid event ID.");
        }
        callbacks[eventId].emplace_back(nextCallbackId, std::move(function));
        return { nextCallbackId++ };
    }

    bool detachCallback(size_t eventId, size_t callbackId) {
        auto it = callbacks.find(eventId);
        if (it == callbacks.end()) return false;

        auto& callbackList = it->second;
        auto removeIt = std::remove_if(callbackList.begin(), callbackList.end(),
                                       [callbackId](const Callback& callback) {
                                           return callback.id == callbackId;
                                       });
        if (removeIt != callbackList.end()) {
            callbackList.erase(removeIt, callbackList.end());
            return true;
        }
        return false;
    }

    void triggerEvent(size_t eventId, Payload* payload) {
        auto it = callbacks.find(eventId);
        if (it == callbacks.end()) return;

        for (auto& callback : it->second) {
            callback.function(payload);
        }
    }

    void listEvents() const {
        for (const auto& [eventId, event] : events) {
            std::cout << "Event ID: " << eventId << " (" << event.label << ")\n";
            auto it = callbacks.find(eventId);
            if (it != callbacks.end()) {
                for (const auto& callback : it->second) {
                    std::cout << "  Callback ID: " << callback.id << "\n";
                }
            }
        }
    }
};

void handlerIncrement(Payload* payload) {
    int* data = payload->extract<int>();
    *data += 10;
    std::cout << "Incremented by 10: " << *data << "\n";
}

void handlerDouble(Payload* payload) {
    int* data = payload->extract<int>();
    *data *= 2;
    std::cout << "Doubled: " << *data << "\n";
}

void menu(EventManager& manager) {
    while (true) {
        int choice;
        std::cout << "Menu:\n1. Register Event\n2. Attach Callback\n3. Detach Callback\n4. List Events\n5. Trigger Event\n6. Exit\n";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            std::cout << "Enter event name: ";
            std::cin >> name;
            EventDescriptor& event = manager.registerEvent(std::move(name));
            std::cout << "Event registered with ID " << event.id << "\n";
        } else if (choice == 2) {
            size_t eventId;
            std::cout << "Enter event ID: ";
            std::cin >> eventId;

            std::cout << "Choose callback:\n1. Increment by 10\n2. Double\n";
            int callbackChoice;
            std::cin >> callbackChoice;

            HandlerFunction function;
            if (callbackChoice == 1) {
                function = handlerIncrement;
            } else if (callbackChoice == 2) {
                function = handlerDouble;
            } else {
                std::cout << "Invalid choice.\n";
                continue;
            }

            CallbackDescriptor descriptor = manager.attachCallback(eventId, std::move(function));
            std::cout << "Callback attached with ID " << descriptor.id << "\n";
        } else if (choice == 3) {
            size_t eventId, callbackId;
            std::cout << "Enter event ID and callback ID to detach: ";
            std::cin >> eventId >> callbackId;
            if (manager.detachCallback(eventId, callbackId)) {
                std::cout << "Callback detached.\n";
            } else {
                std::cout << "Callback not found.\n";
            }
        } else if (choice == 4) {
            manager.listEvents();
        } else if (choice == 5) {
            size_t eventId;
            std::cout << "Enter event ID to trigger: ";
            std::cin >> eventId;

            int data;
            std::cout << "Enter data: ";
            std::cin >> data;
            Payload payload{ &data };
            manager.triggerEvent(eventId, &payload);
        } else if (choice == 6) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
}

int main() {
    EventManager manager;
    menu(manager);
    return 0;
}