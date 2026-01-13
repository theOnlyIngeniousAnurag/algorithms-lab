// Experiment 1: Linear Search
// Aim: To search a given key element in an array using the Linear Search algorithm.

#include <stdio.h>

int main()
{
    int A[50], N, key, i, flag = 0;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter elements:\n");
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    for(i = 0; i < N; i++)
    {
        if(A[i] == key)
        {
            printf("Element found at position %d", i);
            flag = 1;
            break;
        }
    }

    if(flag != 1)
        printf("Element not found");

    return 0;
}


//Sample Input & Output
/* Enter number of elements: 5
Enter elements:
10 20 30 40 50
Enter key to search: 30

 Element found at position 2
*/

// Linear Search works on both sorted and unsorted arrays
// Time Complexity: O(n)
// Space Complexity: O(1)
