#! /usr/bin/env python3

import ctypes

def main():
    libc = ctypes.CDLL('./libutils.so')
    libc.sum.argstype = [ctypes.c_int, ctypes.c_int]
    libc.sum.restype = ctypes.c_int
    print(libc.sum(10, 20))

    libc.sum_arr.argstype = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
    libc.sum_arr.restype = ctypes.c_int
    arr = list(range(10))
    print(f"{arr}")
    arr_type = ctypes.c_int * len(arr)
    res = libc.sum_arr(arr_type(*arr), len(arr))
    print(f"sum of array is {res}")

    libc = ctypes.CDLL('/lib64/libc.so.6')
    libc.strstr.argstype = [ctypes.c_char_p, ctypes.c_char_p]
    libc.strstr.restype = ctypes.c_char_p
    res = libc.strstr(b"bambaleilo", b"ale")
    print(res)


if __name__ == "__main__":
    main()
