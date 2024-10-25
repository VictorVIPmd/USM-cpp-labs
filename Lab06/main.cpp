#include <iostream>


static int hello(int x) {
    return x + 10;
}

int main() {
    int result = hello(5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
