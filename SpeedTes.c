#include <stdio.h>

int main()
{
    //галеон>сикль>кнат
    int g_in_s = 17; //галеонов в сиклей
    int s_in_k = 29; //сиклей в кнатов  
    int g1, s1, k1; 
    int g2, s2, k2;
    int resultG, resultS, resultK;
    
    scanf("%d%d%d", &g1, &s1, &k1);
    scanf("%d%d%d", &g2, &s2, &k2);

    int moneyK1 = g1 *g_in_s * s_in_k + s1 *29 + k1;
    int moneyK2 = g2 *g_in_s * s_in_k + s2 *29 + k2;
    int allMoneyK = moneyK1 + moneyK2;//всего денег в кнатах
    resultK = allMoneyK % s_in_k;
    int remountInG = allMoneyK / s_in_k; //деньги которые можно сделать целыми в сиклях
    resultS = remountInG % g_in_s;
    resultG = remountInG / g_in_s;
    printf("%d %d %d", resultG, resultS, resultK);
}