#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "user_interaction.h"
#include "misc_funtions.h"

void exit_key();

int
main()
{
    list *the_list = (list *) malloc(sizeof(list));

    if (the_list == NULL)
		return 1;

    the_list->head = NULL;
    the_list->tail = NULL;
    the_list->num_elements = 0;

    int option = 0;
    int task_remove = 0;

    while (option != 5)
    {
		system("clear");
		draw_menu_options();
		printf("\nChoose an option: ");
		scanf("%d", &option);
		clean_buffer();

		system("clear");

		switch (option)
		{
		    case 1:
				create_task(the_list);
				exit_key();
				break;
		    case 2:
				view_tasks(the_list);
				task_detail(the_list);
				exit_key();
				break;
		    case 3:
				view_tasks(the_list);
				delete_task(the_list);
				exit_key();
				break;
		    case 4:
				view_tasks(the_list);
				update_task(the_list);
				exit_key();
				break;
		}
    }

    remove_all(the_list);
    free(the_list);
    the_list = NULL;

    return 0;
}

void
exit_key()
{
    printf("Press any key to exit... ");
    getchar();
    clean_buffer();
}
