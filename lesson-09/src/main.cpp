#include <iostream>
#include "utils.hpp"

int main()
{
    Point p1, p2;
    p1.x = 20;
    p1.y = 10;
    p2.x = -5;
    p2.y = -5;
    std::cout << "square: " << square(p1, p2) << std::endl;
    return 0;
}
