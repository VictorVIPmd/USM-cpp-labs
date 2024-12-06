#include "HeapInt.h"

// копирования
HeapInt::HeapInt(const HeapInt& other)
{
    heapValue = new int{ *other.heapValue };
}

HeapInt::HeapInt(HeapInt&& other)
{
    heapValue = other.heapValue;
    other.heapValue = nullptr;
}

void HeapInt::operator=(const HeapInt& other)
{
    if (this == &other) {
        return;
    }

    delete heapValue;

    heapValue = new int{ *other.heapValue };
}

void HeapInt::operator=(HeapInt&& other)
{
    if (this == &other) {
        return;
    }

    delete heapValue;

    heapValue = other.heapValue;

    other.heapValue = nullptr;
}