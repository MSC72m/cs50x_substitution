#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// getting the Key as CLI argument
int main(int argc, string argv[])
{ // check to ensure that it only has one key as argument with out sapces
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // determine the length of argv
    int length = strlen(argv[1]);
    // force the length to be 26 letters long
    if (length != 26)
    {
        printf("Key must be 26 letters long\n");
        return 1;
    }
    // force to not have repeated characters
    bool repeated_letter = false;
    for (int i = 0; i < length; i++)
    { // force to have all alphabetic characters
        if (!isalpha(argv[1][i]))
        {
            printf("Key must be alphabetic\n");
            return 1;
        }

        for (int j = i + 1; j < length; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                repeated_letter = true;
                break;
            }
        }

        if (repeated_letter)
        {
            printf("Error: repeated letters\n");
            return 1;
        }
    }
    // get user input && determine it's length
    string user_input = get_string("plain text: ");
    int input_length = strlen(user_input);
    // defalut output
    printf("ciphertext: ");
    for (int i = 0; i < input_length; i++)
    {   // check if its uppercase then change the letter to the corresponding cipher letter
        if (isupper(user_input[i]))
        {
            int upper_index = user_input[i] - 'A';
            printf("%c", toupper(argv[1][upper_index]));
        }   // check if its lowercase then change the letter to the corresponding cipher lette
        else if (islower(user_input[i]))
        {
            int lower_index = user_input[i] - 'a';
            printf("%c", tolower(argv[1][lower_index]));
        }
        else
        {   // if its not a letter pass it as is
            printf("%c", user_input[i]);
        }
    }

    printf("\n");
    // return 0 if nothing went wrong
    return 0;
}
