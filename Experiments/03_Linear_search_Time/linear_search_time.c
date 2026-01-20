// Experiment 3: Linear Search with Random Test Cases and CPU Time Calculation
// Aim : To implement Linear Search by generating random input values and calculate the CPU time required for execution.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[100000], N, key, i, flag = 0;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    for(i = 0; i < N; i++)
        A[i] = rand() % 1000;

    printf("Enter key to search: ");
    scanf("%d", &key);

    start = clock();

    for(i = 0; i < N; i++)
    {
        if(A[i] == key)
        {
            flag = 1;
            break;
        }
    }

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    if(flag == 1)
        printf("Element found\n");
    else
        printf("Element not found\n");

    printf("CPU Time taken: %f seconds\n", cpu_time);

    return 0;
}


// Sample Input:
/*
Enter number of elements: 10000
Enter key to search: 500
*/

// Sample Output:
/*Element found
CPU Time taken: 0.000002 seconds
*/

// Time Complexity Analysis
/*
Best Case: O(1)
Average Case: O(n)
Worst Case: O(n)
*/
