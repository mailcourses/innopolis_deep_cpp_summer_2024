#include <iostream>

template<typename T>
concept HasFoo =
    requires(T t) {
        //{ t.foo() } -> std::same_as<int>;
        { t.foo() } -> std::convertible_to<int>;
    };

template<HasFoo T>
void boo(T t)
{
    std::cout << "boo with t.foo()->int" << std::endl;
}

template<class T>
void boo(T t)
{
    std::cout << "boo without t.foo()->int" << std::endl;
    //t.help();
}

struct Foo
{
    int foo() { return 100500; }
    using supertype = int;
    void help() {};
    //static int supertype = 100500;
};

struct Boo
{
    std::string foo() { return std::string{}; }
};

struct Moo
{
    float foo() { return 2.0f; }
};

int main()
{
    boo(Foo());
    boo(Boo());
    boo(Moo());
    Foo::supertype a;
}


