#pragma once

#include <cassert>
#include <span>

struct Array
{
    int* data;
    size_t length;
    size_t capacity;
};

Array createArrayWithCapacity(size_t capacity);
Array createArray();

void addElementToArray(Array* array, size_t value);
size_t getElementAtIndex(const Array* array, size_t index);

std::span<int> getCurrentSpan(const Array* array);
void destroyArray(Array* array);