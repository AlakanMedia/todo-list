#include <stdio.h>
#include "user_interaction.h"
#include "misc_funtions.h"

void
draw_menu_options()
{
    printf("Option menu\n\n");
    printf("1 - Add todo\n");
    printf("2 - List todos\n");
    printf("3 - Delete todo\n");
    printf("4 - Update todo\n");
    printf("5 - Exit\n");
}

void
create_todo(list *the_list)
{
    int c;
    int i = 0;
    unsigned char title[MAX_TITLE];
    unsigned char description[MAX_DESCRIPTION];

    printf("Ingrese el título: ");

    while (i < (MAX_TITLE - 1) && (c = getchar()) != '\n')
        title[i++] = c;
    title[i] = '\0';

    if (i == (MAX_TITLE - 1))
        clean_buffer();

    i = 0;

    printf("Ingrese la descripción: ");
    
    while (i < (MAX_DESCRIPTION - 1) && (c = getchar()) != '\n')
        description[i++] = c;
    description[i] = '\0';

    if (i == (MAX_DESCRIPTION - 1))
        clean_buffer();
    
    if (insert_todo(the_list, title, description))
	printf("\nUser successfully created\n");
    else
	printf("\nThere was a problem creating the user\n");
}

void
view_todos(list *the_list)
{
    printf("To do list\n\n");

    if (the_list->head)
    {
	node *aux = the_list->head;
    	int i = 0;

    	while(aux != NULL)
    	{
    	    printf("%d - Title: %s\n", ++i, aux->the_todo.title);
    	    aux = aux->next;
    	}
	printf("\n");
    }
    else
	printf("The list is empty\n");
}
