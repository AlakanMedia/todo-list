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
}
list;

int is_empty(list *the_list);
int insert_todo(list *the_list, unsigned char title,
		unsigned char description);
void remove_all(list *the_list);

#endif // LIST
