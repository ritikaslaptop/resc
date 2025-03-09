#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences array: preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// array of candidates
candidate candidates[MAX_CANDIDATES];

// numbers of voters and candidates
int voter_count;
int candidate_count;

// function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // check for invalid usage
    if (argc < 2)
    {
        printf("usage: runoff [candidate ...]\n");
        return 1;
    }

    // populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // get number of voters
    voter_count = get_int("number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("rank %i for voter %i: ", j + 1, i);
            if (!vote(i, j, name))
            {
                printf("invalid vote.\n");
                return 4;
            }
        }
    }

    // keep holding runoffs until winner exists
    while (true)
    {
        // calculate votes given remaining candidates
        tabulate();

        // check if election has been won
        if (print_winner())
        {
            break;
        }

        // eliminate last-place candidates
        int min = find_min();
        if (is_tie(min))
        {
            // print all tied candidates
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // eliminate anyone with minimum number of votes
        eliminate(min);

        // reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
}

// print the winner of the election, if there is one
bool print_winner(void)
{
    int majority = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min_votes = MAX_VOTERS;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

// return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
