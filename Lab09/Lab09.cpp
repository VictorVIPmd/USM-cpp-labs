#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

// Возможные варианты
enum class Portrait {
    Lenin,
    Washington,
    Hitler
};

enum class LampColor {
    Blue,
    White,
    Red
};

enum class WireColor {
    Red,
    Yellow,
    Green
};

//цвета лампочки
int getLampValue(LampColor color, bool isHitler) {
    if (isHitler) { //для Гитлера
        switch (color) {
            case LampColor::Blue: return 15;  // Blue -> White
            case LampColor::White: return 35; // White -> Red
            case LampColor::Red: return 11;   // Red -> Blue
        }
    } else { //для Вашингтона
        switch (color) {
            case LampColor::Blue: return 11;
            case LampColor::White: return 15;
            case LampColor::Red: return 35;
        }
    }
    return 0;
}

//для циклического сдвига цвета провода (вправо или влево)
WireColor shiftWire(WireColor color, int shift) {
    int totalColors = 3; // Всего три цвета: Red, Yellow, Green
    int current = static_cast<int>(color);
    int shifted = (current + shift + totalColors) % totalColors; // Циклический сдвиг
    return static_cast<WireColor>(shifted);
}

//цвет провода в строку для вывода
std::string wireColorToString(WireColor color) {
    switch (color) {
        case WireColor::Red: return "Red";
        case WireColor::Yellow: return "Yellow";
        case WireColor::Green: return "Green";
    }
    return "Unknown";
}

// Основная функция для определения, какой провод перерезать
std::string determineWireToCut(Portrait portrait, LampColor lampColor, bool switchOn, int dialValue) {
    //Если Ленин, ничего резать не нужно
    if (portrait == Portrait::Lenin) {
        return "Do nothing, no wire needs to be cut.";
    }

    //Числовое значение цвета лампочки
    int lampValue = getLampValue(lampColor, portrait == Portrait::Hitler);

    //Если значение на циферблате равно значению лампочки, режем зеленый провод
    if (dialValue == lampValue) {
        WireColor wireToCut = WireColor::Green;
        if (switchOn) {
            wireToCut = shiftWire(wireToCut, -1); // Если тумблер включен, сдвигаем цвет
        }
        return "Cut the " + wireColorToString(wireToCut) + " wire.";
    }

    // Если значение на циферблате меньше значения лампочки - режем красный провод
    if (dialValue < lampValue) {
        WireColor wireToCut = WireColor::Red;
        if (switchOn) {
            wireToCut = shiftWire(wireToCut, -1); // Если тумблер включен, сдвигаем цвет
        }
        return "Cut the " + wireColorToString(wireToCut) + " wire.";
    }

    //если значение на циферблате делится на 4, выполняем сдвиг цвета вправо
    int shift = (dialValue % 4 == 0) ? 1 : 0;
    WireColor wireToCut = WireColor::Yellow; // По умолчанию режется желтый
    if (shift > 0) {
        wireToCut = shiftWire(wireToCut, shift);
    }
    return "Cut the " + wireColorToString(wireToCut) + " wire.";
}

int main() {
    // Тестовые случаи
    assert(determineWireToCut(Portrait::Lenin, LampColor::Blue, false, 10) == "Do nothing, no wire needs to be cut.");
    assert(determineWireToCut(Portrait::Washington, LampColor::Blue, false, 10) == "Cut the Red wire.");
    assert(determineWireToCut(Portrait::Washington, LampColor::Blue, true, 10) == "Cut the Green wire.");
    assert(determineWireToCut(Portrait::Hitler, LampColor::Red, false, 11) == "Cut the Green wire.");

    //тест
    Portrait portrait = Portrait::Washington;
    LampColor lampColor = LampColor::Blue;
    bool switchOn = true;
    int dialValue = 14;

    std::cout << determineWireToCut(portrait, lampColor, switchOn, dialValue) << std::endl;
    return 0;
}
