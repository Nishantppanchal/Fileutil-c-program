// Includes required files
#include "../h/fileutil.h"
#include "../h/parse_args.h"
#include "../h/is_delimiter_check.h"
#include "../h/print.h"
// Includes required libraries
#include <unistd.h>
#include <fcntl.h>

/* Main function
Logic for fileutil put together */
int main(int argc, char *argv[])
{

    // Declare variables
    int infile, out_dest, max_num_words, i, num_words, file_len;
    char buffer[1024];
    Is_delimiter is_delimiter;
    char current_char, next_char;

    // Parses the inputted arguments using the parse_args function
    parse_args(argc, argv, &infile, &out_dest, &max_num_words);

    /* Gets the length of all the text in the file
    Moves the file offset to the end of file. This will return the resulting offset, which is the
    end of the file since we have specified SEEK_END. */
    file_len = lseek(infile, 0, SEEK_END);

    // Move the file offset back to the beginning of the file
    lseek(infile, 0, SEEK_SET);
    // Read the file into the buffer
    read(infile, &buffer, sizeof(char) * 1024);

    next_char = 'c'; // next_char is set to 'c' to ensure next_char != '\0' doesn't trigger initially
    // Determines whether the first character is a delimiter and sets is_delimiter.current_char to that
    is_delimiter.current_char = is_delimiter_check(buffer[0]);
    num_words = 0; // Sets the inital number of words to 0
    /* Loops the code in the loop until the num_words exceeds the max_num_words or we have reached the
    end of the file. */
    for (i = 0; num_words < max_num_words && i < file_len; i++)
    {
        // Gets the current character from buffer
        current_char = buffer[i];
        // Gets the end character from buffer
        next_char = buffer[i + 1];

        // Writes the current character to the output destination
        write(out_dest, &current_char, sizeof(char));

        // Check is the next character is a delimiter
        is_delimiter.next_char = is_delimiter_check(next_char);

        /* If the current character is not a delimiter and the next character is a delimiter, it would
        mean that current character is the last character a word*/
        if (!is_delimiter.current_char && is_delimiter.next_char)
        {
            num_words++; // Add 1 to num_words
        }

        // Sets the current_char to the next_char in the is_delimiter struct
        is_delimiter.current_char = is_delimiter.next_char;
    }

    close(infile); // Close infile

    // If the out_dest was not standard output
    if (out_dest != 1)
    {
        print("Append successful", 1, 0, 1); // Print "Append successful"
        close(out_dest); // Close out_dest
    }
    // Otherwise, if out_dest was standard output
    else
    {
        print("", 1, 0, 1); // Print new line
    }

    // Exit the main function with 0 meaning not errors
    return 0;
}