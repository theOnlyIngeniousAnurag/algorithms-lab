#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
   Merge Sort keeps dividing the array into smaller pieces,
   sorts those pieces, and finally joins them in sorted order.
*/
void mergeSort(int a[], int left, int right)
{
    int mid;
    int i, j, k;
    int size;
    int *temp;

    if (left >= right)
        return;

    /* Find the middle and divide the array into two parts. */
    mid = left + (right - left) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    size = right - left + 1;
    temp = (int *)malloc(size * sizeof(int));

    if (temp == NULL)
        return;

    i = left;
    j = mid + 1;
    k = 0;

    /* Compare the front values of both sorted halves. */
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    /* Copy any remaining values from the left half. */
    while (i <= mid)
        temp[k++] = a[i++];

    /* Copy any remaining values from the right half. */
    while (j <= right)
        temp[k++] = a[j++];

    /* Copy the merged result back into the original array. */
    for (i = left, k = 0; i <= right; i++, k++)
        a[i] = temp[k];

    free(temp);
}

/* Measure the CPU time required by Merge Sort. */
double measureMergeSort(int original[], int n, int repetitions)
{
    int *a;
    int i, j;
    clock_t start, end;

    a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
        return -1.0;

    start = clock();

    for (i = 0; i < repetitions; i++)
    {
        for (j = 0; j < n; j++)
            a[j] = original[j];

        mergeSort(a, 0, n - 1);
    }

    end = clock();

    free(a);

    return ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
}

void displayFirstElements(int a[], int n)
{
    int limit = n < 10 ? n : 10;
    int i;

    for (i = 0; i < limit; i++)
        printf("%d ", a[i]);

    if (n > 10)
        printf("...");

    printf("\n");
}

int main()
{
    int *randomArray;
    int *bestArray;
    int *worstArray;

    int n, i;
    int repetitions = 100;

    double bestTime;
    double averageTime;
    double worstTime;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input size.\n");
        return 1;
    }

    randomArray = (int *)malloc(n * sizeof(int));
    bestArray = (int *)malloc(n * sizeof(int));
    worstArray = (int *)malloc(n * sizeof(int));

    if (randomArray == NULL || bestArray == NULL || worstArray == NULL)
    {
        printf("Memory allocation failed.\n");
        free(randomArray);
        free(bestArray);
        free(worstArray);
        return 1;
    }

    srand((unsigned)time(NULL));

    /* Best-case input: already sorted. */
    for (i = 0; i < n; i++)
        bestArray[i] = i;

    /* Average-case input: random values. */
    for (i = 0; i < n; i++)
        randomArray[i] = rand() % 100000;

    /* Worst-case input: reverse sorted. */
    for (i = 0; i < n; i++)
        worstArray[i] = n - i;

    printf("\nInput Size = %d\n", n);
    printf("Repetitions per measurement = %d\n", repetitions);

    printf("\nBest Case - Before Sorting (first 10): ");
    displayFirstElements(bestArray, n);

    bestTime = measureMergeSort(bestArray, n, repetitions);

    printf("Best Case - After Sorting  (first 10): ");
    mergeSort(bestArray, 0, n - 1);
    displayFirstElements(bestArray, n);

    printf("CPU Time = %.9f seconds\n", bestTime);

    printf("\nAverage Case - Before Sorting (first 10): ");
    displayFirstElements(randomArray, n);

    averageTime = measureMergeSort(randomArray, n, repetitions);

    printf("Average Case - After Sorting  (first 10): ");
    mergeSort(randomArray, 0, n - 1);
    displayFirstElements(randomArray, n);

    printf("CPU Time = %.9f seconds\n", averageTime);

    printf("\nWorst Case - Before Sorting (first 10): ");
    displayFirstElements(worstArray, n);

    worstTime = measureMergeSort(worstArray, n, repetitions);

    printf("Worst Case - After Sorting  (first 10): ");
    mergeSort(worstArray, 0, n - 1);
    displayFirstElements(worstArray, n);

    printf("CPU Time = %.9f seconds\n", worstTime);

    free(randomArray);
    free(bestArray);
    free(worstArray);

    return 0;
}
