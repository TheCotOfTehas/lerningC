#include <stdio.h>

float fahr(int cel)
{
    return cel * 9/5 + 32;
}

float celsius(int fahr)
{
    return (fahr -32) * 5.0/9;
}

int main()
{
    int cel;
    float f;
    scanf("%d", &cel);
    f = celsius(cel);
    printf("%.4f\n", f);

    return 0;
}