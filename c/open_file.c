#include "../h/open_file.h"
#include "../h/print.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

// Function that opens a file
int open_file(char *filename, char mode)
{
    // Declares variables
    int opened_file;

    // Switch for the mode, which the open type (read or append).
    switch (mode)
    {
        // If the mode is 'r', open the file for reading
        case 'R':
            // Opens the file for reading
            opened_file = open(filename, O_RDONLY);
            
            // If the file is not opened, print an error message
            if (opened_file < 0)
            {
                print("Invalid file: ", 2, 0, 0);
                print(filename, 2, 1, 1); // Print and exit
            }
            break;
        // If the mode is 'a', open the file for appending
        case 'A':
            // Opens the file for appending
            opened_file = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0664);

            // If the file is not opened, print an error message
            if (opened_file < 0)
            {
                print("Error opening or creating file: ", 2, 0, 0);
                print(filename, 2, 1, 1); // Print and exit
            }
            break;
    }

    // Returns the opened file descriptor
    return opened_file;
}