enum Test
{
    a = 1,
    b = 2 // 2
};

enum Test
{
    a = 1,
    b // 2
};

enum Test
{
    a, // 0
    b // 1
};

enum Test
{
    a = -1,
    b // 0
};

enum Test
{
    a = (5 + 10 * 5) / 5, // 11
    b // 12
};

enum Test
{
    other = 5,
    a = other + 6, // 11
    b // 12
};

enum Test
{
    a = '5',
    b = '7' // 55, '7'
};

enum Test
{
    a = '5',
    b // 54, '6'
};

enum Test
{
    a = 'b',
    b // 99, 'c'
};

enum Test
{
    a = 'a' + '1',
    b // 147
};
