#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    printf("%i\n%i\n%i\n", letters, words, sentences);

    // Compute the Coleman-Liau index
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int gd = round(index);
        printf("Grade %i\n", gd);
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int l = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            l++;
        }
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            l++;
        }
    }
    return l;
}

int count_words(string text)
{
    // Return the number of words in text
    int w = 1;
    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == ' ')
        {
            w++;
        }
    }
    return w;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int s = 0;
    char ch[] = {'.', '?', '!'};
    for (int k = 0; k < 3; k++)
    {
        for (int h = 0; h < strlen(text); h++)
        {
            if (ch[k] == text[h])
            {
                s++;
            }
        }
    }
    return s;
}
