#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declare variables for change owed and number of coins
    int change_owed;

    // Prompt the user for an amount of change owed (in cents)
    do
    {
        change_owed = get_int("Change owed: ");
    } while (change_owed < 0);

    // Initialize coin denominations in cents
    int coins[] = {25, 10, 5, 1};
    int num_coins = 0;

    // Calculate the minimum number of coins
    for (int i = 0; i < 4; i++)
    {
        while (change_owed >= coins[i])
        {
            change_owed -= coins[i];
            num_coins++;
        }
    }

    // Print the number of coins
    printf("%d\n", num_coins);

    return 0;
}
