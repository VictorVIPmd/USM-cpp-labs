/*
1. Если количество яблок больше 5, количество груш меньше 8
   и количество апельсинов в 2 раза больше чем количество яблок,
   напечатайте на экран "Hello".

2. Сделайте временную переменную с результатом выражения.
   Проверяйте ее в if.

3. Сделайте по временной переменной для каждого из подусловий.
   Вычисляйте общее условие, используя эти подусловия.

4. Объявите временные переменные подусловий в блоке,
   чтобы эти переменные не были видны за пределами блока.

5. Зарефакторьте 3 переменные с количеством фруктов в одну структуру (`FruitCounts`)
   с 3 полями, по одному для каждого типа фруктов.
   Переделайте код, чтобы везде использовалась эта структура.
*/

#include <iostream>

struct FruitCounts {
    int apples;
    int pears;
    int oranges;
};

void main()
{
   FruitCounts fruits;

   int apples;
   int pears;
   int oranges;

   std::cout << "Apples:";
   std::cin >> fruits.apples;

   std::cout << "Pears:";
   std::cin >> fruits.pears;

   std::cout << "Oranges:";
   std::cin >> fruits.oranges;
    
   bool x;
   {
      bool x1 = fruits.apples > 5;
      bool x2 = fruits.pears < 8;
      bool x3 = fruits.oranges == apples*2;
      x = x1 && x2 && x3;
   }

   if (x){
      std::cout << "Hello";
   }
}