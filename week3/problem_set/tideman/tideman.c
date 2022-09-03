#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool create_cycle(int winner, int loser); // added by me
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// TODO
// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++){
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// TODO
// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        int candidate_i_rank;
        for (int k = 0; k < candidate_count; k++)
        {
            if (ranks[k] == i)
            {
                candidate_i_rank = k;
            }
        }
        for (int j = i + 1; j < candidate_count; j++)
        {
            int candidate_j_rank;
            for (int k = 0; k < candidate_count; k++)
            {
                if (ranks[k] == j)
                {
                    candidate_j_rank = k;
                }
            }
            if (candidate_i_rank < candidate_j_rank)
            {
                preferences[i][j] += 1;
            }
            else if (candidate_j_rank < candidate_i_rank)
            {
                preferences[j][i] += 1;
            }
        }
    }
    return;
}

// TODO
// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count += 1;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count += 1;
            }
        }
    }
    return;
}

// TODO
// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{ // used bubble sorting
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count - 1; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j+1].winner][pairs[j+1].loser])
            {
                pair temporary = pairs[j+1];
                pairs[j+1] = pairs[j];
                pairs[j] = temporary;
            }
        }
    }
}

// added by me, wasn't able to solve on my own and had to look at some online resources to push me in the direction of using a recursive function
// uses recursion to check to see if locking in a pair would create a cycle, called in lock_pairs function
bool create_cycle(int winner, int loser)
{
    if (winner == loser)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] && create_cycle(winner, i))
        {
            return true;
        }
    }
    return false;
}

// TODO
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{// solved with help from some online resources
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if(!create_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }


    // this was the second way i solved the problem, but it still wasn't truly checking for cycles  - though, it did give correct answers from examples in problem set

    // bool possible_winners[candidate_count];
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     possible_winners[i] = true;
    // }
    // int possible_winner_count = candidate_count;
    // for (int k = 0; k < pair_count; k++)
    // {
    //     if (possible_winner_count > 1)
    //     {
    //         locked[pairs[k].winner][pairs[k].loser] = true;
    //         if (possible_winners[pairs[k].loser])
    //         {
    //             possible_winners[pairs[k].loser] = false;
    //             possible_winner_count -= 1;
    //         }
    //     }
    // }



    // this was the first way i solved the locking problem, but it had to check every coordinate in the locked array
    // for every pair, and that wasn't the most efficient way to solve the problem
    // plus, it wasn't truly checking for cycles - though, it did give correct answers from examples in problem set

    // for (int k = 0; k < pair_count; k++)
    // {
    //     int possible_winners = candidate_count;
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         bool possible_winner = true;
    //         for (int i = 0; i < candidate_count; i++)
    //         {
    //             if (locked[i][j])
    //             {
    //                 possible_winner = false;
    //             }
    //         }
    //         if (!possible_winner)
    //         {
    //             possible_winners -= 1;
    //         }
    //     }
    //     if (possible_winners > 1)
    //     {
    //         locked[pairs[k].winner][pairs[k].loser] = true;
    //     }
    // }
}

// TODO
// Print the winner of the election
void print_winner(void)
{
    for (int j = 0; j < candidate_count; j++)
    {
        bool winner = true;
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][j])
            {
                winner = false;
            }
        }
        if (winner)
        {
            printf("%s\n", candidates[j]);
            return;
        }
    }
}