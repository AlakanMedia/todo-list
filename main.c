#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "user_interaction.h"
#include "misc_funtions.h"

int
main()
{
    list *the_list = (list *) malloc(sizeof(list));

    if (!the_list)
		return 1;

    the_list->head = NULL;
    the_list->tail = NULL;
    the_list->num_elements = 0;

	if (!read_data_file(the_list))
	{
		printf("Error reading the file\n");
		return 1;
	}

    int option = 0;
    int task_remove = 0;

	// Arreglo el cual contiene apuntadores a funciones
	void (*array_funtions[]) (list *) = { create_task, task_detail, 
										  update_task, delete_task };	

    while (option != 5)
    {
		system("clear");
		view_tasks(the_list);
		draw_menu_options();
		printf("\nChoose an option: ");
		scanf("%d", &option);
		clean_buffer();

		if (option >= 1 && option <= 4)
		{
			array_funtions[option - 1](the_list);			
			exit_key();
		}
    }

	write_data_file(the_list);
    remove_all(the_list);
    free(the_list);
    the_list = NULL;

    return 0;
}
