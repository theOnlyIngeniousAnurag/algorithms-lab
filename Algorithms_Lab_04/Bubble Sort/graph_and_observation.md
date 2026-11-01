# Bubble Sort — Detailed Graph Guide

## Graph Title

**Graph showing Input Size (N) vs CPU Time for Bubble Sort**

## X-axis

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

## Y-axis

```text
CPU Time (seconds)
```

Choose the Y-axis scale after checking your largest actual value.

Do not use an arbitrary fixed scale that makes all small values invisible.

## Curves

Plot:

1. Best Case
2. Average Case
3. Worst Case

## Expected Shape

```text
Best     → approximately linear
Average  → quadratic
Worst    → quadratic
```

The average and worst curves should rise much more steeply than the best-case curve.

## Interpretation

The graph is an **experimental CPU-time graph**.

The theoretical statements:

```text
Best = O(n)
Average = O(n²)
Worst = O(n²)
```

describe asymptotic growth and should be written below/alongside the graph.

Do not claim that the measured points must exactly form perfect mathematical curves.





# Bubble Sort — Observation Table

Record the actual values obtained by running the program for each input size.

| S. No. | N | Best Case (s) | Average Case (s) | Worst Case (s) |
|---:|---:|---:|---:|---:|
| 1 | 100 | ______ | ______ | ______ |
| 2 | 500 | ______ | ______ | ______ |
| 3 | 1000 | ______ | ______ | ______ |
| 4 | 2000 | ______ | ______ | ______ |
| 5 | 5000 | ______ | ______ | ______ |
| 6 | 10000 | ______ | ______ | ______ |

## Theoretical Complexity Table

| Case | Input Arrangement | Complexity |
|---|---|---|
| Best | Already sorted | O(n) |
| Average | Random order | O(n²) |
| Worst | Reverse sorted | O(n²) |

## Expected Observation

- Best-case execution grows slowly.
- Average and worst cases grow much faster.
- Worst-case CPU time is generally highest for sufficiently large `N`.
- Small measurements may fluctuate due to system effects.
