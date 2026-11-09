# Linear Search — Detailed Graph Guide

## Graph Title

**Graph showing Input Size (N) vs CPU Time for Linear Search**

## X-axis

```text
Input Size (N)
```

Recommended scale for the suggested observation values:

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

Do **not** assume a universal Y-axis scale because CPU measurements depend on the computer.

First inspect the largest recorded CPU time and choose a scale that makes the points visible.

For example, if the maximum is around `0.001 s`, a possible scale is:

```text
1 major division = 0.0002 seconds
```

If the maximum is much smaller, use a smaller unit.

## Curves

Plot three curves:

```text
Best Case
Average Case
Worst Case
```

## Expected Shape

The best-case curve should be nearly flat.

Average and worst cases should show approximately linear growth.

```text
Best     → O(1)
Average  → O(N)
Worst    → O(N)
```

## Important

Do not draw a perfectly mathematical line and label it as measured CPU time.

Plot the **actual observation-table points** and then join them.

The graph is experimental; the complexity notation is theoretical.






# Linear Search — Observation Table

Record the **actual CPU times obtained from the program**.

| S. No. | N | Best Case (s) | Average Case (s) | Worst Case (s) |
|---:|---:|---:|---:|---:|
| 1 | 100 | ______ | ______ | ______ |
| 2 | 500 | ______ | ______ | ______ |
| 3 | 1000 | ______ | ______ | ______ |
| 4 | 2000 | ______ | ______ | ______ |
| 5 | 5000 | ______ | ______ | ______ |
| 6 | 10000 | ______ | ______ | ______ |

## Expected Observation

As `N` increases:

- Best case should remain relatively small because only the first element is checked.
- Average-case time should increase approximately linearly.
- Worst-case time should also increase approximately linearly.
- Average and worst cases may be close to each other depending on the machine and the input.

## Theoretical Comparison

| Case | Work | Complexity |
|---|---|---|
| Best | 1 comparison | O(1) |
| Average | ≈ (N+1)/2 comparisons | O(N) |
| Worst | N comparisons | O(N) |


