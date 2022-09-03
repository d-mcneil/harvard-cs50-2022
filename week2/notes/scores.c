# include <stdio.h>
# include <cs50.h>

int main(void)
{
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;
    // int scores[3];
    // scores[0] = get_int("Score: ");
    // scores[1] = get_int("Score: ");
    // scores[2] = get_int("Score: ");
    // for (int i = 0; i < 3; i++)
    int x = get_float("Quantity of tests: ");
    float scores[x];
    for (int i = 0; i < x; i++)
    {
        scores[i] = get_float("Score: ");
    }
    float sum_of_scores = 0;
    for (int j = 0; j < x; j++)
        {
            sum_of_scores += scores[j];
        }

    // printf("average score is %f\n", ((score1 + score2 + score3)/3.0));
    // printf("average score is %f\n", (scores[0]+scores[1]+scores[2])/3.0);
    printf("average score is %f\n", sum_of_scores/x);
}