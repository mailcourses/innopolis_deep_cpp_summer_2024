extern "C" {

    int fibonacci(int n)
    {
        if (n < 2)
            return 1;
        return fibonacci(n-2) + fibonacci(n-1);
    }

    int sum(int a, int b)
    {
        return a + b;
    }

    int sum_arr(int* arr, int size)
    {
        int res = 0;
        for (int i = 0; i < size; ++i) {
            res += arr[i];
        }
        return res;
    }
}
