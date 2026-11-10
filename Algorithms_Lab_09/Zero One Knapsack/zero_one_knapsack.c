#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

/*
   0/1 Knapsack using Dynamic Programming.

   For every item and every possible capacity, decide:
   take the item or leave it.
*/
int zeroOneKnapsack(int weight[], int profit[], int n, int capacity)
{
    int **dp;
    int i, w;
    int result;

    dp = (int **)malloc((n + 1) * sizeof(int *));

    if (dp == NULL)
        return -1;

    for (i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));

        if (dp[i] == NULL)
        {
            while (i > 0)
            {
                free(dp[i - 1]);
                i--;
            }

            free(dp);
            return -1;
        }
    }

    /* No items means zero profit. */
    for (w = 0; w <= capacity; w++)
        dp[0][w] = 0;

    /* Zero capacity means zero profit. */
    for (i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (i = 1; i <= n; i++)
    {
        for (w = 1; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
            {
                int include =
                    profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                dp[i][w] = max(include, exclude);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    result = dp[n][capacity];

    printf("\nDynamic Programming Table:\n\n");

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= capacity; w++)
            printf("%4d", dp[i][w]);

        printf("\n");
    }

    /*
       Reconstruct the selected items.
       This shows which complete items form the optimal solution.
    */
    printf("\nSelected items:\n");

    w = capacity;

    for (i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("Item %d (Weight = %d, Profit = %d)\n",
                   i,
                   weight[i - 1],
                   profit[i - 1]);

            w -= weight[i - 1];
        }
    }

    for (i = 0; i <= n; i++)
        free(dp[i]);

    free(dp);

    return result;
}

int main()
{
    int n, capacity;
    int *weight;
    int *profit;
    int i;
    int maximumProfit;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    if (n <= 0 || capacity < 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    weight = (int *)malloc(n * sizeof(int));
    profit = (int *)malloc(n * sizeof(int));

    if (weight == NULL || profit == NULL)
    {
        printf("Memory allocation failed.\n");
        free(weight);
        free(profit);
        return 1;
    }

    printf("\nEnter weight and profit of each item:\n");

    for (i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);

        if (weight[i] <= 0 || profit[i] < 0)
        {
            printf("Weight must be positive and profit cannot be negative.\n");
            free(weight);
            free(profit);
            return 1;
        }
    }

    maximumProfit =
        zeroOneKnapsack(weight, profit, n, capacity);

    if (maximumProfit < 0)
    {
        printf("Unable to allocate the DP table.\n");
        free(weight);
        free(profit);
        return 1;
    }

    printf("\nMaximum Profit = %d\n", maximumProfit);

    free(weight);
    free(profit);

    return 0;
}
