# Lab 08 — Quick Sort

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

## 🎯 Aim

To implement **Quick Sort** using the divide-and-conquer technique and analyze its execution time for best, average and worst cases.

---

## 📌 Experiment

### Quick Sort — Logic, Implementation and Time Complexity Analysis

The experiment covers:

- Divide-and-conquer strategy
- Pivot selection
- Partitioning
- Recursive sorting
- Best, average and worst cases
- CPU execution-time measurement
- Recurrence relations
- Time and space complexity
- Practical behavior of Quick Sort
- Observation table
- Detailed graph

---

## 🧠 What Quick Sort Does

Quick Sort selects one element as a **pivot** and rearranges the array so that:

```text
Elements smaller than pivot | Pivot | Elements larger than pivot
```

The two resulting parts are then sorted recursively.

Basic idea:

```text
Choose Pivot
     ↓
Partition
     ↓
Sort Left Part
     ↓
Sort Right Part
```

This is a divide-and-conquer algorithm.

---

## 📂 Folder Structure

```text
Lab-08/
│
├── README.md
│
└── Quick_Sort/
    ├── quick_sort.c
    ├── explanation.md
    ├── sample_output.md
    ├── observation.md
    └── graph_guide.md
```

---

# 📈 Complexity Summary

For the first-element pivot implementation used in this lab:

| Case | Time Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n²) |

The recursive auxiliary stack is:

| Case | Auxiliary Space |
|---|---|
| Best / Average | O(log n) expected |
| Worst | O(n) |

The algorithm sorts the array in place apart from recursion stack and temporary variables.

---

# 📊 Experimental Analysis

The program measures CPU time for:

- **Best case:** an input arrangement designed to give relatively balanced partitions.
- **Average case:** random input.
- **Worst case:** sorted input for the first-element pivot.

### Important

The implementation deliberately uses the **first element as the pivot**.

Therefore, an already sorted or reverse-sorted array can produce highly unbalanced partitions and demonstrate the worst-case behavior.

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

Record the actual CPU times obtained from your execution.

Do not use fabricated CPU measurements.

---

# 📈 Graph

### Title

```text
Graph showing Input Size (N) vs CPU Time for Quick Sort
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

Choose the scale after recording the actual measurements.

### Curves

Plot:

- Best Case
- Average Case
- Worst Case

Expected theoretical behavior:

```text
Best     → O(n log n)
Average  → O(n log n)
Worst    → O(n²)
```

The worst-case curve may rise much more rapidly as `N` increases.

---

# 📝 Result

Quick Sort was successfully implemented using the divide-and-conquer technique. The experimental analysis is expected to show approximately `O(n log n)` behavior for balanced/average inputs and `O(n²)` behavior when the first-element pivot repeatedly produces highly unbalanced partitions.
