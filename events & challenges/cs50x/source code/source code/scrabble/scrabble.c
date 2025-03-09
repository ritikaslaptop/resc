#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function to compute the score of a word
int compute_score(string word);

// Points assigned to each letter
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: Enter your word: ");
    string word2 = get_string("Player 2: Enter your word: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

// Function to compute the score of a word
int compute_score(string word)
{
    int score = 0;

    // Loop through each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Check if the character is a letter
        if (isalpha(word[i]))
        {
            // convert to uppercase and calculate score
            int letter_index = toupper(word[i]) - 'A';
            score += POINTS[letter_index];
        }
    }

    return score;
}
