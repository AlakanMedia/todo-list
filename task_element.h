#ifndef TASK_ELEMENT
#define TASK_ELEMENT

#define MAX_TITLE 31
#define MAX_DESCRIPTION 91

typedef struct task
{
    unsigned char title[MAX_TITLE];
    unsigned char description[MAX_DESCRIPTION];
    int is_done;
}
task;

#endif // TASK_ELEMENT
