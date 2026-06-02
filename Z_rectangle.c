#include <stdio.h>
#include <stdbool.h>

void ReadPlan(int size, char matrix[size][size]);
void PrintPlan(int size, char matrix[size][size]);

int main()
{
    int size =0;
    scanf("%d", &size);
    char matrix[size][size];
    ReadPlan(size, matrix);
    PrintPlan(size, matrix);
}

void ReadPlan(int size, char matrix[size][size])
{
    char temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf(" %c", &temp);
            matrix[i][j] = temp;
        }    
    }
}

void PrintPlan(int size, char matrix[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%c", matrix[i][j]);
  
        printf("\n");
    }
}