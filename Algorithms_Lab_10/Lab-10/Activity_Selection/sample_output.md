# Activity Selection — Sample Output

### Sample Input

```text
Enter number of activities: 6

Enter start and finish time for each activity:
Activity 1: 1 2
Activity 2: 3 4
Activity 3: 0 6
Activity 4: 5 7
Activity 5: 8 9
Activity 6: 5 9
```

### Expected Output

```text
Activities sorted by finish time:
Activity        Start   Finish
1               1       2
2               3       4
3               0       6
4               5       7
6               5       9
5               8       9

Selected Activities:
Activity 1: (1, 2)
Activity 2: (3, 4)
Activity 4: (5, 7)
Activity 5: (8, 9)

Maximum number of compatible activities = 4

CPU Time (sorting + selection, average of 100 runs) = 0.00XXXXXXX seconds
```

The exact CPU-time value depends on the computer and compiler.

The selected activities should be:

```text
Activity 1 → (1,2)
Activity 2 → (3,4)
Activity 4 → (5,7)
Activity 5 → (8,9)
```

Maximum:

```text
4 activities
```
