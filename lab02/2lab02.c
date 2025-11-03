#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter an integer n: ");
    scanf("%d", &n);
    double S = 0;
    double P = 1.0;
    int func = 0;
    for (int i = 1; i <= n; i++)
    {
        P = P * (i + 2) / 10;
        S = S + P / (i << i);
        func += 6;
    }

    printf("S = %.7f\n", S);
    printf("Number of operations: %d\n", func);
    return 0;
}
А