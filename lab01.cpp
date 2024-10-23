 #include <iostream>

int main() {
    int i = 69;
    int number = 72;
    i = i + number;

    int arr[3] = {0, 0, 0};
    int* iPointer = &i;

    number = *iPointer;
    *iPointer = 15;
    iPointer = &arr[0];
    iPointer += 2;
    
    // 10 - 11
    arr[0] = 5;
    *iPointer = 6;
    
    std::cout << "i = " << i << std::endl;
    std::cout << "number = " << number << std::endl;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "arr[1] = " << arr[1] << std::endl;
    std::cout << "arr[2] = " << arr[2] << std::endl;

    return 0;
}
