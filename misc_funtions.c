#include <stdio.h>
#include "misc_funtions.h"

void
clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int
read_data_file(list *the_list)
{
	FILE *file = fopen("data.csv", "r");

	if (file == NULL)
		return 0;

	unsigned char title[MAX_TITLE];
	unsigned char description[MAX_DESCRIPTION];
	int is_done;
	int read;

	do
	{
		read = fscanf(file, "%30[^,],%90[^,],%d\n",
					  title, description, &is_done);

		if ((read != 3 && !feof(file)) || ferror(file))
			return 0;

		insert_task(the_list, title, description);
	}
	while (!feof(file));

	fclose(file);
	return 1;
}
