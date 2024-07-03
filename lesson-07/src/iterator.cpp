#include <iterator>
#include <iostream>
#include <algorithm>
#include <numeric>

template<class T>
class ArrayIterator
{
private:
    T* ptr_;
public:
    ArrayIterator(T* ptr) : ptr_(ptr) { }
    ArrayIterator& operator++()
    {
        ++ptr_;
        return *this;
    }

    ArrayIterator operator++(int)
    {
        ArrayIterator tmp = *this;
        ++ptr_;
        return tmp;
    }

    T& operator*()
    {
        return *ptr_;
    }

    bool operator==(const ArrayIterator& rhs) {
        return ptr_ == rhs.ptr_;
    }

    bool operator!=(const ArrayIterator& rhs) {
        return ptr_ != rhs.ptr_;
    }
};

template<class T, size_t N>
class MyArray
{
private:
    T data[N];
public:
    using iterator = ArrayIterator<T>;

    size_t size() const { return N; }
    iterator begin() { return iterator(data); }
    iterator end() { return iterator(data + N); }
    T& operator[](size_t idx) {
        return data[idx];
    }
};

constexpr size_t ARRAY_SIZE = 5;

int main()
{
    MyArray<int32_t, ARRAY_SIZE> arr;
    std::cout << arr.size() << std::endl;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = i+1;
    }
    auto begin = arr.begin(); // std::begin(arr)
    auto end = arr.end(); // std::begin(end)
    while (begin != end)
    {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
    std::cout << std::accumulate(std::begin(arr), std::end(arr), 0) << std::endl;
}
