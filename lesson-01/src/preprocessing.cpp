#include <iostream>

#define NAME(world) #world

int main()
{
    #line 107
    std::cout << "Hello " << NAME(world) << __LINE__ << __FILE__ << std::endl;
    return 0;
}
