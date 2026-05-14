#include <stdio.h>
 
int GetPowDigit(int,int);
int main()
{
    int n,k,current;
    scanf("%d%d",&n,&k);
    int array[100];
    int t =0;
    for(int inter = 0; inter < 100; inter++)
        array[inter] = 1;
    
    for(int i = 2; i < n ; i++)
    {
        current =  GetPowDigit(i, k);
        if(n % current == 0)
        {
            n = n / current;
            printf("%d %d\n", i ,n);
            array[t] = i;
            t++;
            i = 1;
        }
    }
    
    int resulr =1;
    for(int inter = 0; inter < 100; inter++)
        resulr *= array[inter];
    
    printf("%d\n", resulr);
}
 
int GetPowDigit(int digit, int pow)
{
    int result = digit;
    for(int i = 1; i < pow ; i++)
         result *= digit;
    
    return result;
}
 
/*
    2 64
    2 8
    2 1
    8
*/
