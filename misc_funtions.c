#include <stdio.h>
#include "misc_funtions.h"

void
clean_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
