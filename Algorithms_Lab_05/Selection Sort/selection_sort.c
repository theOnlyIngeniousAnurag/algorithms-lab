#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        // ELI10: Find the smallest value in the unsorted part.
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        // ELI10: Put the smallest value at its correct position.
        if (minIndex != i)
        {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

double measureSelectionSort(int original[], int n, int repetitions)
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
        // ELI10: Restore the same input before every timed sort.
        for (j = 0; j < n; j++)
            a[j] = original[j];

        selectionSort(a, n);
    }

    end = clock();

    keep = a[0];
    (void)keep;

    free(a);

    return ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
}

int main()
{
    int *randomArray;
    int n, i;
    int repetitions = 100;
    double bestTime, averageTime, worstTime;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    randomArray = (int *)malloc(n * sizeof(int));

    if (randomArray == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    // ELI10: Create random data for the average-case test.
    for (i = 0; i < n; i++)
        randomArray[i] = rand() % 100000;

    /*
       Best case: already sorted input.
       Selection Sort still performs its normal comparisons.
    */
    {
        int *best = (int *)malloc(n * sizeof(int));

        if (best == NULL)
        {
            free(randomArray);
            return 1;
        }

        for (i = 0; i < n; i++)
            best[i] = i;

        bestTime = measureSelectionSort(best, n, repetitions);
        free(best);
    }

    // Average case: random input.
    averageTime = measureSelectionSort(randomArray, n, repetitions);

    /*
       Worst case: reverse-sorted input.
       The comparison count remains O(n^2).
    */
    {
        int *worst = (int *)malloc(n * sizeof(int));

        if (worst == NULL)
        {
            free(randomArray);
            return 1;
        }

        for (i = 0; i < n; i++)
            worst[i] = n - i;

        worstTime = measureSelectionSort(worst, n, repetitions);
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

    free(randomArray);

    return 0;
}
