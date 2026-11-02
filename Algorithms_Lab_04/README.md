# Lab 04 — Bubble Sort & Insertion Sort

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

## 🎯 Aim

To understand, implement, and experimentally analyze **Bubble Sort** and **Insertion Sort**, including their best-case, average-case, and worst-case time complexities.

The experiments also include CPU-time measurement, observation tables, sample outputs, and detailed graphing guidance.

---

## 📌 Experiments

### Experiment 1 — Bubble Sort

Study:

- Bubble Sort logic
- Pass-by-pass working
- Adjacent comparison and swapping
- Early termination optimization
- Best, average, and worst cases
- Stability
- In-place sorting
- Time and space complexity
- Practical performance considerations

### Experiment 2 — Bubble Sort Implementation & Analysis

Implement Bubble Sort in C and:

- Sort an array
- Measure CPU execution time
- Analyze best, average, and worst cases
- Record observations for different input sizes
- Plot an input-size vs CPU-time graph

### Experiment 3 — Insertion Sort

Study:

- Insertion Sort logic
- Sorted-prefix concept
- Key selection
- Shifting elements
- Best, average, and worst cases
- Stability
- In-place sorting
- Adaptive behavior
- Time and space complexity
- Practical use cases

### Experiment 4 — Insertion Sort Implementation & Analysis

Implement Insertion Sort in C and:

- Sort an array
- Measure CPU execution time
- Analyze best, average, and worst cases
- Record observations for different input sizes
- Plot an input-size vs CPU-time graph

---

## 📂 Folder Structure

```text
Lab-04/
│
├── README.md
│
├── Bubble_Sort/
│   ├── bubble_sort.c
│   ├── explanation.md
│   ├── sample_output.md
│   ├── observation.md
│   └── graph_guide.md
│
└── Insertion_Sort/
    ├── insertion_sort.c
    ├── explanation.md
    ├── sample_output.md
    ├── observation.md
    └── graph_guide.md
```

---

# ⚡ Quick Comparison

| Feature | Bubble Sort | Insertion Sort |
|---|---|---|
| Basic idea | Swap adjacent out-of-order elements | Insert each element into sorted prefix |
| Best Case | O(n) with early-exit optimization | O(n) |
| Average Case | O(n²) | O(n²) |
| Worst Case | O(n²) | O(n²) |
| Auxiliary Space | O(1) | O(1) |
| In-place | Yes | Yes |
| Stable | Yes | Yes |
| Adaptive | Somewhat, with early exit | Yes |
| Good for nearly sorted data | Reasonable | **Very good** |
| Typical practical use | Mainly educational/small data | Small or nearly sorted data |

---

## 🧪 Experimental Method

Both programs use repeated executions while measuring only the sorting operation.

This is useful because a single sort of a small array may execute too quickly for reliable CPU-time observation.

The measured average CPU time is calculated as:

```text
Average measured CPU time
=
Total measured CPU time / Number of repetitions
```

The repetition count is kept the same for all input sizes.

> CPU measurements are machine-dependent. Actual values must be recorded from the execution environment.

---

# 📈 Graphing

For each algorithm, plot:

```text
X-axis → Input Size (N)
Y-axis → CPU Time (seconds)
```

Use three series:

- Best Case
- Average Case
- Worst Case

Suggested input sizes:

```text
100
500
1000
2000
5000
10000
```

Choose the Y-axis scale only after observing the actual CPU times.

---

## 📊 Theoretical Graph Behavior

### Bubble Sort

```text
Best     → O(n)      [with early-exit optimization]
Average  → O(n²)
Worst    → O(n²)
```

### Insertion Sort

```text
Best     → O(n)
Average  → O(n²)
Worst    → O(n²)
```

The experimental CPU graph may not exactly match the theoretical curves because of system and timer effects.

---

## ⚠️ Important Note About Complexity

For Bubble Sort, the **O(n) best case depends on using the early-exit optimization**.

Without the `swapped` flag, a basic implementation performs all passes even when the array is already sorted, resulting in O(n²) best-case time.

The implementation in this lab uses the optimization.

---

## 📝 Result

Bubble Sort and Insertion Sort were implemented successfully and their performance was analyzed experimentally.

Both have quadratic average and worst-case complexity, while their best cases can be linear. Insertion Sort is particularly effective for small or nearly sorted data.
