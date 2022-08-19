#include "../h/parse_args.h"
#include "../h/open_file.h"
#include "../h/is_all_int.h"
#include "../h/print.h"
#include <stdlib.h>
#include <unistd.h>

void parse_args(int argc, char *argv[], int *infile, int *out_dest, int *max_num_words)
{
    int n_passed = 0;
    int a_passed = 0;
    int sourcefile_passed = 0;

    // Note: We start at index 1 rather than 0 because the argv[0] is the program name

    *max_num_words = 10;
    *out_dest = 1;

    // Check if the first argument is a sourcefile argument
    // This is done by checking if the first character in the first argument is '-'.
    // When the sourcefile argument is passed, it will not start '-' while all other
    // arguments. Hence, we can determine if the sourcefile argument is passed if the
    // first argument doesn't start with '-'.
    if (argc > 1 && argv[1][0] != '-')
    {
        *infile = open_file(argv[1], 'R');
        sourcefile_passed = 1;
    }
    else
    {
        char *default_infile = "simple.txt";
        *infile = open_file(default_infile, 'R');
    }

    // Parse the other of the arguments
    // Still start at one for cases where sourcefile argument is not passed.
    for (int i = 1 + sourcefile_passed; i < argc; i += 2)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
                case 'a':
                    if (a_passed)
                    {
                        print("Duplicate argument: -a", 1, 1);
                    }
                    else if (i + 1 >= argc || argv[i + 1][0] == '-')
                    {
                        print("Invalid argument, no path specified after the -a argument", 1, 1);
                    }
                    else
                    {
                        *out_dest = open_file(argv[i + 1], 'A');
                        a_passed = 1;
                    }
                    break;
                case 'n':
                    if (n_passed)
                    {
                        print("Duplicate argument: -n", 1, 1);
                    }
                    else if (i + 1 >= argc || argv[i + 1][0] == '-')
                    {
                        print("Invalid argument, no line numbers specified after the -n argument!", 1, 1);
                    }
                    else if (!is_all_int(argv[i + 1]))
                    {
                        print("Invalid number for -n argument\nPlease refer to documentation to how to use the -n argument", 1, 1);
                    }
                    else
                    {
                        *max_num_words = atoi(argv[i + 1]);
                        n_passed = 1;
                    }
                    break;
                default:
                    print("Invalid argument: ", 0, 0);
                    print(argv[i], 1, 1);
            }
        }
        else
        {
            print("Invalid argument: ", 0, 0);
            print(argv[i], 1, 1);
        }
    }
}