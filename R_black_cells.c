#include <stdio.h>

int main()
{
    int N;
    int result = 0;
    scanf("%d", &N);
    char line;

    for(int i =0;i < 10;i++)
        while( scanf("%c", &line) == 1)
            if(line == '*')
                result++;
    
    printf("%d", result);
}