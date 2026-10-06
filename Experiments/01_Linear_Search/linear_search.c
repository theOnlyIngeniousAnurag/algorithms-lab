
#include <stdio.h>

int main()
{
    int a[100], n, key;
    int i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    // Check each element one by one until the key is found.
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Key found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    // If we checked everything and found nothing, the key is absent.
    if (!found)
        printf("Key not found\n");

    return 0;
}


// Time Complexity: O(n)
// Space Complexity: O(1)
