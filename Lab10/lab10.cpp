#include <cassert>
#include "Vector2.hpp"

int main() {
    Vector2 v1{1.0f, 2.0f};
    Vector2 v2{3.0f, 4.0f};

    // Тесты
    assert(((v1 * 2.0f) == Vector2{4.0f, 6.0f}));
    assert(((2.0f * v1) == Vector2{4.0f, 6.0f}));
    assert(((v1 / 2.0f) == Vector2{1.0f, 1.5f}));

    v1 *= 2.0f;
    assert((v1 == Vector2{4.0f, 6.0f}));

    v1 /= 2.0f;
    assert((v1 == Vector2{2.0f, 3.0f}));

    assert(((v1 + v2) == Vector2{6.0f, 4.0f}));
    assert(((v1 - v2) == Vector2{-2.0f, 2.0f}));

    v1 += v2;
    assert((v1 == Vector2{6.0f, 4.0f}));

    v1 -= v2;
    assert((v1 == Vector2{2.0f, 3.0f}));

    // индексация тесты
    assert(v1[0] == 2.0f);
    assert(v1[1] == 3.0f);
    v1[0] = 5.0f;
    assert((v1 == Vector2{5.0f, 3.0f}));

    // ну и вывод
    std::cout << v1 << std::endl;
    return 0;
}