#include <iostream>
#include <functional>

void foo(int num, double d, std::string str)
{
    std::cout << "num = " << num << " d = " << d << " str = " << str << std::endl;
}

int main()
{
    foo(10, 0.5, "Hello, Peter");
    auto hello_func = std::bind(foo, std::placeholders::_1, std::placeholders::_2, std::string{"Hello, Otto"});
    hello_func(20, 5.5);
    auto num_func = std::bind(foo, 100, std::placeholders::_1, std::placeholders::_2);
    auto double_func = std::bind(foo, std::placeholders::_1, 100.5, std::placeholders::_2);
    num_func(10.5, std::string{"Hello, MJ"});
    double_func(30, std::string{"Hello, Norman"});
}
