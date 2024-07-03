#include <iostream>

template<typename T>
void f(T&& param)
{
    std::cout << "f(T&&)" << std::endl;
}

template<typename T>
void f(T& param)
{
    std::cout << "f(T&)" << std::endl;
}

int main()
{
    int x = 10;
    f(x);
    f(std::move(x));
}
