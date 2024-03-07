#include <stdio.h>
#include <string.h>
#include "misc_funtions.h"

void
exit_key()
{
    printf("Press any key to exit... ");
  	getchar();
    clean_buffer();
}

void
clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int
compare_date(void *date_one, void *date_two)
{
	if (((int *)date_two)[2] > ((int *)date_one)[2])
	{
		return -1;
	}
	else if (((int *)date_two)[2] < ((int *)date_one)[2])
	{
		return 1;
	}
	else
	{
		if (((int *)date_two)[1] > ((int *)date_one)[1])
			return -1;
		else if (((int *)date_two)[1] < ((int *)date_one)[1])
			return 1;
		else
		{
			if ((int *)date_two > (int *)date_one)
				return -1;
			else if ((int *)date_two < (int *)date_one)
				return 1;
		}
	}

	return 0;
}

int
date_correct(int date[])
{
	if (*(date + 2) >= 0)
	{
		if (*(date + 1) == 1 || *(date + 1) == 3 || *(date + 1) == 5 
			|| *(date + 1) == 7 || *(date + 1) == 8 || *(date + 1) == 10 
			|| *(date + 1) == 12)
		{
			if (*date >= 0 && *date <= 31)
				return 1;
		}
		else if (*(date + 1) == 4 || *(date + 1) == 6 || *(date + 1) == 9 
				 || *(date + 1) == 11)
		{
			if (*date >= 0 && *date <= 30)
				return 1;
		}
		else if(*(date + 1) == 2)
		{
			if ((*(date + 2) % 4 == 0 && *(date + 2) % 100 != 0) 
				|| *(date + 2) % 400 == 0)
			{
				if (*date >= 0 && *date <= 29)
					return 1;
			}
			else
			{
				if (*date >= 0 && *date <= 28)
					return 1;
			}
		}
	}

	return 0;
}

char *
read_data_file(list *the_list)
{
	FILE *file = fopen("data.csv", "r");

	if (file == NULL)
		return "Error opening the file...\n";

	unsigned char title[MAX_TITLE];
	unsigned char description[MAX_DESCRIPTION];
	int start_date[3];
	int end_date[3];
	int is_done;
	int read;

	do
	{
		read = fscanf(file, "%30[^,],%90[^,],%d/%d/%d,%d/%d/%d,%d\n",
					  title, 
					  description, 
					  start_date,
					  start_date + 1,
					  start_date + 2,
					  end_date,
					  end_date + 1,
					  end_date + 2,
					  &is_done);

		if (read != 9 && !feof(file))
			return "File format incorrect...\n";

		if (ferror(file))
			return "Error reading file...\n";

		if (title[0] != '\0')
			insert_task(the_list, title, description, start_date, 
						end_date, is_done);
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
			fprintf(file, "%s,%s,%d/%d/%d,%d/%d/%d,%d\n", 
					aux->the_task.title,
					aux->the_task.description,
					aux->the_task.start_date[0],
					aux->the_task.start_date[1],
					aux->the_task.start_date[2],
					aux->the_task.end_date[0],
					aux->the_task.end_date[1],
					aux->the_task.end_date[2],
					aux->the_task.is_done);

			aux = aux->next;	

			if (ferror(file))
				return;
		}

		fclose(file);
	}
}
