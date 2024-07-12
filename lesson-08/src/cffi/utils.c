#include <stdlib.h>

typedef struct Point
{
    int x;
    int y;
} Point;

int area(Point* p1, Point* p2)
{
    return abs((p1->x - p2->x)*(p1->y - p2->y));
}

int sum(int* arr, int size)
{
    int res = 0;
    for (int i = 0; i < size; ++i) {
        res += arr[i];
    }
    return res;
}

int fibonacci(int n)
{
    if (n < 2)
        return 1;
    return fibonacci(n-2) + fibonacci(n-1);
}
