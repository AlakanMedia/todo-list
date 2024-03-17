#ifndef LIST_H
#define LIST_H

#include "task.h"

typedef struct Node
{
    Task the_task;
    struct Node *next;
}
Node;

typedef struct List
{
    Node *head;
    Node *tail;
    int num_elements;
}
List;

char is_empty(List *the_list);
char insert_task(List *the_list, unsigned char title[], 
				unsigned char description[], int start_date[],
				int end_date[], int is_done);
Node *select_task(List *the_list, int index);
char remove_task(List *the_list, int index);
void remove_all(List *the_list);

#endif // LIST_H
