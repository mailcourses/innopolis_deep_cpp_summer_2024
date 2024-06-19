module;

#include <vector>

export module math;

int unexport_func()
{
    std::vector<int> arr;
    arr.resize(10);
    return arr.size();
}

export
{
    void foo()
    {
    }

    void boo()
    {
    }

};

// TODO: не импортируется с const
export int gMagicVar = 42;

export int sum(int num1, int num2)
{
    return num1 + num2 + unexport_func();
}

export namespace math
{

    int square(int num)
    {
        return num * num;
    }

} // namespace math
