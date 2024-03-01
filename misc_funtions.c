#include <stdio.h>
#include <string.h>
#include "misc_funtions.h"

void
clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int
read_data_file()
{
	unsigned char title[120];
	unsigned char description[120];
	int is_done;

	FILE *file = fopen("data.csv", "r");

	if (file == NULL)
		return 0;

	int read = 0;

	do
	{
		read = fscanf(file, "%30[^,],%90[^,],%d\n",
					  title, description, &is_done);

		if (read != 3 && !feof(file))
			return 0;

		printf("len: %d ", strlen(title));
		printf("len: %d\n", strlen(description));
		printf("t: %s\nd: %s\n", title, description);
	}
	while (!feof(file));

	fclose(file);
	return 1;
}
