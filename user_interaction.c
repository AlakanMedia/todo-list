#include <stdio.h>
#include "user_interaction.h"
#include "misc_funtions.h"

void
draw_menu_options()
{
    printf("Option menu\n\n");
    printf("1 - Add task\n");
    printf("2 - List tasks\n");
    printf("3 - Delete task\n");
    printf("4 - Update task\n");
    printf("5 - Exit\n");
}

void
create_todo(list *the_list)
{
    int c;
    int i = 0;
    unsigned char title[MAX_TITLE];
    unsigned char description[MAX_DESCRIPTION];

    printf("Enter the task's name: ");

    while (i < (MAX_TITLE - 1) && (c = getchar()) != '\n')
        title[i++] = c;
    title[i] = '\0';

    if (i == (MAX_TITLE - 1))
        clean_buffer();

    i = 0;

    printf("Enter the task's description: ");
    
    while (i < (MAX_DESCRIPTION - 1) && (c = getchar()) != '\n')
        description[i++] = c;
    description[i] = '\0';

    if (i == (MAX_DESCRIPTION - 1))
        clean_buffer();
    
    if (insert_todo(the_list, title, description))
	printf("\nTask successfully created\n");
    else
	printf("\nThere was a problem creating the task\n");
}

void
view_todos(list *the_list)
{
    printf("Task list\n\n");

    if (the_list->head)
    {
	node *aux = the_list->head;
    	int i = 0;

    	while (aux != NULL)
    	{
    	    printf("%d. Title: %s\n", ++i, aux->the_todo.title);
    	    aux = aux->next;
    	}
	printf("\n");
    }
    else
	printf("The list is empty\n");
}

void
delete_todo(list *the_list)
{
    int task_remove = 0;
    printf("Select a task to remove: ");
    scanf("%d", &task_remove);

    if (remove_todo(the_list, task_remove))
	printf("\nTask successfully removed\n");
    else
	printf("\nThere was a problem removing the task\n");
}
