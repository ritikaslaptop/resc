#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get text input
    string text = get_string("Text: ");

    // initialize counters
    int letters = 0, words = 1, sentences = 0;

    // iterate through the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
            letters++;
        else if (isspace(text[i]))
            words++;
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }

    // calculate l and s
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    // compute the coleman-liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // round and output grade level
    int grade = round(index);
    if (grade >= 16)
        printf("Grade 16+\n");
    else if (grade < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %d\n", grade);
}
