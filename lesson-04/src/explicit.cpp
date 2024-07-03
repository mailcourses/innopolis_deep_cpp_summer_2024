#include <iostream>

struct A
{
    explicit A(int) { std::cout << "A(int)" << std::endl;}
    A(const A&) { std::cout << "A(const A&)" << std::endl;}
    A(A&&) { std::cout << "A(A&&)" << std::endl;}
};

int main()
{
    A a = A(1);
}
