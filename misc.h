#ifndef MISC_H
#define MISC_H

#include "list.h"

void exit_key();
void clean_buffer();
void write_data_file(List *the_list);
char read_data_file(List *the_list);
char date_correct(int date[]);
int compare_date(void *date_one, void *date_two);

#endif //MISC_H
