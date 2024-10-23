/* Задание 2
Сделайте функцию, которая находит в строке 'пробел', и выдает кусок строки от позиции после этой позиции до следующего 'пробел'.
Если следующего нет, пускай выдает остальную часть строки.

Сделайте тесты, как в прошлом задании.
*/


#include <iostream>
#include <cassert>
#include <string>

std::string secondWord(const std::string& str) {
    // Первый пробел
    size_t firstSpace = str.find(' ');

    // Если нет пробела или строка пуста
    if (firstSpace == std::string::npos || firstSpace == str.size() - 1) {
        return "";
    }

    // Пропускаем все пробелы после первого пробела
    size_t startPos = str.find_first_not_of(' ', firstSpace);

    // Если нет символов после пробелов
    if (startPos == std::string::npos) {
        return "";
    }

    // Следующий пробел после найденного слова
    size_t secondSpace = str.find(' ', startPos);

    // Возвращаем слово до следующего пробела или до конца строки
    return str.substr(startPos, secondSpace - startPos);
}


// Тесты
void runTests() {
    assert(secondWord("Hello world") == "world");
    assert(secondWord("Hello my dear") == "my");
    assert(secondWord("") == "");
    assert(secondWord(" ") == "");
    assert(secondWord(" a ") == "a");
    assert(secondWord("a  ") == "");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}
