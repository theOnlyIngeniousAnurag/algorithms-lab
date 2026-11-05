# Insertion Sort Using Doubly Linked List — Detailed Graph Guide

## Graph Title

**Graph showing Input Size (N) vs CPU Time for Insertion Sort Using Doubly Linked List**

## X-axis

```text
Input Size (N)
```

Recommended:

```text
1 major division = 1000 elements
```

Mark:

```text
0, 1000, 2000, ..., 10000
```

## Y-axis

```text
CPU Time (seconds)
```

Choose the scale after recording the actual measurements.

Do not assume that a CPU-time scale from another system will work on your computer.

## Curves

Plot:

- Best Case
- Average Case
- Worst Case

## Expected Shape

```text
Best     → approximately linear
Average  → approximately quadratic
Worst    → approximately quadratic
```

## Interpretation

The best case occurs when the linked list is already sorted, so each key requires only minimal checking.

For random and reverse-sorted input, the number of shifts grows quadratically.

## Important

The graph should contain the **actual experimental points**.

Do not replace measured values with ideal mathematical values.

Theoretical complexity should be stated separately:

```text
Best = O(n)
Average = O(n²)
Worst = O(n²)
```

# Insertion Sort Using Doubly Linked List — Observation Table

Record actual CPU times obtained by executing the program.

| S. No. | N | Best Case (s) | Average Case (s) | Worst Case (s) |
|---:|---:|---:|---:|---:|
| 1 | 100 | ______ | ______ | ______ |
| 2 | 500 | ______ | ______ | ______ |
| 3 | 1000 | ______ | ______ | ______ |
| 4 | 2000 | ______ | ______ | ______ |
| 5 | 5000 | ______ | ______ | ______ |
| 6 | 10000 | ______ | ______ | ______ |

## Theoretical Comparison

| Case | Input Arrangement | Complexity |
|---|---|---|
| Best | Sorted | O(n) |
| Average | Random | O(n²) |
| Worst | Reverse sorted | O(n²) |

## Expected Observation

- Best case should grow approximately linearly.
- Average and worst cases should grow approximately quadratically.
- Worst case is expected to be the most expensive for sufficiently large `N`.
- Exact CPU times may fluctuate because of system conditions.






# Insertion Sort Using Doubly Linked List — Sample Output

### Sample Run

```text
Enter number of elements: 1000

Input Size = 1000
Repetitions per measurement = 100

Best Case (sorted linked list):
CPU Time = 0.00XXXXXX seconds

Average Case (random linked list):
CPU Time = 0.00XXXXXX seconds

Worst Case (reverse-sorted linked list):
CPU Time = 0.00XXXXXX seconds

Demonstration:
Before sorting: 5 3 4 1 2
After sorting:  1 2 3 4 5
```

The CPU-time values are illustrative output formatting only. Actual values must be recorded from the execution environment.
