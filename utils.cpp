#include <stdio.h>
#include "utils.hpp"

void clear_keyboard_buffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}
