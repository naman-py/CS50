#include <cs50.h>
#include <stdio.h>
void pattern(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = h - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
int main(void)
{
    int height;
    do
    {
        height = get_int("Height : ");
        if (height > 0 && height < 9)
        {
            break;
        }
    }
    while (true);
    pattern(height);
}
