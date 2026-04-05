#include <stdio.h>

#define MAX_SIZE 10

int main() {

    int flag;
    int n;
    int row = 0;
    
    do {
        printf("Enter matrix size n (7-10): ");
        scanf("%d", &n);
    } while (n < 7 || n > MAX_SIZE);

    printf("Enter elements of the first row:\n");
    int matrix[MAX_SIZE][MAX_SIZE];
       for (int j = 0; j < n; j++) {
        printf("A[0][%d]: ", j);
        scanf("%d", &matrix[0][j]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    do{
         flag = 0;

        for (int i = 0; i < n-2; i += 2){
            if (matrix[row][i] > matrix[row][i + 2]){
                int temp = matrix[row][i];
                matrix[row][i] = matrix[row][i + 2];
                matrix[row][i + 2] = temp;
                flag = 1;
            }
        }

    }while (flag != 0);

    printf("Sorted first row (even positions sorted):\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", matrix[0][j]);
    }
    printf("\n");

    return 0;
}