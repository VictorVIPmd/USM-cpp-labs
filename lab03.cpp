// Типы - int, struct, 
// Объекты - Leg, Arm, Person

#include <array>

struct Leg // тип Struct 
{
    int length; // тип int, объекта Length
};

struct Arm // тип Struct 
{
    int power; // тип int, объекта Power
};

struct Person // тип Struct 
{
    std::array<Leg, 2> legs; // Объекты
    Arm arms[2]; // Объекты
};
int main() // тип Int
{
    Person person; //Объект
}