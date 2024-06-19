#include <iostream>
#include <memory>

void foo(std::unique_ptr<int[]> &/*tmp*/)
{
    //..
}

void foo(std::shared_ptr<char[]> tmp)
{
    std::cout << "within foo: " << tmp.use_count() << std::endl;
}

/*
template<class T>
class shared_ptr
{
    struct data {
        size_t counter_ = 0;
        T* data_ = nullptr;
    };

    data* info_ = nullptr;
};
*/

int main()
{
    {
        int* arr = new int[26];
        std::unique_ptr<int[]> ptr1(new int[26]);
        delete[] arr;
        std::unique_ptr<int[]> ptr2(new int[33]);
        int* arr2 = ptr1.get();
        arr2[0] = 1;
        arr2[2] = 1;
        //delete[] arr2; // seg fault
        foo(ptr1);
    }

    {
        std::shared_ptr<char[]> ptr1(new char[26]);
        std::cout << "counter after ptr1: " << ptr1.use_count() << std::endl;
        std::shared_ptr<char[]> ptr2(ptr1);
        std::shared_ptr<char[]> ptr3(new char('A'));
        ptr3.reset(new char('B'));
        ptr3 = ptr2;
        std::cout << "counter after ptr2: " << ptr1.use_count() << std::endl;
        foo(ptr2);
    }
    return 0;
}
