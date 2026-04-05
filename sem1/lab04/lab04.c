#include <stdio.h>
#include <windows.h>

#define MAX_SIZE 10

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double matrix[MAX_SIZE][MAX_SIZE];
    int n;

    do {
        printf("Введіть розімр матриці n (7-10): ");
        scanf("%d", &n);
    } while (n < 7 || n > MAX_SIZE);


    printf("Введіть елементи побічної діагоналі (інші заповняться нулями автоматично):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1 - i) {
                printf("A[%d][%d]: ", i, j);
                scanf("%lf", &matrix[i][j]);
            } else {
                matrix[i][j] = 0.0;
            }
        }
    }

    int left = 0;
    int right = n - 1;
    int found = 0;

    printf("\nПочинаємо двійковий пошук числа з [0, 5] на побічній діагоналі...\n");

    while (left <= right) {

        int mid = left + (right - left) / 2;

        int row = mid;
        int col = n - 1 - mid;

        double val = matrix[row][col];

        printf("Перевіряємо індекс %d (координати [%d][%d]) зі значенням %.2f\n", mid, row, col, val);

        if (val >= 0 && val <= 5) {
            printf("Знайдено число %.2f на побічній діагоналі за індексом %d (координати [%d][%d])\n", val, mid, row, col);
            found = 1;
            break;
        } 
        if (val > 5) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

         }

        if (!found) {
            printf("Число з [0, 5] не знайдено на побічній діагоналі матриці.\n");
        }
    return 0;
} 