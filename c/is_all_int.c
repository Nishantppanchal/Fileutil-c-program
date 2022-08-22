#include "../h/is_all_int.h"
#include <string.h>

// Function that checks if a string is all integers
int is_all_int(char *str)
{
    // Gets the length of the string
    int str_len = strlen(str);

    // Loops the code in the loop until the end of the string
    for (int i = 0; i < str_len; i++)
    {
        // If the current character is not a digit, return 0
        if (str[i] < 48 || str[i] > 57)
        {
            return 0;
        }
    }

    // If the code reaches this point, it means the string is all integers
    return 1;
}