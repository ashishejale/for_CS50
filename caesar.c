#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

string cipher(string plain, int key);

int main(int argc, string argv[])
{
    //To check if arguments are 2 and numeric
    bool numeric;
    if (argc == 2)
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            numeric = isdigit(argv[1][i]);
            if (numeric == 0)
            {
                printf("Usage: ./ceasar key\n");
                return 1;
            }
        }
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        string ciphertext = cipher(plaintext, key);
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }

    if (argc != 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
}

string cipher(string plain, int key)
{
    string cipher = plain;
    int k = key;
    for (int i = 0; plain[i] != '\0'; i++)
    {
        if (isupper(plain[i]))
        {
            cipher[i] = ((plain[i] - 'A' + k) % 26) + 'A';
        }
        else if (islower(plain[i]))
        {
            cipher[i] = ((plain[i] - 'a' + k) % 26) + 'a';
        }
        else
        {
            cipher[i] = plain[i];
        }
    }
    return cipher;
}
