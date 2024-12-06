/*
- Сделайте функцию которая попарно перемножает числа из 2 массивов, записывая результат в 1-ый массив.

- Убедитесь в ней в том, что спаны одинаковой длины, используя `assert`.
- Реализуйте версию с бесконечным циклом, используя `break` вручную.
- Реализуйте версию с циклом `while` с условием.
- Реализуйте версию с циклом `for`.
*/

//Добавил вывод информации в отдельную функцию!

#include <iostream>
#include <span>
#include <array>
#include <cassert>
#include <cstddef>

int main()
{
    std::array array1{1, 2, 3, 4, 5};
    std::array array2{5, 4, 3, 2, 1};

    product(array1, array2);

    std::cout << "Array inputOutput: " << std::endl;
    for (int i : array1) {
        std::cout << i << std::endl;
    }

}

void Print(std::span<int> inputOutput, std::span<int> coefficients)
{
    int i = 0;
    while(i < inputOutput.size()){
        std::cout << "inputOutput[" << i << "] = " << inputOutput[i] << ", coef[" << i << "] = " << coefficients[i] << std::endl;
        i++;
    }
}

void product(std::span<int> inputOutput, std::span<int> coefficients)
{
    // Проверка на одинаковый размер массивов
    assert(inputOutput.size() == coefficients.size());

    while (true) {
        for (int i = 0; i < inputOutput.size(); i++) {
            inputOutput[i] = inputOutput[i] * coefficients[i];
           
            Print(inputOutput, coefficients);
        }
        break;
    }

    /*
    while (int i < inputOutput.size()) {
        inputOutput[i] = inputOutput[i] * coefficients[i];
        Print(inputOutput, coefficients);
        i++;
    } */

    /*
    for (int i = 0; i < inputOutput.size(); i++) {
        inputOutput[i] = inputOutput[i] * coefficients[i];
        Print(inputOutput, coefficients);
    } */
}