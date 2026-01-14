// Experiment 2: Binary Search
// Aim: To search a given key element in a sorted array using the Binary Search algorithm.

#include <stdio.h>

int main()
{
    int A[50], N, key;
    int beg, end, mid, flag = 0;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter sorted elements:\n");
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    beg = 0;
    end = N - 1;

    while(beg <= end)
    {
        mid = (beg + end) / 2;

        if(A[mid] == key)
        {
            printf("Element found at position %d", mid);
            flag = 1;
            break;
        }
        else if(A[mid] > key)
            end = mid - 1;
        else
            beg = mid + 1;
    }

    if(flag != 1)
        printf("Element not found");

    return 0;
}


//Sample Input & Output:
/*
Enter number of elements: 6
Enter sorted elements:
5 10 15 20 25 30
Enter key to search: 20

Element found at position 3
*/

// Binary Search works only on sorted arrays
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Faster than Linear Search
