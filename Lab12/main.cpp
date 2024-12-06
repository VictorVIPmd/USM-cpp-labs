#include "array.hpp"
#include <cassert>
#include <iostream>

void TEST01()
{
    Array arr = createArrayWithCapacity(10);
    assert(arr.capacity == 10);
}

void TEST02()
{
    Array arr = createArray();
    assert(arr.length == 0);
    
    addElementToArray(&arr, 5);
    assert(arr.length == 1);
}

void TEST03()
{
    Array arr = createArrayWithCapacity(1);
    
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1);
    
    addElementToArray(&arr, 10);
    assert(arr.capacity == 2);
    
    addElementToArray(&arr, 20);
    assert(arr.capacity == 4);
}

void TEST04()
{
    Array arr = createArray();
    addElementToArray(&arr, 5);
    
    int el = getElementAtIndex(&arr, 0);
    assert(el == 5);
}

void TEST05()
{
    Array arr = createArray();
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 6);
    addElementToArray(&arr, 7);

    std::span<int> span = getCurrentSpan(&arr);

    assert(span.size() == 3);
    assert(span[0] == 5);
    assert(span[1] == 6);
    assert(span[2] == 7);
}

int main()
{
    TEST01();
    TEST02();
    TEST03();
    TEST04();
    TEST05();

    std::cout << "Всё гуд" << std::endl;

    return 0;
}