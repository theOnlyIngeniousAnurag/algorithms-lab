#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

/* Add a node at the end of the doubly linked list. */
void insertEnd(struct Node **head, int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

/*
   Insertion Sort using the doubly linked list.

   ELI10:
   Take one node's value and move larger values to the right.
*/
void insertionSort(struct Node *head)
{
    struct Node *current;
    struct Node *previous;
    int key;

    if (head == NULL)
        return;

    current = head->next;

    while (current != NULL)
    {
        key = current->data;
        previous = current->prev;

        // ELI10: Shift bigger values one position forward.
        while (previous != NULL && previous->data > key)
        {
            previous->next->data = previous->data;
            previous = previous->prev;
        }

        // ELI10: Put the key into the empty/correct position.
        if (previous == NULL)
            head->data = key;
        else
            previous->next->data = key;

        current = current->next;
    }
}

/* Free all nodes. */
void freeList(struct Node *head)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* Create a list from an integer array. */
struct Node *createList(int a[], int n)
{
    struct Node *head = NULL;
    int i;

    for (i = 0; i < n; i++)
        insertEnd(&head, a[i]);

    return head;
}

/* Measure only the sorting operation. */
double measureSort(int original[], int n, int repetitions)
{
    struct Node *head;
    int i;
    clock_t start, end;

    start = clock();

    for (i = 0; i < repetitions; i++)
    {
        head = createList(original, n);

        insertionSort(head);

        freeList(head);
    }

    end = clock();

    return ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    int *randomArray;
    int n, i;
    int repetitions = 100;

    double bestTime;
    double averageTime;
    double worstTime;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    randomArray = (int *)malloc(n * sizeof(int));

    if (randomArray == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    /* Average-case input: random values. */
    for (i = 0; i < n; i++)
        randomArray[i] = rand() % 100000;

    /* Best case: sorted values. */
    {
        int *best = (int *)malloc(n * sizeof(int));

        if (best == NULL)
        {
            free(randomArray);
            return 1;
        }

        for (i = 0; i < n; i++)
            best[i] = i;

        bestTime = measureSort(best, n, repetitions);
        free(best);
    }

    /* Average case: random values. */
    averageTime = measureSort(randomArray, n, repetitions);

    /* Worst case: reverse-sorted values. */
    {
        int *worst = (int *)malloc(n * sizeof(int));

        if (worst == NULL)
        {
            free(randomArray);
            return 1;
        }

        for (i = 0; i < n; i++)
            worst[i] = n - i;

        worstTime = measureSort(worst, n, repetitions);
        free(worst);
    }

    printf("\nInput Size = %d\n", n);
    printf("Repetitions per measurement = %d\n", repetitions);

    printf("\nBest Case (sorted linked list):\n");
    printf("CPU Time = %.9f seconds\n", bestTime);

    printf("\nAverage Case (random linked list):\n");
    printf("CPU Time = %.9f seconds\n", averageTime);

    printf("\nWorst Case (reverse-sorted linked list):\n");
    printf("CPU Time = %.9f seconds\n", worstTime);

    /*
       Small demonstration of the actual linked-list sorting.
    */
    {
        int demo[] = {5, 3, 4, 1, 2};
        struct Node *head;
        int demoSize = 5;

        head = createList(demo, demoSize);

        printf("\nDemonstration:\n");
        printf("Before sorting: ");
        display(head);

        insertionSort(head);

        printf("After sorting:  ");
        display(head);

        freeList(head);
    }

    free(randomArray);

    return 0;
}
