#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node {
    Data val;               // данные, которые хранятся в одном элементе
    struct Node * next;     // указатель на следующий элемент списка
} Node ;

typedef struct Node * List;

void test0();
List list_create ();
void list_push (List * plist, Data x);
Data list_pop (List * plist);
Data list_get(List list);
void list_print (List list);
int list_size(List list);
int  list_is_empty(List list);
void list_clear(List * plist);

int main()
{
    test0();
    return 0;
}

List list_create ()
{
    return NULL;
}
void list_push (List * plist, Data x)
{
    if(plist == NULL)
    {
        plist = malloc(sizeof(Node));
        (*plist)->val = x;
        return;
    }
    Node * currentNode = (*plist)->next;
    while (currentNode != NULL)
        currentNode = currentNode->next;

    currentNode = malloc(sizeof(Node));
    currentNode->val = x;
}
Data list_pop (List * plist)
{ 
    Node * currentNode = (*plist);
    if (currentNode->next == NULL)
    {
        Data result = currentNode->val;
        *plist = NULL;
        free(currentNode);
        return result;
    }

    Data result = currentNode->val;
    *plist = (*plist)->next;
    free(currentNode);
    return result;
}
Data list_get(List list)
{
    return (*list).val;
}
void list_print (List list)
{
    if(list != NULL)
    {
        printf("%d ", list->val);
        while ((list = list->next) != NULL)
            printf("%d ", list->val);
    }  
    printf("\n");
}
int list_size(List list)
{
    int size = 0;
    Node * currentNode = list; 
    while (currentNode != NULL)
    {
        size++;
        currentNode = currentNode->next;
    }
    
    return size;
}

int  list_is_empty(List list)
{
    return list == NULL;
}
void list_clear(List * plist)
{
    Node * currentNode = *plist;
    while (currentNode != NULL)
    {
        Node * nextNode = currentNode->next; 
        free(currentNode);
        currentNode = nextNode;  
    }
    
    *plist = NULL;
}

void test0()
{
    List list = list_create();
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0

    list_push(&list, 21);
    list_print(list);                               // 21
    list_push(&list, 17);
    list_print(list);                               // 17 21
    list_push(&list, 3);
    list_print(list);                               // 3 17 21
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 0
    printf("size = %d\n", list_size(list));         // size = 3

    Data x = list_pop(&list);
    printf("pop %d\n", x);                          // pop 3
    list_print(list);                               // 17 21
    printf("size = %d\n", list_size(list));         // size = 2

    list_clear(&list);
    list_print(list);                               // пустая строка
    printf("is_empty = %d\n", list_is_empty(list)); // is_empty = 1
    printf("size = %d\n", list_size(list));         // size = 0
}