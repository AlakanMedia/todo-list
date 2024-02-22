#ifndef TODO_ELEMENT
#define TODO_ELEMENT

#define MAX_TITLE 31
#define MAX_DESCRIPTION 91

typedef struct todo
{
    unsigned char title[MAX_TITLE];
    unsigned char description[MAX_DESCRIPTION];
}
todo;

#endif // TODO_ELEMENT
