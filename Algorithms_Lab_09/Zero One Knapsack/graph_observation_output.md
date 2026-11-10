# 0/1 Knapsack — Detailed Graph Guide

## 1. Main Graph

### Title

**Graph showing Number of Items (N) vs CPU Time for 0/1 Knapsack**

### X-axis

```text
Number of Items (N)
```

Recommended:

```text
1 major division = 1000 items
```

### Y-axis

```text
CPU Time (seconds)
```

Choose the scale after obtaining actual timings.

---

## 2. Controlled Experiment

Use:

```text
W = 1000
```

for every row in the main observation table.

Plot:

```text
N vs CPU Time
```

Because:

```text
Time = O(nW)
```

and `W` is fixed:

```text
O(nW) = O(n)
```

with respect to `N`.

Therefore, the main graph may look approximately linear.

This does **not** mean that 0/1 Knapsack has overall `O(n)` complexity.

---

## 3. Capacity Graph

For a stronger demonstration of the actual `O(nW)` dependence, create a second graph if your faculty permits.

Keep:

```text
N = 1000
```

and vary:

```text
W = 100, 500, 1000, 2000, 5000, 10000
```

Plot:

```text
Capacity (W) vs CPU Time
```

The expected growth is approximately linear with `W` when `N` is fixed.

---

## 4. Why Two Graphs Are Better

The complexity contains two variables:

```text
O(nW)
```

A single graph cannot independently demonstrate both variables.

Therefore:

### Graph 1

```text
N vs CPU Time
```

with fixed `W`.

### Graph 2

```text
W vs CPU Time
```

with fixed `N`.

This is a more academically correct experimental demonstration.

---

## 5. Interpretation

Write below the main graph:

> The graph shows that the execution time increases with the number of items when the knapsack capacity is kept fixed. Since the Dynamic Programming solution has O(nW) complexity, fixing W makes the observed dependence on n approximately linear.

For the second graph:

> The graph shows that execution time increases with capacity when the number of items is fixed. This demonstrates the dependence of the Dynamic Programming solution on W, resulting in O(nW) overall time complexity.

---

## 6. Important Note

Do not plot `n × W` as if it were measured CPU time.

The experimental graph must use actual CPU-time observations.

If theoretical curves are required, label them separately as:

```text
Normalized theoretical O(nW)
```
