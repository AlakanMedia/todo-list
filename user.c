#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "user.h"
#include "misc.h"

void
draw_menu_options()
{
    printf("Options\n\n");
    printf("1 - Add task\n");
    printf("2 - View task\n");
    printf("3 - Update task\n");
    printf("4 - Delete task\n");
    printf("5 - Exit\n");
}

void
get_text(unsigned char buffer[], int max_length)
{
    int c;
    int i = 0;

    while (i < (max_length - 1) && (c = getchar()) != '\n')
        buffer[i++] = c;
    buffer[i] = '\0';

    if (i == (max_length - 1))
        clean_buffer();
}

void
enter_date(int start_date[], int date[])
{
	int i;

	do
	{
		printf("Enter the task completion date (dd/mm/yyyy): ");
		i = scanf("%d/%d/%d", date, date + 1, date + 2);
		clean_buffer();
	}
	while (!date_correct(date) || compare_date(start_date, date) > 0
		   || i < 3);
}

void
create_task(list *the_list)
{
    unsigned char title[MAX_TITLE];
    unsigned char description[MAX_DESCRIPTION];
	int start_date[3];
	int end_date[3];

    printf("Enter the task's name: ");
	get_text(title, MAX_TITLE);

    printf("Enter the task's description: ");
	get_text(description, MAX_DESCRIPTION);
    
	time_t time_now = time(NULL); // Número de segundos desde 01/01/1970
	struct tm *gm_time = gmtime(&time_now);

	*(start_date) = gm_time->tm_mday;
	*(start_date + 1) = gm_time->tm_mon + 1;
	*(start_date + 2) = gm_time->tm_year + 1900;

	enter_date(start_date, end_date);

    if (insert_task(the_list, title, description, start_date, end_date, 0))
		printf("\nTask successfully created\n");
    else
		printf("\nThere was a problem creating the task\n");
}

void
view_tasks(list *the_list)
{
    if (!is_empty(the_list))
    {
		node *aux = the_list->head;
    	int i = 0;

    	printf("Task list\n\n");

    	while (aux)
    	{
    	    printf("%d. [%c] %s\n", ++i, (aux->the_task.is_done) ? 'x' : ' ', 
				   aux->the_task.title);
    	    aux = aux->next;
    	}

		printf("\n");
    }
    else
		printf("The list is empty\n\n");
}

void
task_detail(list *the_list)
{
	if (!is_empty(the_list))
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
			printf("\nStart date: %02d/%02d/%d", 
					the_node->the_task.start_date[0],
					the_node->the_task.start_date[1],
					the_node->the_task.start_date[2]);
			printf("\nEnd date: %02d/%02d/%d", 
					the_node->the_task.end_date[0],
					the_node->the_task.end_date[1],
					the_node->the_task.end_date[2]);
		    printf("\nIs done? %s\n\n", 
					(the_node->the_task.is_done) ? "Yes" : "No");
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
		printf("3 - Update end date\n");
		printf("4 - Mark as done\n");

		printf("\nSelect an option: ");
		scanf("%d", &index);
		clean_buffer();

		switch (index)
		{
			case 1:
    			printf("Enter the new name: ");
				get_text(node_update->the_task.title, MAX_TITLE);
				break;
			case 2:
    			printf("Enter the new description: ");
				get_text(node_update->the_task.description, MAX_DESCRIPTION);
				break;
			case 3:
				enter_date(node_update->the_task.start_date,
						   node_update->the_task.end_date);
				break;
			case 4:
				node_update->the_task.is_done = !node_update->the_task.is_done;
				break;
		}

		printf("\nTask successfully updated\n");
	}
}

void
delete_task(list *the_list)
{
	if (!is_empty(the_list))
	{
	    int task_remove;
	    printf("Select a task to remove: ");
	    scanf("%d", &task_remove);
		clean_buffer();
	
	    if (remove_task(the_list, task_remove))
			printf("\nTask successfully removed\n");
	    else
			printf("\nThere was a problem removing the task\n");
	}
}
