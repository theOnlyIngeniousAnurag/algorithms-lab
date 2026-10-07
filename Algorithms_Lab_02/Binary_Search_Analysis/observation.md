# Binary Search — Observation & Graph Guide

## Observation Table

Record the CPU time obtained from the actual program execution.

| S. No. | N | Best Case (s) | Average Case (s) | Worst Case (s) |
|---:|---:|---:|---:|---:|
| 1 | 100 | ______ | ______ | ______ |
| 2 | 500 | ______ | ______ | ______ |
| 3 | 1000 | ______ | ______ | ______ |
| 4 | 2000 | ______ | ______ | ______ |
| 5 | 5000 | ______ | ______ | ______ |
| 6 | 10000 | ______ | ______ | ______ |

### How to Generate the Three Cases

For experimental analysis, use the same input size `N` and vary the key:

**Best case**

Choose the first middle element:

```text
key = a[(N - 1) / 2]
```

**Average case**

Use a set of representative keys and calculate the mean CPU time over repeated trials.

**Worst case**

Use a key that is absent from the array, such as a value outside the generated range.

> Exact CPU values should be recorded from the machine on which the program is executed. They should not be fabricated because CPU timing is system-dependent.

---

# Graph

## Graph Title

**Input Size (N) vs CPU Time for Binary Search**

## X-axis

**Input Size (N)**

Suggested scale:

```text
1 major division = 1000 elements
```

## Y-axis

**CPU Execution Time (seconds)**

Choose the scale after observing the largest measured value.

For example, if the values are in the microsecond range, a small scale such as:

```text
1 major division = 0.000001 seconds
```

may be appropriate.

If the values are larger, choose a larger scale.

## Plotting

Plot:

- Best Case
- Average Case
- Worst Case

using the actual observation-table values.

## Expected Interpretation

The best-case curve may remain very low because the key is found immediately.

Average and worst cases increase slowly as `N` increases.

The theoretical result is:

```text
Best Case    → O(1)
Average Case → O(log n)
Worst Case   → O(log n)
```

## Why a Graph May Look Almost Flat

For logarithmic algorithms, even a large increase in `N` causes only a small increase in the number of search steps.

For example:

```text
N = 1,000       → about 10 levels
N = 10,000      → about 14 levels
N = 1,000,000   → about 20 levels
```

Therefore, a CPU-time graph for Binary Search may look almost flat, especially when the timer resolution is limited.

That is expected and does **not** mean the algorithm is linear.
