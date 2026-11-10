#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    double ratio;
};

/* Swap two items. */
void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

/*
   Bubble Sort by profit/weight ratio in descending order.
   ELI10: Put the most profitable item per unit weight first.
*/
void sortByRatio(struct Item items[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
                swap(&items[j], &items[j + 1]);
        }
    }
}

double fractionalKnapsack(struct Item items[], int n, double capacity)
{
    int i;
    double remaining = capacity;
    double totalProfit = 0.0;
    double fraction;

    for (i = 0; i < n; i++)
    {
        if (remaining <= 0.0)
            break;

        if (items[i].weight <= remaining)
        {
            remaining -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            fraction = remaining / items[i].weight;
            totalProfit += items[i].profit * fraction;
            remaining = 0.0;
        }
    }

    return totalProfit;
}

int main()
{
    struct Item items[100];
    int n, i;
    double capacity;
    double maximumProfit;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%lf", &capacity);

    printf("\nEnter weight and profit of each item:\n");

    for (i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);

        if (items[i].weight <= 0)
        {
            printf("Weight must be positive.\n");
            return 1;
        }

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    sortByRatio(items, n);

    printf("\nItems sorted by profit/weight ratio:\n");
    printf("Item\tWeight\tProfit\tRatio\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\n",
               i + 1,
               items[i].weight,
               items[i].profit,
               items[i].ratio);
    }

    maximumProfit =
        fractionalKnapsack(items, n, capacity);

    printf("\nMaximum Profit = %.2f\n", maximumProfit);

    return 0;
}
