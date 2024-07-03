#include <iostream>

struct A
{
public:
    virtual void help()
    {
        std::cout << "A::help" << std::endl;
    }
};

struct B : A
{
public:
    virtual void help() override
    {
        std::cout << "B::help" << std::endl;
    }

    void methodSpecificToB()
    {
        std::cout << "B::methodSpecificToB: " << this->counter << std::endl;
    }
int counter = 100500;
};

struct C : A
{
public:
    virtual void help() override
    {
        std::cout << "C::help" << std::endl;
    }

};

A* fabric(int num)
{
    if (num == 1) {
        return new B();
    }

    if (num == 2) {
        return new C();
    }

    return nullptr;
}

void foo(A& a)
{
    a.help();
    try {
        B& b = dynamic_cast<B&>(a);
        b.methodSpecificToB();
    } catch(std::bad_cast &ex) {
        std::cerr << "Этот объект не является объектом типа B" << std::endl;
    }
}

int main(int argc, char** argv)
{
    int num = std::stoi(argv[1]);
    A* obj = fabric(num);
    foo(*obj);
}
