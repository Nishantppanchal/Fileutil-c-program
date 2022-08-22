#include "../h/print.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Function to print a message to out_dest (standard output or error output)
void print(char *str, int out_des, int exit_program, int newline)
{
    // Gets length of the string
    int len_str = strlen(str);
    // Writes the string to the out_dest
    write(out_des, str, sizeof(char) * len_str);

    // If newline is 1, print a newline
    if (newline)
    {
        char *newline = "\n"; // Set newline to the newline character
        write(out_des, newline, sizeof(char)); // Write the newline to the out_dest
    }

    // If exit_program is 1, exit the program
    if (exit_program)
    {
        exit(1); // Exit the program returning 1
    }
}