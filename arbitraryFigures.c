#include <stdio.h>
#include <stdbool.h>

void ReadPlan(int size, char matrix[size][size]);
void PrintPlan(int size, char matrix[size][size]);
void FillFigures(int x,  int y, int size,char matrix[size][size]);
int GetCountFigures(int size, char matrix[size][size]);

typedef struct 
{
    int x;
    int y;
} PointF;



int main()
{
    int size = 0;
    int countFigures = 0 ;
    scanf("%d", &size);
    char matrix[size][size];
    ReadPlan(size, matrix);
    countFigures = GetCountFigures(size, matrix);
    printf("%d\n", countFigures);
}

int GetCountFigures(int size, char matrix[size][size])
{
    int count = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] == '*')
            {
                count++;
                FillFigures(j, i, size, matrix);
            }

    return count;
}

void FillFigures(int x,  int y, int size,char matrix[size][size])
{
    PointF stakc[1000];
    PointF temp;
    int currentLastElement = -1;
    temp.x = x;
    temp.y = y;
    stakc[++currentLastElement] = temp;

    matrix[y][x] = '.';
    while (currentLastElement >= 0)
    {
        PointF current = stakc[currentLastElement--];

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            if (newX >= 0 && newX < size && newY >= 0 && newY < size) 
            {
                if (matrix[newY][newX] == '*') 
                {
                    matrix[newY][newX] = '.';
                    stakc[++currentLastElement] = (PointF){newX, newY};
                }
            }
        }
        
    }
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