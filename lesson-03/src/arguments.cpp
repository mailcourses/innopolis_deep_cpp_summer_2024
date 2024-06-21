#include <iostream>

class Dummy
{
public:
    Dummy() = default;
    Dummy(const Dummy& rhs) : data_(rhs.data_)
    {
        std::cout << "Dummy copy ctr" << std::endl;
    }
public:
    std::string data_;
};

void foo(const Dummy& rhs, int& counter)
{
    rhs.data_.size();
    //rhs.data_.push_back('!'); <-- не const-метод push_back.
    int tmp = 0;
    tmp++; // 0, tmp = 1
    ++tmp; // 2, tmp = 2
    //for(size_t i = 0; i < rhs.data_.size(); ++i)
    for (char ch : rhs.data_) {
        ++counter; // counter++
    }
}

void boo(Dummy rhs, int* counter)
{
    if (!counter) {
        return;
    }
    rhs.data_.push_back('#');
    for (char ch : rhs.data_) {
        ++(*counter); // counter++
    }
}

int main()
{
    Dummy dummy;
    int counter1 = 0;
    int counter2 = 0;
    dummy.data_ = std::string{"Hello, world"};
    std::cout << "foo()" << std::endl;
    foo(dummy, counter1);
    std::cout << "boo()" << std::endl;
    boo(dummy, &counter2);
    //boo(dummy, nullptr);
    std::cout << "dummy.data_ = " << dummy.data_ << std::endl;
    std::cout << "counter1 = " << counter1 << std::endl;
    std::cout << "counter2 = " << counter2 << std::endl;

    counter1 = counter2 = 0;
    //
    {
        int* ptr1 = &counter1;
        int** ptr1_1 = &ptr1;
        int*** ptr1_1_1 = &ptr1_1;

        (*ptr1) = 10;
        ptr1 = &counter2;
    }

    {
        const int* ptr2 = &counter2;
        // ==
        // int const* ptr2 = &counter2;
        //(*ptr2) = 20; <-- read-only
        ptr2 = &counter1;
    }

    {
        int* const ptr3 = &counter1;
        (*ptr3) += 30;
        // ptr3 = &counter2; <-- read-only
    }

    {
        const int* const ptr4 = &counter2;
        //(*ptr4) += 100;
        //ptr4 = &counter1;
    }
}
