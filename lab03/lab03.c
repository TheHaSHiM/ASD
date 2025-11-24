#include <stdio.h>
#include <unistd.h>

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void draw_point(int x, int y) { 
    gotoxy(x, y);
    printf("0");
    fflush(stdout);
    usleep(5000);
}

int main(void) {
    int width = 80;
    int height = 24;
    printf("\033[2J");

    int k, j, i, x, y;

    for (k = 0; k <= width + height - 2; k++) {
        
        int start_row = (k < width) ? 0 : k - width + 1;
        int end_row = (k < height) ? k : height - 1;

        if (start_row > end_row) continue;

        
        int j_start = (k % 2 != 0) ? start_row : end_row;
        int j_end = (k % 2 != 0) ? end_row : start_row;   
        int step = (k % 2 != 0) ? 1 : -1;                 

        for (j = j_start; (step > 0) ? (j <= j_end) : (j >= j_end); j += step) {
            
            i = k - j; 
            x = width - i; 
            y = j + 1;
            
            draw_point(x, y); 
        }
    }

    gotoxy(1, 25);
    return 0;
}  