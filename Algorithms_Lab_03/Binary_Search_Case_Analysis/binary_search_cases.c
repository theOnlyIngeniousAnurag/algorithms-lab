#include <stdio.h>
#include <time.h>

int binarySearch(int a[], int n, int key)
{
    int beg = 0;
    int end = n - 1;
    int mid;

    // ELI10: Keep cutting the sorted search area into half.
    while (beg <= end)
    {
        mid = beg + (end - beg) / 2;

        if (a[mid] == key)
            return mid;

        if (a[mid] < key)
            beg = mid + 1;       // ELI10: Search right half.
        else
            end = mid - 1;       // ELI10: Search left half.
    }

    return -1;
}

double measureBinarySearch(int a[], int n, int key, int repetitions)
{
    int i;
    volatile int result;
    clock_t start, end;

    start = clock();

    // ELI10: Repeat the search so the timer can measure it more clearly.
    for (i = 0; i < repetitions; i++)
        result = binarySearch(a, n, key);

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

    /*
       Create a sorted array:
       0, 2, 4, 6, ...
    */
    for (i = 0; i < n; i++)
        a[i] = 2 * i;

    /*
       Best case:
       First middle element is found immediately.
    */
    bestKey = a[(n - 1) / 2];

    /*
       Average case:
       Use a representative key near the middle.
       For rigorous experimental averaging, run multiple
       successful searches using different positions.
    */
    averageKey = a[n / 4];

    /*
       Worst case:
       A value outside the array guarantees an unsuccessful search.
    */
    worstKey = 2 * n + 1;

    bestTime = measureBinarySearch(a, n, bestKey, repetitions);
    averageTime = measureBinarySearch(a, n, averageKey, repetitions);
    worstTime = measureBinarySearch(a, n, worstKey, repetitions);

    printf("\nInput Size = %d\n", n);
    printf("Repetitions per measurement = %d\n", repetitions);

    printf("\nBest Case:\n");
    printf("Key = %d\n", bestKey);
    printf("CPU Time = %.9f seconds\n", bestTime);

    printf("\nAverage Case (representative successful search):\n");
    printf("Key = %d\n", averageKey);
    printf("CPU Time = %.9f seconds\n", averageTime);

    printf("\nWorst Case:\n");
    printf("Key = %d (not present)\n", worstKey);
    printf("CPU Time = %.9f seconds\n", worstTime);

    return 0;
}
