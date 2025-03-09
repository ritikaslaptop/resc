#include <cs50.h>
#include <stdio.h>
#include <string.h>

// max number of candidates
#define MAX 9

// candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// array of candidates
candidate candidates[MAX];

// number of candidates
int candidate_count;

// function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // display winner of election
    print_winner();
    return 0;
}

// update vote totals given a new vote
bool vote(string name)
{
    // iterate over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // check if the candidate's name matches the given name
        if (strcmp(candidates[i].name, name) == 0)
        {
            // if yes, increment the candidate's votes and return true
            candidates[i].votes++;
            return true;
        }
    }

    // if no match, return false
    return false;
}

// print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;

    // find the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // print the candidate (or candidates) with the maximum votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
