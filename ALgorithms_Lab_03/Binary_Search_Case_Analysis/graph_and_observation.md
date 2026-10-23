# Binary Search — Detailed Graph Guide

## Graph Title

**Graph showing Input Size (N) vs CPU Time for Binary Search**

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

Select the scale based on your actual measured values.

Do not copy a CPU-time scale from another computer.

## Plot

Plot:

- Best Case
- Average Case
- Worst Case

using the actual observation-table values.

## Expected Theoretical Behavior

```text
Best     → O(1)
Average  → O(log N)
Worst    → O(log N)
```

## Why Curves May Overlap

Binary Search is extremely fast.

For many practical input sizes, the difference in CPU time can be smaller than the timing resolution or measurement noise.

Therefore, the graph may show three curves that almost overlap.

This is acceptable if the observation table contains valid measurements.

## Optional Better Experimental Method

If the curves are too close to observe:

1. Increase the repetition count.
2. Keep the timed section limited to the search function.
3. Divide total measured time by the number of repetitions.
4. Use the same number of repetitions for every `N`.
5. Repeat each measurement several times and use the average.

This improves experimental visibility without changing the algorithm.







# Binary Search — Observation Table

Record actual CPU times from the program.

| S. No. | N | Best Case (s) | Average Case (s) | Worst Case (s) |
|---:|---:|---:|---:|---:|
| 1 | 100 | ______ | ______ | ______ |
| 2 | 500 | ______ | ______ | ______ |
| 3 | 1000 | ______ | ______ | ______ |
| 4 | 2000 | ______ | ______ | ______ |
| 5 | 5000 | ______ | ______ | ______ |
| 6 | 10000 | ______ | ______ | ______ |

## Expected Observation

The measured CPU times should generally increase much more slowly than Linear Search.

However, for small input sizes, the measured values may:

- Be identical,
- Be extremely small,
- Appear noisy,
- Or even appear as `0.000000000`.

This is normal because the actual Binary Search operation is very fast and the timer has finite resolution.

## Theoretical Comparison

| Case | Work | Complexity |
|---|---|---|
| Best | 1 comparison | O(1) |
| Average | Logarithmic number of comparisons | O(log N) |
| Worst | Logarithmic number of comparisons | O(log N) |
