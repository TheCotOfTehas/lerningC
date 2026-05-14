#include <stdio.h>

void print_bin(unsigned char x, char end);

int main()
{
    unsigned char x;
    scanf("%hhu", &x);      // hh используеся для указания, что работа с char

    print_bin(x, '\n');     // напечатать х и в конце напечатать \n

    return 0;
}

void print_bin(unsigned char x, char end)
{
    for(int i = 8; i >=0; i--)
    {
        int current = x>>i;
        if(current & 1)
          printf("1");
        else
            printf("0");

    }
    printf("%c", end);
}
