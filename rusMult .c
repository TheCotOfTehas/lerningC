#include <stdio.h>

int rusMult(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", rusMult(a, b));
    return 0;
}

int rusMult(int a, int b)
{
    if (b ==1)
    {
        printf("%d %d\n", a, b);
        return a;
    }
    
    printf("%d %d\n", a, b);
    a *=2;
    b /=2;
    rusMult(a, b);
}