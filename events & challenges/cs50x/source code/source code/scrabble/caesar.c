#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt the plaintext using caesar cipher
string caesar_cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    // check if the program is executed with exactly one command-line argument
    if (argc != 2)
    {
        printf("usage: ./caesar key\n");
        return 1;
    }

    // validate that the key provided is a non-negative integer
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("usage: ./caesar key\n");
            return 1;
        }
    }

    // convert the key from string to integer
    int key = atoi(argv[1]);

    // prompt the user for plaintext
    string plaintext = get_string("plaintext: ");

    // encrypt the plaintext
    string ciphertext = caesar_cipher(plaintext, key);

    // output the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// function to perform the caesar cipher encryption
string caesar_cipher(string plaintext, int key)
{
    // adjust the key to fall within the range of 0-25
    key = key % 26;

    for (int i = 0; i < strlen(plaintext); i++)
    {
        // encrypt uppercase letters
        if (isupper(plaintext[i]))
        {
            plaintext[i] = 'A' + (plaintext[i] - 'A' + key) % 26;
        }
        // encrypt lowercase letters
        else if (islower(plaintext[i]))
        {
            plaintext[i] = 'a' + (plaintext[i] - 'a' + key) % 26;
        }
        // non-alphabetic characters remain unchanged
    }

    return plaintext;
}
