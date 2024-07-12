#! /usr/bin/env python3

import time
import ctypes

# external packages
from cffi import FFI

# own packages
import cutils

MAX_N = 34

def capi_fib():
    start_ts = time.time()
    res = cutils.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"capi: {end_ts-start_ts} seconds")
    return res

def ctypes_fib():
    libc = ctypes.CDLL('./ctypes/libutils.so')
    libc.fibonacci.argstype = [ctypes.c_int]
    libc.fibonacci.restype = ctypes.c_int
    start_ts = time.time()
    ctypes_res = libc.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"ctypes: {end_ts-start_ts} seconds")
    return ctypes_res

def cffi_api_fib():
    ffbuilder = FFI()
    ffbuilder.cdef('''
    int fibonacci(int n);
    ''')

    ffbuilder.set_source('_sample', '''
    #include <stdlib.h>
    int fibonacci(int n)
    {
        if (n < 2)
            return 1;
        return fibonacci(n-2) + fibonacci(n-1);
    }
    ''')
    ffbuilder.compile()
    from _sample import lib
    start_ts = time.time()
    res = lib.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"cffi API: {end_ts-start_ts} seconds")
    return res

def cffi_abi_fib():
    ffi = FFI()
    lib = ffi.dlopen('./cffi/libutils.so')
    ffi.cdef('''
    int fibonacci(int n);
    ''')
    start_ts = time.time()
    res = lib.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"cffi ABI: {end_ts-start_ts} seconds")
    return res

def fibonacci(n):
    if n < 2:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

def py_fib():
    start_ts = time.time()
    py_res = fibonacci(MAX_N)
    end_ts = time.time()
    print(f"py: {end_ts-start_ts} seconds")
    return py_res

def main():
    py_res = py_fib()
    ctypes_res = ctypes_fib()
    cffi_api_res = cffi_api_fib()
    cffi_abi_res = cffi_abi_fib()
    capi_res = capi_fib()
    assert(py_res == ctypes_res == cffi_api_res == cffi_abi_res == capi_res)

if __name__ == "__main__":
    main()
