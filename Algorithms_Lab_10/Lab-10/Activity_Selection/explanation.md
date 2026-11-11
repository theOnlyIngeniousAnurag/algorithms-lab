# Activity Selection — Detailed Explanation

## 1. Problem Statement

The Activity Selection Problem is a classic **Greedy Algorithm** problem.

Suppose one person has a single room and several activities are requested.

Every activity has:

```text
Start Time
Finish Time
```

The objective is:

> Select the maximum number of non-overlapping activities.

Two activities are compatible when:

```text
Start of next activity >= Finish of previous activity
```

---

## 2. ELI10 Explanation

Imagine you have one classroom.

Many students want to use it:

```text
A → 9 to 10
B → 9 to 12
C → 10 to 11
D → 11 to 12
```

You want to schedule the maximum number of sessions.

The smart rule is:

> Choose the activity that finishes earliest.

Why?

Because finishing early leaves more time for future activities.

---

## 3. Greedy Strategy

The algorithm performs two major steps:

```text
1. Sort activities by finish time.
2. Repeatedly select the next compatible activity.
```

After selecting an activity:

```text
lastFinish = selected activity's finish time
```

An activity can then be selected only if:

```text
activity.start >= lastFinish
```

---

## 4. Example

Consider:

| Activity | Start | Finish |
|---|---:|---:|
| A1 | 1 | 2 |
| A2 | 3 | 4 |
| A3 | 0 | 6 |
| A4 | 5 | 7 |
| A5 | 8 | 9 |
| A6 | 5 | 9 |

Sort by finish time:

```text
A1 (1,2)
A2 (3,4)
A3 (0,6)
A4 (5,7)
A5 (8,9)
A6 (5,9)
```

Select:

```text
A1 → (1,2)
```

Next compatible:

```text
A2 → (3,4)
```

Next compatible:

```text
A4 → (5,7)
```

Next compatible:

```text
A5 → (8,9)
```

Final answer:

```text
A1, A2, A4, A5
```

Number of selected activities:

```text
4
```

---

## 5. Why Earliest Finish Time?

Suppose two compatible activities are available:

```text
A → finishes at 5
B → finishes at 8
```

Choosing A leaves:

```text
more time after 5
```

Choosing B leaves:

```text
less time after 8
```

Therefore, the earliest finishing activity gives the remaining schedule the maximum possible room.

This is the greedy-choice property.

---

## 6. Complete Algorithm

```text
Algorithm ACTIVITY_SELECTION

Input:
    n : integer (number of activities)
    A[0...n-1] : activities with start and finish times

Output:
    Maximum set of mutually compatible activities

Variables:
    i : integer
    lastFinish : integer
    selectedCount : integer

Steps:

1. Sort A[0...n-1] in ascending order of finish time.

2. If n = 0, stop.

3. Select A[0].

4. selectedCount ← 1.

5. lastFinish ← A[0].finish.

6. For i ← 1 to n-1 do

       If A[i].start >= lastFinish then
           Select A[i].
           selectedCount ← selectedCount + 1.
           lastFinish ← A[i].finish.
       End If

   End For

7. Display the selected activities.

8. Display selectedCount.

9. Stop.
```

---

## 7. Why Is This Greedy Algorithm Optimal?

The proof is based on an exchange argument.

Suppose the optimal schedule starts with some activity B.

Let A be the activity with the earliest finish time.

Because A finishes no later than B:

```text
finish(A) <= finish(B)
```

Replace B with A.

This replacement cannot reduce the number of activities that can be scheduled afterward because A leaves at least as much remaining time as B.

Therefore, there exists an optimal solution that starts with A.

The same reasoning can then be applied to the remaining activities.

Hence the greedy strategy is optimal.

---

## 8. Sorting Step

This implementation uses Quick Sort to arrange activities by finish time.

The program sorts according to:

```text
finish time
```

not start time.

The sorting is important because the greedy selection assumes activities are processed from earliest finish to latest finish.

---

## 9. Time Complexity

### Sorting

Quick Sort has:

```text
Average = O(n log n)
Worst   = O(n²)
```

### Greedy selection

The selection loop scans the activities once:

```text
O(n)
```

Therefore:

```text
Overall Average = O(n log n)
Overall Worst   = O(n²)
```

If a guaranteed `O(n log n)` sorting algorithm is used, the entire Activity Selection solution becomes:

```text
O(n log n)
```

---

## 10. Space Complexity

The greedy selection itself requires only a few variables:

```text
O(1)
```

The program also stores the activity array and selection indices:

```text
O(n)
```

Quick Sort additionally uses recursive stack space:

```text
Average = O(log n)
Worst   = O(n)
```

---

## 11. Important Properties

| Property | Activity Selection |
|---|---|
| Technique | Greedy |
| Greedy choice | Earliest finish time |
| Selection after sorting | O(n) |
| Current sorting | Quick Sort |
| Average overall | O(n log n) |
| Worst overall | O(n²) |
| Greedy optimal | Yes |
| Main objective | Maximum number of compatible activities |

---

## 12. What the Algorithm Is NOT Optimizing

Activity Selection maximizes:

```text
Number of activities
```

It does not necessarily maximize:

```text
Total duration
Total profit
Total weight
```

If every activity has a profit/value and the objective is to maximize total profit, that is a different scheduling problem.

---

## 13. Applications

The same idea appears in:

- Meeting-room scheduling
- Classroom scheduling
- CPU/resource scheduling
- Event scheduling
- Conference-room allocation
- Broadcast scheduling
- Machine/resource utilization

---

## 14. Difference from Weighted Activity Selection

### Activity Selection

Objective:

```text
Maximum number of non-overlapping activities
```

Greedy by earliest finish time works.

### Weighted Activity Selection

Each activity has a profit/value.

Objective:

```text
Maximum total profit
```

Simple earliest-finish greedy is not sufficient; Dynamic Programming is commonly used.

---

## 15. Important Implementation Note

The program measures:

```text
Sorting + Greedy Selection
```

rather than only the selection loop.

This is intentional because the sorting step is part of the complete implementation.

The theoretical complexity should therefore include the sorting complexity.

---

## 16. Why Activity IDs Are Preserved

The program stores an explicit `id` for every activity.

This is important because Quick Sort changes the order of activities.

For example, after sorting:

```text
Original Activity 5
```

may appear at array index `2`.

The ID allows the program to still report:

```text
Activity 5
```

rather than confusing the array index with the original activity number.
