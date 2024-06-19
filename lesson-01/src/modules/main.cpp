#include <iostream>

import math;

int main()
{
    std::cout << sum(100000, 500) << std::endl;
    std::cout << math::square(5) << std::endl;
    foo();
    boo();
    // TODO: почему не импортируется с const??
    std::cout << gMagicVar << std::endl;
    //unexport_func();
}
