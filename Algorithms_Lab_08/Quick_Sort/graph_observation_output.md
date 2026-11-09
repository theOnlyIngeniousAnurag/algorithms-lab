# Quick Sort — Detailed Graph Guide

## 1. Graph Title

**Graph showing Input Size (N) vs CPU Time for Quick Sort**

---

## 2. X-axis

Write:

```text
Input Size (N)
```

Recommended scale:

```text
1 major division = 1000 elements
```

Mark:

```text
0, 1000, 2000, ..., 10000
```

---

## 3. Y-axis

Write:

```text
CPU Time (seconds)
```

Choose the scale only after recording actual CPU timings.

For example, if your largest observed value is around `0.05 s`, you might choose:

```text
1 major division = 0.01 seconds
```

But use a different scale if your actual machine produces different values.

---

## 4. Plot

Plot three curves:

```text
Best Case
Average Case
Worst Case
```

Use the exact measurements from `observation.md`.

---

## 5. Expected Theoretical Behavior

```text
Best     → O(n log n)
Average  → O(n log n)
Worst    → O(n²)
```

Conceptually:

```text
CPU Time
   │
   │                         Worst O(n²)
   │                       /
   │                    __/
   │                 __/
   │        Best/Average
   │       __/
   │    __/
   │___/____________________________ Input Size
```

The drawing above is only a conceptual guide, not experimental data.

---

## 6. Why the Worst Curve Can Become Steeper

For the first-element pivot:

```text
Sorted input:

1 2 3 4 5 6 7
^
pivot
```

The pivot creates:

```text
0 elements | pivot | 6 elements
```

Then the next recursive call creates:

```text
0 elements | pivot | 5 elements
```

This produces approximately:

```text
n + (n-1) + (n-2) + ... + 1
```

operations, which is:

```text
O(n²)
```

---

## 7. Important Graphing Rule

Do not force the measured curves to look exactly like the theoretical curves.

Real CPU measurements can:

- overlap,
- fluctuate,
- cross,
- show small irregularities.

Theoretical complexity describes the **growth rate for large n**, not the exact CPU time of every individual run.

---

## 8. Interpretation to Write Below the Graph

> The graph shows that Quick Sort generally performs efficiently for balanced and average inputs, with approximately O(n log n) growth. For the first-element pivot implementation, sorted input produces highly unbalanced partitions and demonstrates the O(n²) worst-case behavior. Minor variations in measured CPU time are caused by execution-system conditions.

---

## 9. Optional Theoretical Comparison

If the faculty asks for theoretical curves, keep them separate from measured CPU time.

You may use normalized functions:

```text
n log₂(n)
n²
```

and clearly label them as:

```text
Theoretical / Normalized
```

Do not present normalized values as actual CPU measurements.

## Theoretical Complexity

| Case | Input Arrangement | Time Complexity |
|---|---|---|
| Best | Approximately balanced partitions | O(n log n) |
| Average | Random/typical input | O(n log n) |
| Worst | Highly unbalanced partitions | O(n²) |

## Observation

The best and average cases should generally grow close to `O(n log n)`.

For this implementation, sorted input is deliberately used for the worst case because the first element is always selected as the pivot.

Therefore, the worst-case curve can grow substantially faster as the input size increases.




# Quick Sort — Sample Output

The program generates the test arrays automatically.

### Expected Output Format

```text
Enter number of elements: 1000

Input Size = 1000
Repetitions per measurement = 100

Best Case - Before Sorting (first 10): 499 249 124 62 31 15 7 3 1 0 ...
Best Case - After Sorting  (first 10): 0 1 2 3 4 5 6 7 8 9 ...
CPU Time = 0.00XXXXXXX seconds

Average Case - Before Sorting (first 10): 482 17 921 204 76 615 39 801 12 554 ...
Average Case - After Sorting  (first 10): 0 1 2 3 4 5 6 7 8 9 ...
CPU Time = 0.00XXXXXXX seconds

Worst Case - Before Sorting (first 10): 0 1 2 3 4 5 6 7 8 9 ...
Worst Case - After Sorting  (first 10): 0 1 2 3 4 5 6 7 8 9 ...
CPU Time = 0.00XXXXXXX seconds
```

The exact random values and CPU timings depend on the execution environment.

**Do not copy the illustrative CPU values into the observation table. Record actual values from your own execution.**


