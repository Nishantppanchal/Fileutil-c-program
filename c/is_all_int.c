#include "../h/is_all_int.h"
#include <string.h>

int is_all_int(char *str)
{
    int str_len = strlen(str);

    for (int i = 0; i < str_len; i++)
    {
        if (str[i] < 48 || str[i] > 57)
        {
            return 0;
        }
    }

    return 1;
}