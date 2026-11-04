# Lab 05 — Selection Sort

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

## 🎯 Aim

To understand and implement **Selection Sort** and experimentally analyze its CPU execution time and time/space complexity for different input sizes.

The experiment covers the working logic, algorithm, implementation, best/average/worst cases, sample output, observation table, and detailed graphing procedure.

---

## 📌 Experiment

### Selection Sort

Study and implement Selection Sort with:

- Detailed logic and working
- Step-by-step example
- Algorithm / pseudocode
- Best, average, and worst-case analysis
- Comparison-count analysis
- CPU execution-time measurement
- Time complexity
- Space complexity
- Stability and in-place properties
- Sample output
- Observation table
- Detailed graph
- Experimental vs theoretical analysis

---

## 📂 Folder Structure

```text
Lab-05/
│
├── README.md
│
└── Selection_Sort/
    ├── selection_sort.c
    ├── explanation.md
    ├── sample_output.md
    ├── observation.md
    └── graph_guide.md
```

---

# 🧠 Complexity Summary

Selection Sort repeatedly searches the unsorted portion for the minimum element and places it at the beginning of that portion.

### Time Complexity

| Case | Comparisons | Time Complexity |
|---|---:|---|
| Best | n(n−1)/2 | O(n²) |
| Average | n(n−1)/2 comparisons | O(n²) |
| Worst | n(n−1)/2 | O(n²) |

A key property of Selection Sort is that the **number of comparisons is essentially independent of the initial order of the input**.

The number of swaps can vary depending on implementation/input, but the standard implementation performs at most `n−1` swaps.

### Space Complexity

```text
Auxiliary Space = O(1)
```

because the array is sorted in place using a few temporary variables.

---

# 📊 Experimental Analysis

The program measures the CPU time for:

- Best case → already sorted input
- Average case → randomly generated input
- Worst case → reverse-sorted input

Because Selection Sort performs nearly the same comparison work regardless of input arrangement, the three CPU-time curves are expected to be relatively close.

Small differences are normal because actual CPU time is affected by:

- Operating-system scheduling
- Background applications
- CPU frequency
- Compiler settings
- Cache behavior
- Timer resolution
- Measurement overhead

---

# 📈 Graph

### Title

```text
Graph showing Input Size (N) vs CPU Time for Selection Sort
```

### X-axis

```text
Input Size (N)
```

Recommended scale:

```text
1 major division = 1000 elements
```

For the suggested values:

```text
100, 500, 1000, 2000, 5000, 10000
```

### Y-axis

```text
CPU Time (seconds)
```

Choose the Y-axis scale based on the largest actual measured value.

Do not copy a fixed CPU-time scale from another computer.

### Curves

Plot:

- Best Case
- Average Case
- Worst Case

### Expected behavior

All three curves should show approximately quadratic growth:

```text
Best     → O(n²)
Average  → O(n²)
Worst    → O(n²)
```

The curves may be close together or overlap.

This is expected and is one of the important observations of Selection Sort.

---

## ⚠️ Theoretical vs Experimental Result

The theoretical analysis says that Selection Sort performs approximately the same number of comparisons regardless of input order.

Therefore:

```text
Best ≈ Average ≈ Worst
```

in terms of asymptotic time complexity.

However, actual CPU measurements do not have to be identical.

---

## 📝 Result

Selection Sort was implemented successfully and its performance was analyzed for different input arrangements.

The experiment demonstrates that Selection Sort has **O(n²)** best-, average-, and worst-case time complexity and **O(1)** auxiliary space.
