#include <cassert>
#include <string>
#include <string_view>

std::string_view secondWord(std::string_view str) {
    char separator = ' ';

    size_t firstSpace = str.find(separator);
    
    if (firstSpace == std::string_view::npos) {
        return "";
    }
    
    size_t secondSpace = str.find(separator, firstSpace + 1);
    
    if (secondSpace == std::string_view::npos) {
        return str.substr(firstSpace + 1);
    }
    
    return str.substr(firstSpace + 1, secondSpace - firstSpace - 1);
}

int main() {
    assert(secondWord("Hello world") == "world");
    assert(secondWord("Hello my dear") == "my");
    assert(secondWord("") == "");
    assert(secondWord(" ") == "");
    assert(secondWord(" a ") == "a");
    assert(secondWord("a  ") == "");
    assert(secondWord("a  b") == "");
    assert(secondWord("hello     world    dear") == "");
}
