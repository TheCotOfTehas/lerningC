#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//Основные команды их бы в отдельный файл запихнуть
void HLT();
void ADD(uint8_t *, uint8_t *);
void SUB(uint8_t *, uint8_t *);
void MOV(uint8_t *, uint8_t );
void IR();

//Команды обёртки для масива функций CPU
void wrap_HLT(void);
void wrap_IR(void);
void wrap_ADD(void);
void wrap_SUB(void);
void wrap_MOV(void);

void readerCommand(void);
bool stop = false; //влаг для остановки программы
uint8_t ram[4];
void (*ops[5])(void);

int main() 
{
    ops[0] = wrap_HLT;
    ops[1] = wrap_ADD;
    ops[2] = wrap_SUB;
    ops[3] = wrap_MOV;
    ops[4] = wrap_IR;
    
    while (!stop)
        readerCommand();
    
    return 0;
}



/*void readerCommand(void)
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
}*/

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