#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string Encipher(string text, string arg);

string cletters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string sletters = "abcdefghijklmnopqrstuvwxyz";
int main(int argc, string argv[])
{
    // VALIDATE KEY

    if (argc <= 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    int n = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (argv[1][i] == cletters[j] || argv[1][i] == sletters[j])
            {
                n++;
            }
        }
        for (int k = 0; k < 26; k++)
        {
            if (k == i)
            {
                continue;
            }
            if (toupper(argv[1][i]) == toupper(argv[1][k]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    if (n < 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Get plaintext
    string plaintext = get_string("Plaintext: ");

    // Encipher
    string ciphertext = Encipher(plaintext, argv[1]);

    // print cipher text
    printf("ciphertext: %s\n", ciphertext);
}

string Encipher(string text, string arg)
{
    printf("%s\n", arg);
    printf("%s\n", text);
    for (int i = 0; i <= strlen(text); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == cletters[j])
            {
                text[i] = toupper(arg[j]);
                break;
            }
            if (text[i] == sletters[j])
            {
                text[i] = tolower(arg[j]);
                break;
            }
        }
    }
    return text;
}
