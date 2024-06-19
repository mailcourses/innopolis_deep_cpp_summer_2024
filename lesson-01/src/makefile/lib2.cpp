
int pow(int num, int p)
{
    if (p == 0)
        return 1;
    int res = num;
    while (--p) {
        res *= num;
    }
    return res;
}

int square(int num)
{
    return pow(num, 2);
}
