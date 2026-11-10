# Fractional Knapsack — Detailed Graph Guide

## Graph Title

**Graph showing Number of Items (N) vs CPU Time for Fractional Knapsack**

## X-axis

```text
Number of Items (N)
```

Recommended:

```text
1 major division = 1000 items
```

Mark:

```text
0, 1000, 2000, ..., 10000
```

## Y-axis

```text
CPU Time (seconds)
```

Choose the scale only after recording actual timings.

## Plot

Use the CPU-time values from `observation.md`.

There is one main curve:

```text
CPU Time vs Number of Items
```

## Expected Behavior

Because this lab implementation uses Bubble Sort:

```text
Current implementation → O(n²)
```

Therefore, the experimental curve should generally become steeper as `N` increases.

If the program is later changed to use Merge Sort or an efficient library sort:

```text
Expected sorting-dominated complexity → O(n log n)
```

## Interpretation

> The graph shows that execution time increases with the number of items. The current implementation uses Bubble Sort to order items by profit-to-weight ratio, so the dominant time complexity is O(n²). The greedy selection itself requires only O(n) time after sorting.

## Important

Do not plot theoretical `n²` values as actual CPU seconds.

If a normalized theoretical curve is required, label it clearly as:

```text
Normalized theoretical O(n²)
```

## Theoretical Analysis

Current implementation:

```text
Ratio calculation = O(n)
Bubble Sort       = O(n²)
Selection         = O(n)

Overall            = O(n²)
```

With an efficient comparison sort:

```text
Overall = O(n log n)
```

## Observation

The measured CPU time should generally increase as the number of items increases. Since this particular implementation uses Bubble Sort, its experimental growth is expected to be closer to quadratic than to the optimal `O(n log n)` greedy implementation.



# Fractional Knapsack — Sample Output

### Sample Input

```text
Enter number of items: 3
Enter knapsack capacity: 50

Enter weight and profit of each item:
Item 1: 10 60
Item 2: 20 100
Item 3: 30 120
```

### Sample Output

```text
Items sorted by profit/weight ratio:
Item    Weight  Profit  Ratio
1       10      60      6.00
2       20      100     5.00
3       30      120     4.00

Maximum Profit = 240.00
```

The final 20 units of capacity are filled using:

```text
20/30 = 2/3
```

of Item 3.

Therefore:

```text
Maximum Profit = 60 + 100 + (120 × 2/3)
               = 240
```



