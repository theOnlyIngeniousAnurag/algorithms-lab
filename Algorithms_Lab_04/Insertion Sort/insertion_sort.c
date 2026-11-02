#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int a[], int n)
{
    int i, j, key;

    // ELI10: Take one value and insert it into the sorted left side.
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        // ELI10: Move larger values one position to the right.
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        // ELI10: Put the key into its correct position.
        a[j + 1] = key;
    }
}

double measureInsertionSort(int original[], int n, int repetitions)
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

        insertionSort(a, n);
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

    // ELI10: Generate random data for the average-case test.
    for (i = 0; i < n; i++)
        a[i] = rand() % 100000;

    /*
       Best case: already sorted input.
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

        bestTime = measureInsertionSort(best, n, repetitions);
        free(best);
    }

    // Average case: random input.
    averageTime = measureInsertionSort(a, n, repetitions);

    /*
       Worst case: reverse-sorted input.
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

        worstTime = measureInsertionSort(worst, n, repetitions);
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
