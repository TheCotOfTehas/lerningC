# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

unsigned long long count_digits(unsigned long long digit);

int main()
{
    unsigned long long int digit; //для числа из консоли
    unsigned long long int count = 0; //Колличество цифр
    //int iterator = 1; //эмулятор итератора
    unsigned long long int multiplier =9; // множитель
    scanf("%llu",&digit); //читаю из консоли
    unsigned long long int digitsIN = count_digits(digit); //количество цифр в числе
    //printf("промежуточные digitsIN == %d count = %d multiplier = %d\n", digitsIN, count, multiplier);
    unsigned long long int longZerro = 0;
    
    if(digitsIN == 1)
    {
        printf("0 %llu\n", digit);
        return 0;
    }
    
    for(unsigned long long int iterator = 1; iterator <= digitsIN; iterator++)
    {
        //printf("%d\n", iterator);
        if(digitsIN == iterator)
        {
            count += (digit - longZerro + 1) * iterator;
            printf("%llu %llu\n", iterator - 1, count);
            return 0;
        }
        
        if(longZerro == 0)
            longZerro = 10;
        else 
            longZerro *=10;
        
        count += multiplier * iterator;
        multiplier *= 10;
    }
    
    return 0;
}

unsigned long long count_digits(unsigned long long digit) 
{
    unsigned long long count = 0;
    //printf("digit %d", digit);
    if (digit == 0)
    {
        //printf(" count 1\n");
        return 1;
    }
    
    while (digit > 0) 
    {
        digit /= 10;
        count++;
    }
    //printf(" count %d\n", count);
    return count;
}


