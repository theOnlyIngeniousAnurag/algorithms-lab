#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int a[], int n, int key)
{
    int i;

    // ELI10: Check every element one by one.
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
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

    srand((unsigned)time(NULL));

    // ELI10: Fill the array with random values.
    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    // ELI10: Use one random array value as the key.
    key = a[n / 2];

    start = clock();

    result = linearSearch(a, n, key);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Key = %d\n", key);

    if (result != -1)
        printf("Key found at position %d\n", result + 1);
    else
        printf("Key not found\n");

    printf("CPU Time = %.9f seconds\n", cpu_time);

    return 0;
}
