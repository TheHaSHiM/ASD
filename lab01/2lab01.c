#include <stdio.h>

int main(void)
{
    int x;
    printf("Enter an integer x: ");
    scanf("%d", &x);
    int y;
    int y_defined = 0;

    if (x > 20)
    {
        y = -x + 9;
        y_defined = 1;
    }

    else if ((x > 0 && x <= 10) || (x >= -49 && x < -10))
    {
        y = 10 * x * x * x + 7 * x / 5 + 2;
        y_defined = 1;
    }

    
    switch (y_defined)
    {
    case 1:
        printf("y = %d\n", y);
        break;
    case 0:
        printf("x is out of range\n");
        break;
    }
}