#ifndef TASK_H
#define TASK_H

#define MAX_TITLE 31
#define MAX_DESCRIPTION 91

typedef struct Task
{
    unsigned char title[MAX_TITLE];
    unsigned char description[MAX_DESCRIPTION];
	int start_date[3];
	int end_date[3];
    int is_done;
}
Task;

#endif // TASK_H
