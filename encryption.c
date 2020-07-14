#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// declaring global variables
bool validation(string key);
int crypt(string key);
bool status;
int length_of_key;
// main function takes 2 arguments, which are the name of the file and the encryption key
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
// if the number of arguments = 2, get the key from the argument and check if has 26 characters
    else if (argc == 2)
    {
        string key = argv[1];
        length_of_key = strlen(key);
        if (length_of_key == 26)
        {
            validation(key);
// if validation is successful, starting the ecnryption
            if (status == true)
            {
                crypt(key);
            }
        }
        else
        {
            return 1;
        }
    }
}
// the function checks for key correctness, avoiding numbers and special characters
bool validation(string key)
{
    for (int i = 0; i < length_of_key; i++)
    {
        if (isalpha(key[i]))
        {
// checking for duplicates in the key
            for (int letter = i + 1; letter < length_of_key; letter++)
            {
                if (key[i] == key[letter])
                {
                    exit(1);
                }
            }
        }
        else
        {
            exit(1);
        }
    }
    status = true;
    return status;
}
// core function that takes the key and encrypt the message according to input
int crypt(string key)
{
// getting the input if the key was valid
    string user_input = get_string("Message to encrypt: ");
    int length_of_message = strlen(user_input);
// declaring the encrypted key
    char encrypted[length_of_message];
// avoiding memory allocation error
    encrypted[length_of_message] = '\0';
// assigning the values from input to the array
    for (int g = 0; g < length_of_message; g++)
    {
        encrypted[g] = user_input[g];
    }
// defining the postition of the characters in alhabetic order
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int c = 0; c < length_of_message; c++)
    {
// the case then the input is lower case
        if (islower(user_input[c]) && isalpha(user_input[c]))
        {
            for (int l = 0; l < strlen(alphabet); l++)
            {
                if (alphabet[l] == (user_input[c]))
                {
                    if (islower(key[l]))
                    {
                        encrypted[c] = key[l];
                        break;
                    }
                    else
                    {
                        encrypted[c] = tolower(key[l]);
                        break;
                    }
                }

            }
        }
// the case then the input is upper case
        else if (isupper(user_input[c]) && isalpha(user_input[c]))
        {
            for (int l = 0; l < strlen(alphabet); l++)
            {
                if (toupper(alphabet[l]) == user_input[c])
                {
                    if (isupper(key[l]))
                    {
                        encrypted[c] = key[l];
                        break;
                    }
                    else
                    {
                        encrypted[c] = toupper(key[l]);
                        break;
                    }

                }
            }
        }
// if the current symbol is not alphabetic
        else
        {
            encrypted[c] = user_input[c];
        }
    }

    printf("ciphertext: %s\n", encrypted);
    return 0;
}