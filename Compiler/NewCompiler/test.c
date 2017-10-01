int fib(int n) {
    int a;
    int b;
    int tmp;
    int i;
    if (n < 2)
        return n;
    a = 0;
    b = 1;
    tmp = 0;
    i = 2;
    while (i <= n)
    {
        tmp = a + b;
        a = b;
        b = tmp;
        i = i + 1;
    }
    return tmp;
}

void main(void)
{
    int n;
    int v;
    n = 5;
    v = fib(n);
}
