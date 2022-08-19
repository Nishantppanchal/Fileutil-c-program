#include "../h/fileutil.h"
#include "../h/parse_args.h"
#include "../h/is_delimiter_check.h"
#include "../h/print.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    // Declare variables
    int infile, out_dest, max_num_words, i, num_words, file_len;
    char buffer[1024];
    Is_delimiter is_delimiter;
    char current_char, next_char;

    parse_args(argc, argv, &infile, &out_dest, &max_num_words);

    file_len = lseek(infile, 0, SEEK_END);
    lseek(infile, 0, SEEK_SET);

    read(infile, &buffer, sizeof(char) * 1024);

    next_char = 'c'; // next_char is set to 'c' to ensure next_char != '\0' doesn't trigger initially
    // Determines whether the first character is a delimiter and sets is_delimiter.current_char to that
    is_delimiter.current_char = is_delimiter_check(buffer[0]);
    num_words = 0; // Sets the inital number of words to 0
    for (i = 0; num_words < max_num_words && i < file_len; i++)
    {
        current_char = buffer[i];
        next_char = buffer[i + 1];

        write(out_dest, &current_char, sizeof(char));

        is_delimiter.next_char = is_delimiter_check(next_char);

        if (!is_delimiter.current_char && is_delimiter.next_char)
        {
            num_words++;
        }

        is_delimiter.current_char = is_delimiter.next_char;
    }

    close(infile);
    if (out_dest != 1)
    {
        print("Append successful", 0, 1);
        close(out_dest);
    }
    else
    {
        print("", 0, 1);
    }

    return 0;
}