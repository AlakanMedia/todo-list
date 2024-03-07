#ifndef MISC
#define MISC

#include "list.h"

void exit_key();
void clean_buffer();
void write_data_file(list *the_list);
char date_correct(int date[]);
char read_data_file(list *the_list);
int compare_date(void *date_one, void *date_two);

#endif //MISC
