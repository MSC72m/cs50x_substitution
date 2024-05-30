# Substitution Cipher Program

## Project Description
This project is a solution to a CS50x problem set that involves implementing a substitution cipher. The program encrypts a given plaintext using a provided 26-character key where each letter in the plaintext is substituted with the corresponding letter in the key.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm Explanation](#algorithm-explanation)
- [Code Explanation](#code-explanation)

## Installation
No special installation is required for this project. Ensure you have a C compiler like `gcc` installed and the CS50 library available.

## Usage
To compile and run the project, use the following commands:
```sh
make substitution
./substitution key
```
You will be prompted to enter the plaintext, and the program will output the corresponding ciphertext.

## Algorithm Explanation
The substitution cipher algorithm encrypts plaintext by substituting each letter with a corresponding letter from a provided key. The algorithm works as follows:

Validate Key:
Ensure the key has exactly 26 characters.
Ensure all characters in the key are alphabetic.
Ensure there are no repeated characters in the key.
Encrypt Plaintext:
Get the plaintext input from the user.
For each character in the plaintext:
If it is an uppercase letter, substitute it with the corresponding uppercase letter from the key.
If it is a lowercase letter, substitute it with the corresponding lowercase letter from the key.
If it is not a letter, leave it unchanged.
Output Ciphertext:
Print the resulting ciphertext.

## Code Explanation
Including Libraries and Function Prototypes
``` C
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>: Includes the CS50 library for simplified input functions.
#include <ctype.h>: Includes the ctype library for character type functions.
#include <stdio.h>: Includes the standard input/output library.
#include <string.h>: Includes the string library for string handling functions.
Main Function
``` C
int main(int argc, string argv[])
{
    // Check to ensure that it only has one key as argument without spaces
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Determine the length of argv
    int length = strlen(argv[1]);

    // Force the length to be 26 letters long
    if (length != 26)
    {
        printf("Key must be 26 letters long\n");
        return 1;
    }

    // Force to not have repeated characters
    bool repeated_letter = false;
    for (int i = 0; i < length; i++)
    {
        // Force to have all alphabetic characters
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

    // Get user input and determine its length
    string user_input = get_string("plain text: ");
    int input_length = strlen(user_input);

    // Default output
    printf("ciphertext: ");
    for (int i = 0; i < input_length; i++)
    {
        // Check if it's uppercase then change the letter to the corresponding cipher letter
        if (isupper(user_input[i]))
        {
            int upper_index = user_input[i] - 'A';
            printf("%c", toupper(argv[1][upper_index]));
        }
        // Check if it's lowercase then change the letter to the corresponding cipher letter
        else if (islower(user_input[i]))
        {
            int lower_index = user_input[i] - 'a';
            printf("%c", tolower(argv[1][lower_index]));
        }
        else
        {
            // If it's not a letter, pass it as is
            printf("%c", user_input[i]);
        }
    }

    printf("\n");
    // Return 0 if nothing went wrong
    return 0;
}
```
Explanation:
Command-Line Argument Check:

``` C
if (argc != 2)
{
    printf("Usage: ./substitution key\n");
    return 1;
}
Ensures that the user provides exactly one command-line argument (the key).

Key Length Check:

c
Copy code
int length = strlen(argv[1]);
if (length != 26)
{
    printf("Key must be 26 letters long\n");
    return 1;
}
```
Ensures that the key is exactly 26 characters long.

Key Validation:
``` C
bool repeated_letter = false;
for (int i = 0; i < length; i++)
{
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
```
Ensures that the key contains only alphabetic characters and does not have repeated characters.

Getting User Input:

``` C
string user_input = get_string("plain text: ");
int input_length = strlen(user_input);
```
Prompts the user for the plaintext to be encrypted and determines its length.

Encrypting the Plaintext:

``` C
printf("ciphertext: ");
for (int i = 0; i < input_length; i++)
{
    if (isupper(user_input[i]))
    {
        int upper_index = user_input[i] - 'A';
        printf("%c", toupper(argv[1][upper_index]));
    }
    else if (islower(user_input[i]))
    {
        int lower_index = user_input[i] - 'a';
        printf("%c", tolower(argv[1][lower_index]));
    }
    else
    {
        printf("%c", user_input[i]);
    }
}
```
Encrypts each character of the plaintext by substituting it with the corresponding character from the key:

If the character is uppercase, it finds the corresponding uppercase character in the key.
If the character is lowercase, it finds the corresponding lowercase character in the key.
If the character is not alphabetic, it remains unchanged.
