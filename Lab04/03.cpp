/*
- Сделайте функцию которая попарно перемножает числа из 2 массивов, записывая результат в 1-ый массив.
```

- Убедитесь в ней в том, что спаны одинаковой длины, используя `assert`.

- Реализуйте версию с бесконечным циклом, используя `break` вручную.

- Реализуйте версию с циклом `while` с условием.

- Реализуйте версию с циклом `for`.
*/

#include <iostream>
#include <span>

void product(std::span<int> inputOutput, std::span<int> coefficients)
{
    assert(inputOutput.size() == coefficients.size());
    return 0;

    for(int i = 0; i < inputOutput.size(); i++){
        inputOutput[i] *= coefficients[i];
    }
}

void main(){
    int numbers1[4] = {1, 2, 3, 4};
    int numbers2[4] = {11, 22, 33, 44};

    product (numbers1, numbers2);
}