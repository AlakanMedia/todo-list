#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
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
create_task(list *the_list)
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
    
    if (insert_task(the_list, title, description))
		printf("\nTask successfully created\n");
    else
		printf("\nThere was a problem creating the task\n");
}

void
view_tasks(list *the_list)
{
    printf("Task list\n\n");

    if (the_list->head)
    {
		node *aux = the_list->head;
    	int i = 0;

    	while (aux != NULL)
    	{
    	    printf("%d. Title: %s\n", ++i, aux->the_task.title);
    	    aux = aux->next;
    	}

		printf("\n");
    }
    else
		printf("The list is empty\n");
}

void
task_detail(list *the_list)
{
	if (!is_empty(the_list))
	{
    	printf("Want to see a task in more detail? [Y/n] ");
    	char more_detail = tolower(getchar());
    	clean_buffer();

    	if (more_detail == 'y')
    	{
			int index;

			printf("Choose the task you want to see: ");
			scanf("%d", &index); 
    		clean_buffer();

			node *the_node = select_task(the_list, index);

			if (the_node)
			{
				printf("\nTitle: %s", the_node->the_task.title);
			    printf("\nDescription: %s", the_node->the_task.description);
			    printf("\nIs done? %s\n\n", 
					   (the_node->the_task.is_done) ? "Yes" : "No");
			}
    	}
	}
}

void
update_task(list *the_list)
{
	if (!is_empty(the_list))
	{
		int index;
		printf("Select the task to update: ");
		scanf("%d", &index);
		clean_buffer();

		node *node_update = select_task(the_list, index);

		if (!node_update)
			return;

		printf("\n1 - Update name\n");
		printf("2 - Update description\n");
		printf("3 - Mark as done\n");

		printf("\nSelect an option: ");
		scanf("%d", &index);
		clean_buffer();

    	int c;
    	int i;

		switch (index)
		{
			case 1:
    			i = 0;
    			unsigned char title[MAX_TITLE];

    			printf("Enter the new name: ");

    			while (i < (MAX_TITLE - 1) && (c = getchar()) != '\n')
    			    title[i++] = c;
    			title[i] = '\0';

    			if (i == (MAX_TITLE - 1))
    			    clean_buffer();

				strncpy(node_update->the_task.title, title, MAX_TITLE);

				break;
			case 2:
    			i = 0;
    			unsigned char description[MAX_DESCRIPTION];

    			printf("Enter the new description: ");
    			
    			while (i < (MAX_DESCRIPTION - 1) && (c = getchar()) != '\n')
    			    description[i++] = c;
    			description[i] = '\0';

    			if (i == (MAX_DESCRIPTION - 1))
    			    clean_buffer();

				strncpy(node_update->the_task.description, description,
						MAX_DESCRIPTION);

				break;
			case 3:
				node_update->the_task.is_done = !node_update->the_task.is_done;
				break;
		}

		printf("\nTask successfully updated\n");
	}
}

void
delete_task(list *the_list)
{
    int task_remove = 0;
    printf("Select a task to remove: ");
    scanf("%d", &task_remove);
	clean_buffer();

    if (remove_task(the_list, task_remove))
		printf("\nTask successfully removed\n");
    else
		printf("\nThere was a problem removing the task\n");
}
