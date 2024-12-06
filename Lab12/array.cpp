#include "array.hpp"
#include <cassert>
#include <cstdlib>
#include <cstring>

static void resizeArray(Array* array, int newCapacity)
{
    int* newData = (int*)std::malloc(newCapacity * sizeof(int));
    std::memcpy(newData, array->data, array->length * sizeof(int));
    std::free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

Array createArrayWithCapacity(int capacity)
{
    assert(capacity > 0);
    
    Array array;
    array.data = (int*)std::malloc(capacity * sizeof(int));
    array.length = 0;
    array.capacity = capacity;
    
    return array;
}

Array createArray()
{
    return createArrayWithCapacity(4);
}

void addElementToArray(Array* array, int value)
{
    if (array->length >= array->capacity)
    {
        resizeArray(array, array->capacity * 2);
    }
    array->data[array->length++] = value;
}

int getElementAtIndex(const Array* array, int index)
{
    assert(index >= 0 && index < array->length);
    
    return array->data[index];
}

std::span<int> getCurrentSpan(const Array* array)
{
    return { array->data, array->length };
}