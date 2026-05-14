#include <stdio.h>
#include <string.h>

int main()
{
    char findeText[] = "bomb";
    char replaseText[] = "watermelon";
    char text[100] ={0};
    while(scanf("%s", text) == 1)
    {
        if(strcmp(text, findeText) == 0)
            printf("%s ", text);
        else
            printf("%s ", replaseText);       
    }
        printf("\n"); 
    return 0;
}