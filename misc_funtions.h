#ifndef MISC
#define MISC

#include "list.h"

void exit_key();
void clean_buffer();
int compare_date(void *date_one, void *date_two);
int date_correct(int date[]);
char *read_data_file(list *the_list);
void write_data_file(list *the_list);

#endif //MISC
