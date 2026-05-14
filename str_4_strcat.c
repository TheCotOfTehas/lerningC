#include <stdio.h>
#include <string.h>

char * my_strcat(char *dest, const char *src); //destiation(куда) source(откуда)

int main()
{
    char dest[] ={"Hel", "lo"};
    char *src;

    my_strcat(dest, src);

    for(int i = 0; i < strlen(dest) ;i++)
        printf("%c", dest[i]);


    return 0;
}

char * my_strcat(char *dest, const char *src) //destiation(куда) source(откуда)
{
    return NULL;
}