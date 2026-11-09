# Lab 07 — Merge Sort

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

## 🎯 Aim

To implement **Merge Sort** and analyze its time and space complexity for different input sizes.

---

## 📌 Experiment

### Merge Sort — Logic, Implementation and Time Complexity Analysis

The experiment covers:

- Divide-and-conquer strategy
- Splitting an array into smaller subarrays
- Recursive sorting
- Merging two sorted portions
- Best, average and worst cases
- CPU execution-time measurement
- Recurrence relation
- Time and space complexity
- Observation table
- Detailed graph
- Practical versus theoretical analysis

---

## 🧠 What Merge Sort Does

Merge Sort repeatedly divides an array into smaller parts until every part contains one element.

Then it merges the small sorted parts back together in sorted order.

The basic idea is:

```text
Divide → Sort → Merge
```

For example:

```text
[38 12 27 43 9 31 18 25]

             ↓ divide

[38 12 27 43]     [9 31 18 25]

       ↓                 ↓

[12 27 38 43]     [9 18 25 31]

             ↓ merge

[9 12 18 25 27 31 38 43]
```

---

## 📂 Folder Structure

```text
Lab-07/
│
├── README.md
│
└── Merge_Sort/
    ├── merge_sort.c
    ├── explanation.md
    ├── sample_output.md
    ├── observation.md
    └── graph_guide.md
```

---

# 📈 Complexity Summary

| Case | Time Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

Auxiliary space:

```text
O(n)
```

The standard top-down Merge Sort needs temporary storage during merging.

---

# 📊 Experimental Analysis

The program measures CPU time for:

- Best case → already sorted input
- Average case → randomly arranged input
- Worst case → reverse-sorted input

The same Merge Sort algorithm is used for all three cases.

Unlike algorithms whose behavior changes substantially with input ordering, Merge Sort keeps the same asymptotic time complexity for all three cases.

---

# 📋 Observation Table

Suggested input sizes:

```text
100
500
1000
2000
5000
10000
```

Record actual CPU times obtained from your system in:

```text
observation.md
```

Do not use fabricated measurements.

---

# 📈 Graph

### Title

```text
Graph showing Input Size (N) vs CPU Time for Merge Sort
```

### X-axis

```text
Input Size (N)
```

Recommended:

```text
1 major division = 1000 elements
```

### Y-axis

```text
CPU Time (seconds)
```

Select the scale after obtaining actual measurements.

### Curves

Plot:

- Best Case
- Average Case
- Worst Case

All three should show approximately:

```text
O(n log n)
```

The three measured curves may overlap or differ slightly because of operating-system scheduling, compiler settings, cache effects and other system conditions.

---

# 📝 Result

Merge Sort was successfully implemented using the divide-and-conquer technique. The experimental analysis is expected to confirm `O(n log n)` time complexity for best, average and worst cases, with `O(n)` auxiliary space for the standard implementation.
