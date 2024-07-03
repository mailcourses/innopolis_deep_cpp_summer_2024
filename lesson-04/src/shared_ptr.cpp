#include <iostream>
#include <vector>
#include <memory>

struct A
{
    //A() {}
    A(int num) : num_(num) {}

    int num_ = 0;
};

struct B : A
{
    B() : A(100500)
    {
    }
};

template<class T>
class shared_ptr
{
private:
    struct info_
    {
        T* data = nullptr;
        size_t counter = 0;
    };
public:
    shared_ptr(T* ptr) : ptr_(new info_)
    {
        ptr_->data = ptr;
        ptr_->counter = 1;
    }

    shared_ptr(const shared_ptr& rhs)
    {
        ptr_ = rhs.ptr_;
        ptr_->counter += 1;
        std::cout << "copy counter = " << ptr_->counter << std::endl;
    }

    shared_ptr(shared_ptr&& rhs)
    {
        ptr_ = rhs.ptr_;
        rhs.ptr_ = nullptr;
        std::cout << "move counter = " << ptr_->counter << std::endl;
    }

    ~shared_ptr()
    {
        destroy();
    }

    shared_ptr& operator=(const shared_ptr& rhs)
    {
        if (this == &rhs) {
            return *this;
        }

        destroy();

        ptr_ = rhs.ptr_;
        ptr_->counter += 1;

        return *this;
    }

    shared_ptr& operator=(shared_ptr&& rhs)
    {
        if (this == &rhs) {
            return *this;
        }

        destroy();
        ptr_ = rhs.ptr_;

        rhs.ptr_ = nullptr;
        return *this;
    }

    T* get() const { return ptr_->data; }
private:
    void destroy()
    {
        if (!ptr_) return;
        ptr_->counter -= 1;
        std::cout << "destroy = " << ptr_->counter  << std::endl;
        if (ptr_->counter == 0) {
            delete ptr_->data;
            delete ptr_;
        }
    }


private:
    info_* ptr_ = nullptr;
};

void foo(const std::unique_ptr<std::string>& uptr)
{
    std::cout << "lvalue foo" << std::endl;
}

void foo(std::unique_ptr<std::string>&& uptr)
{
    std::cout << "rvalue foo" << std::endl;
}

int main()
{
    shared_ptr<int> sp1(new int(1));

    shared_ptr<int> sp2(new int(10));
    std::vector<shared_ptr<int>> arr;
    {
        shared_ptr<int> sp3(new int(100500));
        //...
        arr.push_back(std::move(sp3));
    }
    std::cout << "After unknown namespace" << std::endl;
    shared_ptr<int> sp4(std::move(sp2));

    std::unique_ptr<std::string> uptr(new std::string{"Hello"});
    //...
    foo(std::move(uptr));
    foo(uptr);
}


