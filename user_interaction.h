#ifndef USER_INTERACTION
#define USER_INTERACTION

#include "list.h"

void draw_menu_options();
void create_task(list *the_list);
void view_tasks(list *the_list);
void task_detail(list *the_list);
void update_task(list *the_list);
void delete_task(list *the_list);

#endif //USER_INTERACTION
