#include <stdio.h>

int main()
{
    int a[100], n, key;
    int beg, end, mid;
    int found = 0;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    beg = 0;
    end = n - 1;

    // ELI10: Keep cutting the search area into half.
    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (a[mid] == key)
        {
            printf("Key found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if (a[mid] > key)
        {
            // ELI10: Key is smaller, so search the left half.
            end = mid - 1;
        }
        else
        {
            // ELI10: Key is bigger, so search the right half.
            beg = mid + 1;
        }
    }

    if (!found)
        printf("Key not found\n");

    return 0;
}
