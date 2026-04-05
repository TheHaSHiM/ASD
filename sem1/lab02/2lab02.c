#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter an integer n: ");
    scanf("%d", &n);
    double S = 0;
    double P = 1.0;
    int func = 0;
    double two_pow_i = 1.0;
    for (int i = 1; i <= n; i++)
    {
        two_pow_i *= 2;
        func += 1;
        P = P * (i + 2) / 10;
        func += 3;
        S = S + P / (i * two_pow_i);
        func += 3;
    }

    printf("S = %.7f\n", S);
    printf("Number of operations: %d\n", func);
    return 0;
}
