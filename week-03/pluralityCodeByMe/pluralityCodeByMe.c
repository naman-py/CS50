#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef struct
{
    string name;
    int vote;
}
candidate;

int main(int argc, string argv[])
{
    if (argc > 1 && argc < 10)
    {
        printf("");
    }
    else
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    candidate candidates[argc - 1];

    for (int i = 0; i < argc - 1; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].vote = 0;
    }

    int n = get_int("Number of voters: ");
    for (int j = 0; j < n; j++)
    {
        int h = 0;
        string votername = get_string("Vote: ");
        for (int k = 0; k < argc - 1; k++)
        {
            if (strcmp(votername, candidates[k].name) == 0)
            {
                candidates[k].vote++;
                h++;
            }
        }
        if (h == 0)
        {
            printf("Invalid vote.\n");
            j--;
        }
    }
    int a = candidates[0].vote;
    for (int o = 0; o < argc - 1; o++)
    {
        if (a < candidates[o].vote)
        {
            a = candidates[o].vote;
        }
    }
    for (int r = 0; r < argc - 1; r++)
    {
        if (a == candidates[r].vote)
        {
            printf("%s\n", candidates[r].name);
        }
    }
}
