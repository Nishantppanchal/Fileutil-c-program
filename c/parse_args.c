#include "../h/parse_args.h"
#include "../h/open_file.h"
#include "../h/is_all_int.h"
#include "../h/print.h"
#include <stdlib.h>
#include <unistd.h>

// Function to parse all the arguments passed to the program
void parse_args(int argc, char *argv[], int *infile, int *out_dest, int *max_num_words)
{
    // Declares and initialises variables
    int n_passed = 0;
    int a_passed = 0;
    int sourcefile_passed = 0;


    // Sets the default value for max_num_words and out_dest
    *max_num_words = 10;
    *out_dest = 1;

    // * Note: We start at index 1 rather than 0 because the argv[0] is the program name

    /* Check if the first argument is a sourcefile argument
    This is done by checking if the first character in the first argument is '-'.
    When the sourcefile argument is passed, it will not start '-' while all other
    arguments. Hence, we can determine if the sourcefile argument is passed if the
    first argument doesn't start with '-'. */
    if (argc > 1 && argv[1][0] != '-')
    {
        // Open file passed through the sourcefile argument
        *infile = open_file(argv[1], 'R');
        // Set the sourcefile_passed flag to 1
        sourcefile_passed = 1;
    }
    else
    {
        // Open the default infile: simple.txt
        char *default_infile = "simple.txt";
        *infile = open_file(default_infile, 'R');
    }

    /* Parse the other of the arguments.
    Set i to 2 if the sourcefile argument is passed, otherwise set i to 1.
    For all the arguments passed loop the code. Increase the i by 2 since all 
    the argument have a required statement following them. */
    for (int i = 1 + sourcefile_passed; i < argc; i += 2)
    {
        /* Check if the argument start with '-', which all arguments should,
        except for the sourcefile argument, however we have already parsed that
        above. */
        if (argv[i][0] == '-')
        {
            // Switch for the letter after - in the argument
            switch (argv[i][1])
            {
                // If the argument is -a
                case 'a':
                    // If a has been passed twice, print an error message and exit
                    if (a_passed)
                    {
                        print("Error, duplicate argument: -a", 2, 1, 1); // Print and exit
                    }
                    // If a path is not provided after -a argument, print an error message and exit
                    else if (i + 1 >= argc || argv[i + 1][0] == '-')
                    {
                        print("Invalid argument, no path specified after the -a argument", 2, 1, 1); // Print and exit
                    }
                    // Otherwise, it the argument is valid, open the file
                    else
                    {
                        // Set the out file to the path provided after -a in append mode
                        *out_dest = open_file(argv[i + 1], 'A');
                        // Set the a_passed flag to 1
                        a_passed = 1;
                    }
                    break;
                // If the argument is -n
                case 'n':
                    // If n has been passed twice, print an error message and exit
                    if (n_passed)
                    {
                        print("Error, duplicate argument: -n", 2, 1, 1); // Print and exit
                    }
                    // If a number is not provided after -n, print an error message and exit
                    else if (i + 1 >= argc || argv[i + 1][0] == '-')
                    {
                        print("Invalid argument, no line numbers specified after the -n argument!", 2, 1, 1); // Print and exit
                    }
                    // If the number passed after -n argument is not all digits, print an error message and exit 
                    else if (!is_all_int(argv[i + 1]))
                    {
                        print("Invalid number for -n argument\nPlease refer to documentation to how to use the -n argument", 2, 1, 1); // Print and exit
                    }
                    // Otherwise, it the argument is valid, set the max_num_words to the number passed after -n
                    else
                    {
                        // Set the max_num_words to the number passed after -n
                        *max_num_words = atoi(argv[i + 1]);
                        // Set the n_passed flag to 1
                        n_passed = 1;
                    }
                    break;
                // If the argument passed is not a valid argument, print an error message and exit
                default:
                    print("Invalid argument: ", 2, 0, 0);
                    print(argv[i], 2, 1, 1); // Print and exit
            }
        }
        /* If the argument passed doesn't start with '-' meaning it is invalid, unless
        in specific cases which we already deal with above, print an error message and exit */
        else
        {
            print("Invalid argument: ", 2, 0, 0);
            print(argv[i], 2, 1, 1); // Print and exit
        }
    }
}