# Selection Sort — Detailed Graph Guide

## Graph Title

**Graph showing Input Size (N) vs CPU Time for Selection Sort**

## X-axis

```text
Input Size (N)
```

For the suggested observation values:

```text
100, 500, 1000, 2000, 5000, 10000
```

a convenient manual graph scale is:

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

Choose the scale after obtaining the actual measurements.

For example, if the largest observed value is around `0.40 s`, a possible manual scale is:

```text
1 major division = 0.05 seconds
```

But this is only an example. Use the actual maximum measured value to choose the final scale.

## Curves

Plot:

- Best Case
- Average Case
- Worst Case

## Expected Shape

All three curves should show approximately quadratic growth:

```text
Best     → O(n²)
Average  → O(n²)
Worst    → O(n²)
```

They may lie very close to each other.

## Why Are They Close?

Selection Sort performs:

```text
(n−1) + (n−2) + ... + 1
```

comparisons regardless of whether the input is already sorted, random, or reverse sorted.

Therefore the dominant comparison work is:

```text
n(n−1)/2
```

for all three cases.

## Important Graphing Rule

Plot the **actual measured points** from the observation table.

Do not invent a perfectly smooth curve and label it as measured CPU time.

Theoretical complexity should be written separately as:

```text
Best = O(n²)
Average = O(n²)
Worst = O(n²)
```


# Selection Sort — Observation Table

Record the actual CPU times obtained from the program.

| S. No. | N | Best Case (s) | Average Case (s) | Worst Case (s) |
|---:|---:|---:|---:|---:|
| 1 | 100 | ______ | ______ | ______ |
| 2 | 500 | ______ | ______ | ______ |
| 3 | 1000 | ______ | ______ | ______ |
| 4 | 2000 | ______ | ______ | ______ |
| 5 | 5000 | ______ | ______ | ______ |
| 6 | 10000 | ______ | ______ | ______ |

## Theoretical Comparison

| Case | Input Arrangement | Comparisons | Complexity |
|---|---|---:|---|
| Best | Already sorted | n(n−1)/2 | O(n²) |
| Average | Random | n(n−1)/2 | O(n²) |
| Worst | Reverse sorted | n(n−1)/2 | O(n²) |

## Expected Observation

The three CPU-time measurements should be reasonably close compared with algorithms whose behavior strongly depends on input order.

However, they will not necessarily be identical.

Small differences are expected because actual execution time depends on the system.



# Selection Sort — Sample Output

The program automatically creates three input arrangements.

### Sample Run

```text
Enter number of elements: 1000

Input Size = 1000
Repetitions per measurement = 100

Best Case (sorted input):
CPU Time = 0.00XXXXXX seconds

Average Case (random input):
CPU Time = 0.00XXXXXX seconds

Worst Case (reverse-sorted input):
CPU Time = 0.00XXXXXX seconds
```

> The CPU values above illustrate the output format only. Actual values must be recorded from the machine used for the laboratory experiment.

## Interpretation

Unlike Bubble Sort with early exit or Insertion Sort, Selection Sort does not become linear when the input is already sorted.

It still searches for the minimum in each remaining portion.

Therefore:

```text
Best     → O(n²)
Average  → O(n²)
Worst    → O(n²)
```
