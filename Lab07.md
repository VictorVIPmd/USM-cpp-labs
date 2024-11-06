1) Что такое метод?  
    Метод — это функция, которая определена внутри класса и предназначена для выполнения действий с объектами этого класса.

2) Что такое "функция-член"?  
    Функция-член — это другое название метода, то есть функция, связанная с классом, которая может изменять или использовать его члены - данные или другие методы.

3) Что такое член класса?  
    Член класса — это переменная или метод, объявленные в области видимости класса..

4) Чем отличается instance-функция (функция-экземпляр) от статической функции?  
    Функция-экземпляр требует создания объекта класса для вызова, и она может обращаться к переменным и методам, принадлежащим конкретному экземпляру.  
    Статическая функция может быть вызвана без создания объекта класса, не имеет доступа к переменным экземпляра и может обращаться только к статическим членам класса.

5) Какой синтаксис вызова методов?  
    - Вызов метода экземпляра:  
        object.method(parameter);  — где object является объектом класса, а method — его функция-член.
    - Вызов статического метода:  
        ClassName::staticMethod(parameter); — где ClassName — это имя класса, а staticMethod — статический метод.

6) Как объявить метод, а определить его отдельно?  
    Внутри класса метод можно объявить, а его определение дать снаружи:  
    
    class MyClass {
        public:
            static void myMethod(); // Объявление метода
    };

    // Определение метода вне класса
    void MyClass::myMethod() {
        std::cout << "Hello" << std::endl; 
    }
    

7) Возможно ли определить метод внутри класса, который будет статическим для линкера (определен только для текущего compilation unit)?  
    Этого сделать нельзя. Однако можно объявить все методы класса как static, чтобы они были связаны только с текущим компиляционным модулем.

8) Обязателен ли оператор new, чтобы создать объект класса (или структуры с методами)?  
    Нет, оператор new не обязателен. Можно создать объект на стеке, не используя динамическую память:
        MyClass obj;

    Если использовать new - создает объект в динамической памяти, значит понадобится освобождение:
            MyClass obj = new MyClass();


9) Влияет ли количество методов класса на объем памяти, занимаемой объектом этого класса?  
    Нет, методы не увеличивают объем памяти, занимаемый объектом. Память объекта зависит от его переменных-членов, а методы хранятся отдельно и не добавляют размеру экземпляра.

10) Занимает ли объект с одним методом больше памяти, чем объект без методов?  
    Нет, наличие методов не увеличивает размер объекта, поскольку методы хранятся отдельно от данных объекта.

11) В чем функциональное преимущество использования методов вместо обычных функций, принимающих this-подобный параметр явно?  
    Методы позволяют более структурированно организовать код и делают его более читаемым.
    Использование this скрыто позволяет избежать явной передачи объекта, к которому метод применяется, что повышает удобство и улучшает понимание кода.