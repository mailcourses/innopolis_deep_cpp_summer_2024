#! /usr/bin/env python3

import random

from cffi import FFI

def main():
    ffi = FFI()
    lib = ffi.dlopen('./libutils.so')
    ffi.cdef('''
    typedef struct Point {
        int x;
        int y;
    } Point;
    int area(Point* p1, Point* p2);
    int sum(int* arr, int size);
    int fibonacci(int n);
    ''')

    p1 = ffi.new('Point*')
    p2 = ffi.new('Point*')
    p1.x, p1.y = (-5, -5)
    p2.x, p2.y = (10, 10)
    area_res = lib.area(p1, p2)
    print(f"area = {area_res}")
    l = [random.choice(list(range(10))) for _ in range(10)]
    original_sum = sum(l)
    c_arr = ffi.new('int[]', l)
    actual_sum = lib.sum(c_arr, len(l))
    print(f"original sum is {original_sum}, actual sum is {actual_sum}")
    print(l)

    print("============")
    ffbuilder = FFI()
    ffbuilder.cdef('''
    int sum(int* arr, int n);
    ''')

    ffbuilder.set_source('_sample', '''
    #include <stdlib.h>
    int sum(int* arr, int n)
    {
        int res = 0;
        for(size_t i = 0; i < n; ++i)
        {
            res += arr[i];
        }
        return res;
    }
    ''')
    ffbuilder.compile()
    from _sample import lib
    new_sum = lib.sum(c_arr, len(l))
    print(f"New sum = {new_sum}")

if __name__ == "__main__":
    main()
