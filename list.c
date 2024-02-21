#include <stdlib.h>
#include <string.h>
#include "list.h"

int
is_empty(list *the_list)
{
    return (the_list->head) ? 0 : 1;
}

int
insert_todo(list *the_list, unsigned char title[],
	    unsigned char description[])
{
    node *new_node = (node *) malloc(sizeof(node));

    if (new_node == NULL)
	return 0;

    strncpy(new_node->the_todo.title, title, 20);
    strncpy(new_node->the_todo.description, description, 80);
    new_node->next = NULL;

    if (is_empty(the_list))
    {
	the_list->head = new_node;
	the_list->tail = new_node;
    }
    else
    {
	the_list->tail->next = new_node;
	the_list->tail = new_node;
    }

    return 1;
}

void
remove_all(list *the_list)
{
    if (!is_empty(the_list))
    {
	node *aux = NULL;

	while ((aux = the_list->head) != NULL)
	{
	    the_list->head = the_list->head->next;
	    aux->next = NULL;
	    free(aux);
	    aux = NULL;
	}
    }
}
