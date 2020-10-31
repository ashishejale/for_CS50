#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string ciphertext(string plain, string key);

int main(int argc, string argv[])
{
//To check if arguments are 2 and numeric
    if (argc == 2)
    {
        string key = (argv[1]);
        if (strlen(key) == 26) //To check key length
        {

            printf("%s\n", key);

            for (int i = 0; (key[i]) != '\0'; i++)
            {
                if (isdigit(key[i])) //To check if key conatains digit
                {
                    printf("Key must only cntain alphabetic characters.\n");
                    return 1;
                }

                if (isalpha(key[i])) //To check if key is alphabetical //To check if alphabet is double in key
                {
                    for (int j = i + 1; key[j] != '\0'; j++)
                    {
                        if (key[i] == key[j])
                        {
                            printf("Key must not contain repeated characters.\n");
                            return 1;
                        }
                    }
                }
            }
            //main code
            string plain = get_string("plaintext:");
            string cipher = ciphertext(plain, key); //calling function to cipher
            printf("ciphertext: %s\n", cipher);
            return 0;
        }
        else //To check length of key
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    if (argc != 2) //To check if arguments are 2
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

string ciphertext(string plain, string key)
{
    string c = plain;
    string k = key;
    string abc = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; plain[i] != '\0'; i++)
    {
        if (islower(plain[i]) != 0)
        {
            for (int j = 0; k[j] != '\0'; j++)
            {
                if (abc[j] == (plain[i]))
                {
                    c[i] = tolower(k[j]);
                    break;
                }
            }
        }
        else if (isupper(plain[i]) != 0)
        {
            for (int j = 0; k[j] != '\0'; j++)
            {
                if (toupper(abc[j]) == plain[i])
                {
                    c[i] = toupper(k[j]);
                    break;
                }
            }
        }
        else
        {
            c[i] = plain[i];

        }
    }
    return c;
}