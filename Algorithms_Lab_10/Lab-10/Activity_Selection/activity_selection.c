#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Activity
{
    int id;
    int start;
    int finish;
};

/* Swap two activities. */
void swap(struct Activity *a, struct Activity *b)
{
    struct Activity temp = *a;
    *a = *b;
    *b = temp;
}

/*
   Quick Sort activities according to finish time.

   ELI10:
   Put activities that finish earlier before activities
   that finish later.
*/
void quickSort(struct Activity a[], int low, int high)
{
    int i, j;
    int pivot;

    if (low >= high)
        return;

    pivot = a[low].finish;
    i = low + 1;
    j = high;

    while (1)
    {
        while (i <= high && a[i].finish <= pivot)
            i++;

        while (a[j].finish > pivot)
            j--;

        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
        else
        {
            break;
        }
    }

    swap(&a[low], &a[j]);

    quickSort(a, low, j - 1);
    quickSort(a, j + 1, high);
}

/*
   Greedy Activity Selection.

   ELI10:
   Pick the activity that finishes earliest.
   Then choose the next activity that starts after it finishes.
*/
int activitySelection(struct Activity a[], int n, int selected[])
{
    int count = 0;
    int lastFinish;
    int i;

    if (n <= 0)
        return 0;

    selected[count++] = 0;
    lastFinish = a[0].finish;

    for (i = 1; i < n; i++)
    {
        if (a[i].start >= lastFinish)
        {
            selected[count++] = i;
            lastFinish = a[i].finish;
        }
    }

    return count;
}

/*
   Generate activities for optional large-input timing experiments.
*/
void generateActivities(struct Activity a[], int n)
{
    int i;
    int maxStart = n * 2 + 10;

    for (i = 0; i < n; i++)
    {
        a[i].id = i + 1;
        a[i].start = rand() % maxStart;
        a[i].finish = a[i].start + 1 + rand() % 20;
    }
}

/*
   Measure sorting + greedy selection.
*/
double measureActivitySelection(struct Activity original[],
                                int n,
                                int repetitions)
{
    struct Activity *a;
    int *selected;
    int i, j;
    volatile int count;
    clock_t start, end;

    a = (struct Activity *)malloc(n * sizeof(struct Activity));
    selected = (int *)malloc(n * sizeof(int));

    if (a == NULL || selected == NULL)
    {
        free(a);
        free(selected);
        return -1.0;
    }

    start = clock();

    for (i = 0; i < repetitions; i++)
    {
        for (j = 0; j < n; j++)
            a[j] = original[j];

        quickSort(a, 0, n - 1);

        count = activitySelection(a, n, selected);
        (void)count;
    }

    end = clock();

    free(a);
    free(selected);

    return ((double)(end - start)) /
           CLOCKS_PER_SEC / repetitions;
}

void displayActivities(struct Activity a[], int n)
{
    int i;

    printf("Activity\tStart\tFinish\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\n",
               a[i].id,
               a[i].start,
               a[i].finish);
    }
}

int main()
{
    struct Activity *activities;
    int *selected;
    int n, i;
    int selectedCount;
    int repetitions = 100;
    double cpuTime;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of activities.\n");
        return 1;
    }

    activities =
        (struct Activity *)malloc(n * sizeof(struct Activity));

    selected =
        (int *)malloc(n * sizeof(int));

    if (activities == NULL || selected == NULL)
    {
        printf("Memory allocation failed.\n");
        free(activities);
        free(selected);
        return 1;
    }

    printf("\nEnter start and finish time for each activity:\n");

    for (i = 0; i < n; i++)
    {
        activities[i].id = i + 1;

        printf("Activity %d: ", i + 1);
        scanf("%d %d",
              &activities[i].start,
              &activities[i].finish);

        if (activities[i].start >= activities[i].finish)
        {
            printf("Finish time must be greater than start time.\n");
            free(activities);
            free(selected);
            return 1;
        }
    }

    cpuTime =
        measureActivitySelection(activities, n, repetitions);

    quickSort(activities, 0, n - 1);

    printf("\nActivities sorted by finish time:\n");
    displayActivities(activities, n);

    selectedCount =
        activitySelection(activities, n, selected);

    printf("\nSelected Activities:\n");

    for (i = 0; i < selectedCount; i++)
    {
        int index = selected[i];

        printf("Activity %d: (%d, %d)\n",
               activities[index].id,
               activities[index].start,
               activities[index].finish);
    }

    printf("\nMaximum number of compatible activities = %d\n",
           selectedCount);

    printf("CPU Time (sorting + selection, average of %d runs) = %.9f seconds\n",
           repetitions,
           cpuTime);

    free(activities);
    free(selected);

    return 0;
}
