#include<stdio.h>

int main()
{
    int k_rice;
    int r_veg;
    int result;

    scanf("%d", &k_rice);
    scanf("%d", &r_veg);

    result = k_rice + r_veg*2;

    printf("%d", result);
    return 0;
}