#include <iostream>

class MyString
{
public:
    MyString(size_t n) : size_(n)
    {
        data_ = new char[n];
        for (size_t i = 0; i < n; ++i) {
            data_[i] = i + 'a';
        }
    }
    ~MyString()
    {
        delete[] data_;
    }

    MyString(const MyString& rhs) = default;

    MyString& operator=(const MyString& rhs)
    {
        if (this == &rhs) {
            return *this;
        }

        delete[] data_;

        size_ = rhs.size_;
        data_ = new char[size_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = rhs.data_[i];
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream&, const MyString&);

    char* get() const { return data_; }

private:
    char* data_ = nullptr;
    size_t size_;
};

std::ostream& operator<<(std::ostream& out, const MyString& rhs)
{
    for (size_t i = 0; i < rhs.size_; ++i) {
        out << rhs.data_[i];
    }
    return out;
}

int main()
{
    MyString str1(10);
    MyString str2(2);
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    std::cout << "Copy" << std::endl;
    str2 = str1;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    MyString& str3 = str1;
    //...
    str3 = str1; // str1 = str1;

    MyString str4(str3);
}
