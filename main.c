#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "user_interaction.h"
#include "misc_funtions.h"

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

    while (option != 5)
    {
	system("clear");
	draw_menu_options();
	printf("\nChoose an option: ");
	scanf("%d", &option);
	clean_buffer();

	switch (option)
	{
	    case 1:
		system("clear");
		create_todo(the_list);
		printf("Press any key to exit... ");
		getchar();
		clean_buffer();
		break;
	    case 2:
		system("clear");
		view_todos(the_list);
		printf("Press any key to exit... ");
		getchar();
		clean_buffer();
		break;
	    case 3:
		break;
	    case 4:
		break;
	}
    }

    free(the_list);
    the_list = NULL;

    return 0;
}


