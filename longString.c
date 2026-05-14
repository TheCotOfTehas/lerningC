#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    long unsigned int longStr = 0;
    char tempStr[256];
    printf("%ld\n", longStr);
    char string[256] = "";
    while(scanf("%s", string) == 1)
    {
        if(strlen(string) > longStr )
            strcpy(tempStr, string);
    }
    printf("%s %ld\n", tempStr, strlen(string));
    return 0;
}
