#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
typedef struct Node
{
    struct Node * next; 
    char temp;
} Node;
 
typedef struct Stac
{
    Node * head; 
    Node * tail; 
} Stac;
 
int Push(Stac *stac, char c);
char Pop(Stac *stac);
int ReedStaples(char arrayStap[1000]);
void AddStaples(char staplesOpen[256], char staplesClose[256]);
int search(char arr[256], char);

int main()
{
    char staplesOpen[256] = {0};
    char staplesClose[256] = {0}; 
    AddStaples(staplesOpen, staplesClose);
    Stac stack = { NULL, NULL };
    char arrayStap[1000];
    for (size_t i = 0; i < 1000; i++)
        arrayStap[i] = 0;
    
    int count = ReedStaples(arrayStap); //считываю скобки из консоли
    bool result = true;

    for (int i = 0; i < count; i++)
    {
        if(arrayStap[i] == 0 || arrayStap[i] == '\n'|| arrayStap[i] == '\0')
            break;

        char currentStap = arrayStap[i];
        if (search(staplesClose, currentStap) != -1)
        {
            Push(&stack, currentStap);
        }
        else if (search(staplesOpen, currentStap) != -1)
        {
            if (stack.head == NULL && stack.tail == NULL)
            {
                result = false;
                break;
            }
            char expectedOpen = staplesClose[(int)currentStap];
            if (stack.tail->temp != expectedOpen)
            {
                result = false;
                break;
            }
    
            Pop(&stack);                
        }    
    }
    

    result = (stack.tail == NULL && stack.head == NULL && result) ? true : false;  
    result ? printf("YES") : printf("NO");
    
    return 0;
}

int search(char arr[256], char key) 
{
    for (int i = 0; i < 256; i++) 
        if (arr[i] == key)
            return i;
            
    return -1;
}

 
void AddStaples(char staplesOpen[256], char staplesClose[256])
{
    staplesOpen['('] = ')';
    staplesOpen['['] = ']';
    staplesOpen['{'] = '}';

    staplesClose[')'] = '(';
    staplesClose[']'] = '[';
    staplesClose['}'] = '{';
}
 
int ReedStaples(char arrayStap[1000])
{
    int count = 0;
    while(1 == scanf("%c", &arrayStap[count])) //считываю скобки из консоли
        count++; 
    
    return count;
}
 
int Push(struct Stac *stac, char c)
{
    Node *newNode = malloc(sizeof(Node));//тут мне нужно чтобы переменная жила
    if (!newNode) return -1;

    newNode->next = stac->tail;
    newNode->temp = c;
    
    stac->tail = newNode;

    if(stac->head == NULL)
        stac->head = newNode;

    return 0;
}
 
char Pop(Stac *stac)
{
    if (stac->tail == NULL) return 0;
    
    char c = stac->tail->temp;
    Node *toRemove = stac->tail;
    stac->tail = stac->tail->next;
    
    if (stac->tail == NULL)
        stac->head = NULL;
    
    free(toRemove);
    return c;
}