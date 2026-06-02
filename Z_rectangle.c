#include <stdio.h>
#include <stdbool.h>

void ReadPlan(int size, char matrix[size][size]);
void PrintPlan(int size, char matrix[size][size]);
int GetSquare(int x,  int y, int size,char matrix[size][size]);
void FillRectangel(int x,  int y, int size,char matrix[size][size]);
int GetMaxSquare(int size, char matrix[size][size]);

int main()
{
    int size =0;
    int max = 0;
    scanf("%d", &size);
    char matrix[size][size];
    ReadPlan(size, matrix);
    max = GetMaxSquare(size, matrix[size][size]);
    //PrintPlan(size, matrix);
    printf("%d", max);
}

int GetMaxSquare(int size, char matrix[size][size])
{
    int max = 0;
    int tempMax = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(matrix[i][j] == '*')
            {
                tempMax = GetSquare(i,  j, size, matrix[size][size]);
                FillRectangel(i,  j, size, matrix[size][size]);
                max = max > tempMax ? max : tempMax;
            }

        }    
    }
}
int GetSquare(int x,  int y, int size,char matrix[size][size])
{
    int widht = 0;
    int length = 0;

    for (int i = x; i < size; i++)
    {
        if (matrix[i][y] == '*')
        {
            widht++
        }
        else
        {
            x = i - 1;
            break;
        }   
    }

    for (int j = y; j < size; j++)
    {
        if (matrix[x][j] == '*')
        {
            length++
        }
        else
        {

            break;
        }   
    }

    
    return widht * length;
}

void FillRectangel(int x,  int y, int size,char matrix[size][size])
{
    for (int i = x; i < size; i++)
        if(matrix[i][y] == '*')
            for (int j = y; j < size; j++)
                if(matrix[i][j] == '*')
                    matrix[i][j] = '.';
                else
                    break;
        else
            break;
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