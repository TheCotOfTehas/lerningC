#include <stdio.h>
#include <string.h>

#define SrtLen 100
//i have a bomb.

void GetStrind(char string[10][SrtLen], int * countStr);
void replace(char * src);

int main()
{
    char bomb[] = "bomb";
    //char watermelon = "watermelon";
    char string[10][SrtLen] = {0};
    int countStr = 0;
    GetStrind(string, &countStr);

    for(int i = 0; i < countStr; i++)
        while(strstr(string[i],bomb) != NULL)
            replace(string[i]);

    for (int i = 0; i < countStr; i++)
        printf("%s\n",string[i]);

    return 0;
}

void replace(char * src)
{
    size_t lenbomb = strlen("bomb");        // длина бомбы
    size_t lenwater = strlen("watermelon"); // длина арбуза


    char * p = strstr(src, "bomb");
    if (p == NULL)
        return;
    memmove(p + lenwater, p + lenbomb, strlen(p + lenbomb) + 1);
    memcpy(p, "watermelon", lenwater);
}

void GetStrind(char string[10][SrtLen], int * countStr)
{
    char temp[SrtLen] = {0};
    while (fgets(temp, SrtLen, stdin) != NULL && *countStr < 10)
    {
        int strLenTemp = strlen(temp);
        char *last = temp + strLenTemp -1;
        if (*last == '\n')
            *last = '\0';

        strcpy(string[*countStr], temp);
        (*countStr)++;
    }
}