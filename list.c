#include <stdlib.h>
#include <string.h>
#include "list.h"

int
is_empty(list *the_list)
{
    return (the_list->head) ? 0 : 1;
}

int
insert_task(list *the_list, unsigned char title[],
	    unsigned char description[])
{
    node *new_node = (node *) malloc(sizeof(node));

    if (new_node == NULL)
		return 0;

    strncpy(new_node->the_task.title, title, MAX_TITLE);
    strncpy(new_node->the_task.description, description, MAX_DESCRIPTION);
    new_node->the_task.is_done = 0;
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

    the_list->num_elements++;

    return 1;
}

node *
select_task(list *the_list, int index)
{
    node *aux = NULL;

    if (!is_empty(the_list) && index > 0 && index <= the_list->num_elements)
    {
		aux = the_list->head;

		for (int i = 1; i < index; i++)
		    aux = aux->next;
    }

    return aux;
}

int
remove_task(list *the_list, int index)
{
    if (!is_empty(the_list) && index > 0 && index <= the_list->num_elements)
    {
		node *aux = the_list->head;

		for (int i = 1; i < (index - 1); i++)
		    aux = aux->next;
		    
		if (index == 1 && the_list->num_elements == 1)
		{
		    the_list->head = NULL;
		    the_list->tail = NULL;
		}
		else if (index == 1 && the_list->num_elements > 1)
		{
		    the_list->head = the_list->head->next;    
		    aux->next = NULL;
		}
		else if (index > 1 && index == the_list->num_elements)
		{
		    the_list->tail = aux;
		    aux = aux->next;
		    the_list->tail->next = NULL;
		}
		else
		{
		    node *to_delete = aux->next;
		    aux->next = to_delete->next;
		    to_delete->next = NULL;
		    aux = to_delete;
		    to_delete = NULL;
		}

		the_list->num_elements--;
		free(aux);
		aux = NULL;

		return 1;
    }

    return 0;
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
		    the_list->num_elements--;
		}
    }
}
