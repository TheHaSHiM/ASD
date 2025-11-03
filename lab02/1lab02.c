#include <stdio.h>

int main(void)
{
    double S = 0;
    int n;
    int func = 0;
    printf("Enter an integer n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        double P = 1.0;
        for (int j = 1; j <= i; j++)
        {
            P = P * (j + 2) / 10;
            func += 3;
        }

        S = S + P / (i << i);
        func += 3;
    }
    printf("S = %.7f\n", S);
    printf("Number of operations: %d\n", func);
    return 0;
}