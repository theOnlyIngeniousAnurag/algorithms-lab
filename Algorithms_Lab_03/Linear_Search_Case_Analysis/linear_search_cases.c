#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int a[], int n, int key)
{
    int i;

    // ELI10: Check the array from left to right.
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }

    return -1;
}

double measureLinearSearch(int a[], int n, int key, int repetitions)
{
    int i;
    volatile int result;
    clock_t start, end;

    start = clock();

    // ELI10: Repeat the same search to make tiny CPU times measurable.
    for (i = 0; i < repetitions; i++)
        result = linearSearch(a, n, key);

    end = clock();

    (void)result;

    return ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
}

int main()
{
    int a[10000];
    int n, i;
    int repetitions = 10000;
    int bestKey, averageKey, worstKey;
    double bestTime, averageTime, worstTime;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand((unsigned)time(NULL));

    // ELI10: Generate random data.
    for (i = 0; i < n; i++)
        a[i] = rand() % 100000;

    /*
       Best case:
       The first element is the key.
    */
    bestKey = a[0];

    /*
       Average case:
       Use a middle-position element as a simple practical
       representative. For formal average-case analysis,
       multiple randomly chosen successful positions can be averaged.
    */
    averageKey = a[n / 2];

    /*
       Worst case:
       Search for a value that is guaranteed not to occur
       in the generated range.
    */
    worstKey = 100001;

    bestTime = measureLinearSearch(a, n, bestKey, repetitions);
    averageTime = measureLinearSearch(a, n, averageKey, repetitions);
    worstTime = measureLinearSearch(a, n, worstKey, repetitions);

    printf("\nInput Size = %d\n", n);
    printf("Repetitions per measurement = %d\n", repetitions);

    printf("\nBest Case:\n");
    printf("Key = %d\n", bestKey);
    printf("CPU Time = %.9f seconds\n", bestTime);

    printf("\nAverage Case (representative middle position):\n");
    printf("Key = %d\n", averageKey);
    printf("CPU Time = %.9f seconds\n", averageTime);

    printf("\nWorst Case:\n");
    printf("Key = %d (not present)\n", worstKey);
    printf("CPU Time = %.9f seconds\n", worstTime);

    return 0;
}
