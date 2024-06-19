#include <iostream>

static int i = 0;
extern int gMagic;
//extern int sMagic;

int foo()
{
    static int j = 0;
    int k = 0;
    j += 10 + i;
    return j;
}

namespace test
{
    int foo()
    {
        return 0;
    }
}

int foo(int num)
{
    return num;
}

class Foo
{
    int foo()
    {
        return 0;
    }
};

void boo()
{
    i += 100;
}

extern "C" {
    int moo()
    {
        return 0;
    }

    class A
    {
    public:
        A() {}
        int a = 0;
    };

}

int main()
{
    std::cout << "[before] i = " << i << ", gMagic = " << gMagic << std::endl;
    for (size_t i = 0; i < 10; ++i) {
        std::cout << "j=" << foo() << std::endl;
        boo();
    }
    std::cout << "[after] i = " << i << ", gMagic = " << gMagic << std::endl;
    //std::cout << "sMagic=" << sMagic << std::endl;
    moo();
    A a;
}
