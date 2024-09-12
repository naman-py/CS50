#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int qty = 0;
    int x = 0;
    int change;
    while (true)
    {
        change = get_int("change owed : ");
        if (change >= 0)
        {
            break;
        }
    }
    int a = 25, b = 10, c = 5, d = 1;
    for (int i = 0; i <= change; i++)
    {
        x += a;
        qty++;
        if (x > change)
        {
            x -= a;
            qty--;
            break;
        }
        if (x == change)
        {
            break;
        }
    }
    for (int j = 0; j <= change; j++)
    {
        x += b;
        qty++;
        if (x > change)
        {
            x -= b;
            qty--;
            break;
        }
        if (x == change)
        {
            break;
        }
    }
    for (int k = 0; k <= change; k++)
    {
        x += c;
        qty++;
        if (x > change)
        {
            x -= c;
            qty--;
            break;
        }
        if (x == change)
        {
            break;
        }
    }
    for (int l = 0; l <= change; l++)
    {
        x += d;
        qty++;
        if (x > change)
        {
            x -= d;
            qty--;
            break;
        }
        if (x == change)
        {
            break;
        }
    }
    printf("%i\n", qty);
}
