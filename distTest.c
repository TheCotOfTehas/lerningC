#include <stdio.h>
#include <math.h>

float dist(int,int,int,int);

int main()
{
    int y = 123;
    int *p = &y;
    int ** pp = &p;
    printf("y = %d\n", y);
    printf("p =%d\n", p);
    printf("pp =%d\n", pp);
    printf("&p =%d\n", &p);
    printf("&pp =%d\n", &pp);
    printf("*p =%d\n", *p);
    printf("*pp =%d\n", *pp);
    printf("**pp =%d\n", **pp);
    return 0;
}

float dist(int x1, int y1, int x2, int y2)
{
    double a = x1 - x2;
    double b = y1 - y2;
    float c = sqrt(a*a + b*b);

    return c;
}