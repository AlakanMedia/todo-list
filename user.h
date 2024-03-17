#ifndef USER_H
#define USER_H

#include "list.h"

void draw_menu_options();
void create_task(List *the_list);
void view_tasks(List *the_list);
void task_detail(List *the_list);
void update_task(List *the_list);
void delete_task(List *the_list);

#endif //USER_H
