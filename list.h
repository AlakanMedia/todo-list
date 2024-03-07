#ifndef LIST
#define LIST

#include "task_element.h"

typedef struct node
{
    task the_task;
    struct node *next;
}
node;

typedef struct list
{
    node *head;
    node *tail;
    int num_elements;
}
list;

char is_empty(list *the_list);
char insert_task(list *the_list, unsigned char title[], 
				unsigned char description[], int start_date[],
				int end_date[], int is_done);
node *select_task(list *the_list, int index);
char remove_task(list *the_list, int index);
void remove_all(list *the_list);

#endif // LIST
