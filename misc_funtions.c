#include <stdio.h>
#include <string.h>
#include "misc_funtions.h"

void
clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char *
read_data_file(list *the_list)
{
	FILE *file = fopen("data.csv", "r");

	if (file == NULL)
		return "Error opening the file...\n";

	unsigned char title[MAX_TITLE];
	unsigned char description[MAX_DESCRIPTION];
	int is_done;
	int read;

	do
	{
		read = fscanf(file, "%30[^,],%90[^,],%d\n",
					  title, description, &is_done);

		if (read != 3 && !feof(file))
			return "File format incorrect...\n";

		if (ferror(file))
			return "Error reading file...\n";

		if (title[0] != '\0')
			insert_task(the_list, title, description, is_done);
	}
	while (!feof(file));

	fclose(file);

	return "Success";
}

void
write_data_file(list *the_list)
{
	FILE *file = fopen("data.csv", "w");

	if (!is_empty(the_list) && file != NULL)
	{
		node *aux = the_list->head;

		while (aux != NULL)
		{
			fprintf(file, "%s,%s,%d\n", 
					aux->the_task.title,
					aux->the_task.description,
					aux->the_task.is_done);

			aux = aux->next;	

			if (ferror(file))
				return;
		}

		fclose(file);
	}
}
