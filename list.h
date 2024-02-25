#ifndef LIST
#define LIST

#include "todo_element.h"

typedef struct node
{
    todo the_todo;
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

int is_empty(list *the_list);
int insert_todo(list *the_list, unsigned char title[],
		unsigned char description[]);
int remove_todo(list *the_list, int index);
void remove_all(list *the_list);

#endif // LIST
