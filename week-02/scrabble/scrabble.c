#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score(string word);
string upper(string str1);

string str[] = {"AEILNORSTU", "DG", "BCMP", "FHVWY", "K", "", "", "JX", "", "QZ"};
int main(void)
{
    string P1 = upper(get_string("Player 1 : "));
    string P2 = upper(get_string("Player 2 : "));

    int scr1 = score(P1);
    int scr2 = score(P2);
    if (scr1 > scr2)
    {
        printf("Player 1 wins!\n");
    }
    else if (scr1 < scr2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

string upper(string str1)
{
    for (int i = 0; str1[i]; i++)
    {
        str1[i] = toupper(str1[i]);
    }
    return str1;
}

int score(string word)
{
    int scr = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < strlen(str[i]); j++)
        {
            for (int k = 0; k < strlen(word); k++)
            {
                if (word[k] == str[i][j])
                {
                    scr += i + 1;
                }
            }
        }
    }
    return scr;
}
