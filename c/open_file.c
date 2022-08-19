#include "../h/open_file.h"
#include "../h/print.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int open_file(char *filename, char mode)
{
    int opened_file;

    switch (mode)
    {
        case 'R':
            opened_file = open(filename, O_RDONLY);
            if (opened_file < 0)
            {
                print("Invalid file: ", 0, 0);
                print(filename, 1, 1);
            }
            break;
        case 'A':
            opened_file = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0664);
            if (opened_file < 0)
            {
                print("Error opening or creating file: ", 0, 0);
                print(filename, 1, 1);
            }
            break;
    }

    return opened_file;
}