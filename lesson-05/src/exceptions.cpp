#include <iostream>
#include <exception>

class A
{
public:
    A() : array(new int[1024])
    {
        std::cout << "A()" << std::endl;
        try {
            init();
        } catch(...) {
            std::cout << "all exceptions" << std::endl;
        }
    }

    ~A() noexcept(false)
    {
        std::cout << "~A()" << std::endl;
        delete[] array;
        throw std::exception();
    }
private:
    void init()
    {
        throw std::exception();
    }
private:
    int* array;
};

int main()
{
    try {
        A a;
    } catch (std::exception&) {
        std::cout << "Catched exception"  << std::endl;
    }
}
