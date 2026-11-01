#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int a[], int n)
{
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        // ELI10: Compare neighbors and push the largest value to the end.
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }

        // ELI10: If nothing moved, the array is already sorted.
        if (!swapped)
            break;
    }
}

double measureBubbleSort(int original[], int n, int repetitions)
{
    int *a;
    int i, j;
    clock_t start, end;
    volatile int keep;

    a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
        return -1.0;

    start = clock();

    for (i = 0; i < repetitions; i++)
    {
        for (j = 0; j < n; j++)
            a[j] = original[j];

        bubbleSort(a, n);
    }

    end = clock();

    keep = a[0];
    (void)keep;

    free(a);

    return ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
}

int main()
{
    int *a;
    int n, i;
    int repetitions = 100;
    double bestTime, averageTime, worstTime;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    // ELI10: Generate one random array for the average-case test.
    for (i = 0; i < n; i++)
        a[i] = rand() % 100000;

    /*
       Best case: already sorted array.
       Make it sorted directly.
    */
    {
        int *best = (int *)malloc(n * sizeof(int));

        if (best == NULL)
        {
            free(a);
            return 1;
        }

        for (i = 0; i < n; i++)
            best[i] = i;

        bestTime = measureBubbleSort(best, n, repetitions);
        free(best);
    }

    // Average case: random array.
    averageTime = measureBubbleSort(a, n, repetitions);

    /*
       Worst case: reverse-sorted array.
    */
    {
        int *worst = (int *)malloc(n * sizeof(int));

        if (worst == NULL)
        {
            free(a);
            return 1;
        }

        for (i = 0; i < n; i++)
            worst[i] = n - i;

        worstTime = measureBubbleSort(worst, n, repetitions);
        free(worst);
    }

    printf("\nInput Size = %d\n", n);
    printf("Repetitions per measurement = %d\n", repetitions);

    printf("\nBest Case (sorted input):\n");
    printf("CPU Time = %.9f seconds\n", bestTime);

    printf("\nAverage Case (random input):\n");
    printf("CPU Time = %.9f seconds\n", averageTime);

    printf("\nWorst Case (reverse-sorted input):\n");
    printf("CPU Time = %.9f seconds\n", worstTime);

    free(a);

    return 0;
}
