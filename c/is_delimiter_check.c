#include "../h/is_delimiter_check.h"

// Function that checks if a character is a delimiter
int is_delimiter_check(char current_char)
{
    // Declares and initialises variables 
    char delimiters[3] = {' ', '\n', '\t'}; // Define and array with all the delimiters
    int lenDelimiters = 3; // Define the length of the delimiters array

    // Loops the code in the loop until the end of the delimiters array
    for (int i = 0; i < lenDelimiters; i++)
    {
        // If the current character is the same as the current delimiter, return 1
        if (current_char == delimiters[i])
        {
            return 1;
        }
    }

    // If the code reaches this point, it means the character is not a delimiter
    return 0;
}