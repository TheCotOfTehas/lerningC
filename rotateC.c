#include <stdio.h>
#include <math.h>

void rotateC(int *x1, int *y1, int *x2, int *y2);

int main()
{
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("x1 : %d y1 : %d x2 : %d y2: %d\n", x1, y1, x2, y2);
    x1 += 1000;
    y1 += 1000;
    x2 += 1000;
    y2 += 1000;

    rotateC(&x1, &y1, &x2, &y2);
    
    printf("x1 : %d y1 : %d x2 : %d y2: %d\n", x1 - 1000, y1 - 1000, x2 - 1000, y2 - 1000);
    return 0;
}

void rotateC(int *x1, int *y1, int *x2, int *y2)
{
    int tempX = *x1;
    int tempY = *y1;
    *x1 = *y2;
    *y1 = *x2;
    *x2 = tempY;
    *y2 = tempX;
}