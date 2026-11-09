# Merge Sort — Detailed Graph Guide

## 1. Graph Title

**Graph showing Input Size (N) vs CPU Time for Merge Sort**

---

## 2. X-axis

Write:

```text
Input Size (N)
```

Use:

```text
1 major division = 1000 elements
```

For the suggested table:

```text
0
1000
2000
3000
...
10000
```

---

## 3. Y-axis

Write:

```text
CPU Time (seconds)
```

Do **not** choose the y-axis scale before obtaining the actual measurements.

Find the largest measured CPU time and select a clean scale that comfortably includes it.

For example, if the largest observed value is around `0.020 s`, a scale such as:

```text
1 major division = 0.005 seconds
```

may be suitable.

If your machine produces larger values, choose a larger scale.

---

## 4. Plot Three Curves

Plot:

1. Best Case
2. Average Case
3. Worst Case

Use the exact measured values from `observation.md`.

---

## 5. Expected Shape

All three cases should show approximately the same asymptotic trend:

```text
O(n log n)
```

Therefore the curves should generally rise faster than a straight line but much more slowly than a quadratic curve.

A conceptual comparison is:

```text
O(n)       → linear
O(n log n) → Merge Sort
O(n²)      → quadratic
```

---

## 6. Important Experimental Point

Do not expect the three curves to be perfectly identical.

For small input sizes, the measured values may:

- overlap,
- cross each other,
- fluctuate slightly,
- contain very small timing differences.

This is normal because CPU timing is affected by the execution environment.

The important conclusion is that **all three cases have the same theoretical asymptotic complexity**.

---

## 7. Graph Interpretation

Write below the graph:

> The graph shows that the CPU execution time of Merge Sort increases with input size. The best, average and worst cases exhibit approximately similar growth because Merge Sort has O(n log n) time complexity in all three cases. Minor variations in measured CPU time are caused by system and execution conditions.

---

## 8. Optional Theoretical Reference Curve

If your faculty asks for a theoretical curve rather than only experimental CPU measurements, a normalized `n log₂n` reference may be plotted separately.

Do not mix normalized theoretical values with actual CPU-time measurements unless the axes and labels clearly distinguish them.



## Theoretical Complexity

| Case | Input | Time Complexity |
|---|---|---|
| Best | Already sorted | O(n log n) |
| Average | Random | O(n log n) |
| Worst | Reverse sorted | O(n log n) |

## Observation

The three curves are expected to remain relatively close because the asymptotic time complexity of Merge Sort is `O(n log n)` in all three cases.

Small differences in measured CPU time are normal and do not change the theoretical complexity.



# Merge Sort — Sample Output

The program generates the test arrays automatically. The following shows the expected output format.

```text
Enter number of elements: 1000

Input Size = 1000
Repetitions per measurement = 100

Best Case - Before Sorting (first 10): 0 1 2 3 4 5 6 7 8 9
Best Case - After Sorting  (first 10): 0 1 2 3 4 5 6 7 8 9
CPU Time = 0.00XXXXXXX seconds

Average Case - Before Sorting (first 10): 483 17 921 204 76 615 39 801 12 554 ...
Average Case - After Sorting  (first 10): 0 1 2 3 4 5 6 7 8 9 ...
CPU Time = 0.00XXXXXXX seconds

Worst Case - Before Sorting (first 10): 1000 999 998 997 996 995 994 993 992 991 ...
Worst Case - After Sorting  (first 10): 1 2 3 4 5 6 7 8 9 10 ...
CPU Time = 0.00XXXXXXX seconds
```

`XXXXXXX` represents machine-dependent timing digits.

