#include "../h/is_delimiter_check.h"

int is_delimiter_check(char current_char)
{
    char delimiters[3] = {' ', '\n', '\t'};
    int lenDelimiters = 3;

    for (int i = 0; i < lenDelimiters; i++)
    {
        if (current_char == delimiters[i])
        {
            return 1;
        }
    }

    return 0;
}