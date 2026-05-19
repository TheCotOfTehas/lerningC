#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void HLT();
void ADD(uint8_t *, uint8_t *);
void SUB(uint8_t *, uint8_t *);
void MOV(uint8_t *, uint8_t );
void IR();
void readerCommand(void);
bool stop = false; //влаг для остановки программы
uint8_t ram[4];
uint8_t cpu[5];

int main() 
{
    return 0;
}

void readerCommand(void)
{
    int command;
    scanf("%d",&command);
    switch (command) 
    {
        case 0: HLT(); 
            break;
        case 1: ADD(&ram[0], &ram[1]); 
            break;
        case 2: SUB(&ram[0], &ram[1]); 
            break;
        case 3: MOV(&ram[0], 42);    
            break;
        case 4: IR();                
            break;
    }
}
void HLT()
{
    stop = true;
}

void IR()
{
    for (size_t i = 0; i < 4; i++)
        printf("%d", ram[i]); 

    printf("\n");
}

void ADD(uint8_t * a, uint8_t * b)
{
    *a =  *a + *b;  
}

void SUB(uint8_t * a, uint8_t * b)
{
    *a =  *a - *b;  
}

void MOV(uint8_t * a, uint8_t b)
{
    *a = b;
}