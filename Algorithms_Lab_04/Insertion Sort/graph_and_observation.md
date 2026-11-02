# Insertion Sort — Detailed Graph Guide

## Graph Title

**Graph showing Input Size (N) vs CPU Time for Insertion Sort**

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

Choose the scale from the actual measurements.

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

The worst-case curve should generally be the steepest for sufficiently large `N`.

## Interpretation

The best case is linear because a sorted input requires only minimal movement.

The average and worst cases are quadratic because elements may need to be shifted across the sorted prefix.

## Practical Comparison

Compared with Bubble Sort, Insertion Sort is usually much better for nearly sorted data because it only moves elements when necessary.





# Insertion Sort — Observation Table

Record the actual values obtained from the program.

| S. No. | N | Best Case (s) | Average Case (s) | Worst Case (s) |
|---:|---:|---:|---:|---:|
| 1 | 100 | ______ | ______ | ______ |
| 2 | 500 | ______ | ______ | ______ |
| 3 | 1000 | ______ | ______ | ______ |
| 4 | 2000 | ______ | ______ | ______ |
| 5 | 5000 | ______ | ______ | ______ |
| 6 | 10000 | ______ | ______ | ______ |

## Theoretical Complexity

| Case | Input Arrangement | Complexity |
|---|---|---|
| Best | Already sorted | O(n) |
| Average | Random order | O(n²) |
| Worst | Reverse sorted | O(n²) |

## Expected Observation

- Best-case time increases approximately linearly.
- Average and worst-case time increase approximately quadratically.
- Insertion Sort should perform particularly well for nearly sorted data.





# Insertion Sort — Sample Output

The program automatically creates best-, average-, and worst-case inputs.

### Sample Run

```text
Enter number of elements: 1000

Input Size = 1000
Repetitions per measurement = 100

Best Case (sorted input):
CPU Time = 0.00000XXX seconds

Average Case (random input):
CPU Time = 0.00XXXXXX seconds

Worst Case (reverse-sorted input):
CPU Time = 0.00XXXXXX seconds
```

The exact CPU values depend on the machine and should be obtained by running the program.
