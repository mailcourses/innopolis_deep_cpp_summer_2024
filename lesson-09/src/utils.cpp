#include "utils.hpp"
#include <cmath>


int foo(int num, int pow)
{
    while(pow) {
        num *= num;
    }
    return num;
}

int square(Point p1, Point p2)
{
    return std::abs((p1.x - p2.x) * (p1.y - p2.y));
}
