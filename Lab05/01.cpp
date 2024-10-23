/*
Задание 1
Сделайте функцию, которая считает сколько символов 1 в строке (std::string_view).

Сделайте несколько тестов для всех случаев (ни одной 1, несколько 1, все 1) используя assert.

Пример
void runTests()
{
    assert(countOnes("001100") == 2);
    // ...
}
*/

#include <iostream>
#include <string_view>
#include <cassert>

// Функция для нахождения
size_t countOnes(std::string_view str) {
    size_t count = 0; // Для рузультата
    for (char ch : str) {
        if (ch == '1') {
            ++count;
        }
    }
    return count; // Возврается кол-во символов 1
}

// Тестирования
void runTests() {
    assert(countOnes("001100") == 2);  // Ожидаем 2 символа '1'
    assert(countOnes("1111") == 4);    // Ожидаем 4 символа '1'
    assert(countOnes("0000") == 0);    // Ожидаем 0 символов '1'
    assert(countOnes("1010101") == 4); // Ожидаем 4 символа '1'
    assert(countOnes("") == 0);        // Пустая строка — 0 символов '1'
    assert(countOnes("00001") == 1);   // Ожидаем 1 символ '1'
    assert(countOnes("1110111011") == 8); // Ожидаем 8 символов '1'

    std::cout << "Всё ок" << std::endl;
}

int main() {
    runTests();
    return 0;
}
