#include <iostream>

int main()
{
    int a = 0;
    std::string str{}; // == std::string str("");, std::string str;
    auto lfunc = [&](int num, char ch) -> int {
        a += num;
        str.push_back(ch);
        return a + num;
    };

    lfunc(100, 'h');
    std::cout << "a = " << a << ", str = " << str << std::endl;
}
