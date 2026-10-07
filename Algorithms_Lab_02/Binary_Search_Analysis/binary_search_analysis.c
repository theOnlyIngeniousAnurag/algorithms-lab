#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int a[], int n, int key)
{
    int beg = 0;
    int end = n - 1;
    int mid;

    // ELI10: Keep cutting the sorted array into half.
    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (a[mid] == key)
            return mid;

        if (a[mid] < key)
            beg = mid + 1;   // ELI10: Search right half.
        else
            end = mid - 1;   // ELI10: Search left half.
    }

    return -1;
}

int main()
{
    int a[10000];
    int n, i, key, result;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // ELI10: Make a sorted array so Binary Search can work.
    for (i = 0; i < n; i++)
        a[i] = i * 2;

    printf("Enter key to search: ");
    scanf("%d", &key);

    start = clock();

    result = binarySearch(a, n, key);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Key found at position %d\n", result + 1);
    else
        printf("Key not found\n");

    printf("CPU Time = %.9f seconds\n", cpu_time);

    return 0;
}
