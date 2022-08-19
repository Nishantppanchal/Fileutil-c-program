#include "../h/print.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void print(char *str, int exit_program, int newline)
{
    int len_str = strlen(str);
    write(1, str, sizeof(char) * len_str);

    if (newline)
    {
        char *newline = "\n";
        write(1, newline, sizeof(char));
    }

    if (exit_program)
    {
        exit(1);
    }
}