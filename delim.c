#include <stdio.h>

int delim(int a[], int i, int j);
    // Функция делит конфеты детей a[i] и a[j].
    // Отдает школьнику (return) лишние конфеты.

int all_equal(int a[], int n);
    // Проверяет, все ли числа в массиве a одинаковые.
    // Возвращает 1 (все одинаковые) или 0 (не все)
    // вы писали раньше такую задачу

int make_all_happy(int a[], int n);
    // Дети делят конфеты, "лишние" конфеты возвращают

int main()
{
    int a[100] = {0};     // ребенок i имеет a[i] конфет
    int n;          // всего детей

    scanf("%d", &n);                        // читаем входные данные
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    
    int schoolboy = 0;
    while(!all_equal(a, n))
    {

        schoolboy += make_all_happy(a, n);   // делим


        schoolboy += delim(a, n - 1, 0);   // делим
        /*for (int it = 0; it < n; it++)
            printf("%d  ", a[it]);
        printf("\n");*/
    }
    
    printf("%d %d\n", schoolboy, a[0]);     // печатаем ответ
    return 0;
}

int make_all_happy(int a[], int n)
{
    int cashback  = 0;
    for(int i = 0;i < n - 1; i++)
        cashback += delim(a, i, i+1);

    return cashback;
}

int all_equal(int a[], int n)
{
    for(int i = 0;i < n - 1; i++)
        if(a[i] != a[i + 1])
            return 0;
    
    return 1;
}

int delim(int a[], int i, int j)
{
    int sum =  a[i] + a[j];
    int result = sum%2;
    int salary = sum / 2;
    a[i] = salary;
    a[j] = salary;
    return result;    
}