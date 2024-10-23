#include <string.h>
#include <iostream>

struct TwoInts
{
    int a;
    int b;
};

struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    //Инициализация - Поля a и b будут нулями
    TwoInts i2 = { };
    i2.a = 5;  // Присваиваем a значение 5
    i2.b = 7;  // Присваиваем b значение 7

    std::cout << i2.a << std::endl;  // Выведет 5
    std::cout << i2.b << std::endl;  // Выведет 7
    
    // Массив arr из 4 элементов обнулён
    StructWithArray s = { };
    s.arr[0] = 10;  // Присваиваем первому элементу массива arr значение 10

    StructWithArray s1 = { };  // Ещё одна структура, где массив arr обнулён
    s1.arr[0] = 15;  // Первый элемент массива arr - 15
    
    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20;  // Меняется первый элемент массива arr через указатель, теперь arr[0] = 20

    std::cout << s.arr[0] << std::endl;  // Выведет 20 - логично

    s.arr[0] = 25;  // Меняется значение первого элемента на 25 напрямую
    std::cout << s.arr[0] << std::endl;  // Выведет 25

    sPointer->arr[0] = 30;  // Снова меняем через указатель, теперь arr[0] = 30
    std::cout << s.arr[0] << std::endl;  // Выведет 30

    sPointer = &s1;  // Теперь указатель указывает на структуру s1
    sPointer->arr[0] = 35;  // Меняем первый элемент массива arr в структуре s1 на 35
    std::cout << s.arr[0] << std::endl;  // Выведет 30, в структуре s, а не s1
    std::cout << s1.arr[0] << std::endl;  // Выведет 35 - изменённое значение в структуре s1

    // Аrr обнулены
    StructWithArray structArray[2] = { };
    structArray[0].arr[3] = 77;  // Присваиваем 77 четвертому элементу массива arr в первой структуре
    structArray[1].someNumber = &structArray[0].arr[3];  // someNumber во второй структуре указывает на structArray[0].arr[3]

    sPointer = &s;
    int* pointer = &sPointer->arr[3];  // Указатель на четвёртый элемент массива arr в структуре s
    s.arr[3] = 72;  // Присваиваем значение 72
    std::cout << *pointer;  // Выведет 72

    // Обнуляется память
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    return 0;
}
