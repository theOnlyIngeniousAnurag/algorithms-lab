# Lab 03 — Best, Average & Worst Case Analysis of Searching Algorithms

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

## 🎯 Aim

To implement Linear Search and Binary Search and experimentally study their **best-case, average-case, and worst-case performance**, along with their time and space complexity.

The experiments include sample output, observation tables, and detailed graphing instructions for comparing experimental results with theoretical complexity.

---

## 📌 Experiments

### Experiment 1 — Linear Search Analysis

Implement Linear Search and determine/observe its:

- Best-case performance
- Average-case performance
- Worst-case performance
- CPU execution time
- Time complexity
- Space complexity

The practical includes an observation table and a graph comparing the three cases.

### Experiment 2 — Binary Search Analysis

Implement Binary Search on a sorted array and determine/observe its:

- Best-case performance
- Average-case performance
- Worst-case performance
- CPU execution time
- Time complexity
- Space complexity

The practical includes an observation table and a graph comparing the three cases.

---

## 📂 Folder Structure

```text
Lab-03/
│
├── README.md
│
├── Linear_Search_Case_Analysis/
│   ├── linear_search_cases.c
│   ├── explanation.md
│   ├── observation.md
│   └── graph_guide.md
│
└── Binary_Search_Case_Analysis/
    ├── binary_search_cases.c
    ├── explanation.md
    ├── observation.md
    └── graph_guide.md
```

---

# 🔎 Theoretical Summary

## Linear Search

| Case | Number of Comparisons | Time Complexity |
|---|---:|---|
| Best | 1 | O(1) |
| Average | Approximately (N + 1) / 2 for successful uniform-position search | O(N) |
| Worst | N | O(N) |

Auxiliary space:

```text
O(1)
```

The input array itself requires O(N) storage.

---

## Binary Search

| Case | Number of Comparisons / Search Steps | Time Complexity |
|---|---:|---|
| Best | 1 | O(1) |
| Average | Logarithmic | O(log N) |
| Worst | Logarithmic | O(log N) |

Auxiliary space for the iterative implementation:

```text
O(1)
```

The sorted input array itself requires O(N) storage.

---

# 📊 Experimental Analysis

The programs measure CPU time using:

```c
clock()
```

and:

```c
CLOCKS_PER_SEC
```

The measured time should be recorded for multiple values of `N`.

> **Important:** CPU-time measurements are machine-dependent. They should be taken from the actual execution environment and should not be presented as universal theoretical values.

For very small inputs, the measured CPU time may be zero or extremely small because of timer resolution and measurement overhead. In that situation, increasing the number of repeated searches inside the timed section can produce more stable measurements.

---

# 📈 Graphs

Two separate graphs are required.

### Graph 1 — Linear Search

**Title:**

```text
Input Size (N) vs CPU Time for Linear Search
```

**X-axis:**

```text
Input Size (N)
```

Suggested scale:

```text
1 major division = 1000 elements
```

**Y-axis:**

```text
CPU Time (seconds)
```

Choose the scale according to the actual measured values.

Plot:

- Best Case
- Average Case
- Worst Case

Expected theoretical behavior:

```text
Best     → O(1)
Average  → O(N)
Worst    → O(N)
```

### Graph 2 — Binary Search

**Title:**

```text
Input Size (N) vs CPU Time for Binary Search
```

**X-axis:**

```text
Input Size (N)
```

Suggested scale:

```text
1 major division = 1000 elements
```

**Y-axis:**

```text
CPU Time (seconds)
```

Choose the scale according to the actual measurements.

Expected theoretical behavior:

```text
Best     → O(1)
Average  → O(log N)
Worst    → O(log N)
```

---

# ⚠️ Important Difference Between Theory and CPU Graphs

The theoretical complexity describes how the **amount of algorithmic work grows**.

CPU time is an actual measurement and may be affected by:

- Operating-system scheduling
- Background applications
- CPU frequency
- Compiler settings
- Cache behavior
- Timer resolution
- Function-call and measurement overhead

Therefore, a CPU-time graph may not perfectly resemble an ideal mathematical complexity curve, especially for small input sizes.

---

## 📝 Result

Linear Search and Binary Search were implemented successfully, and their best-case, average-case, and worst-case behavior was studied using theoretical analysis and experimental CPU-time measurements.

The experiments demonstrate:

```text
Linear Search:
Best     → O(1)
Average  → O(N)
Worst    → O(N)

Binary Search:
Best     → O(1)
Average  → O(log N)
Worst    → O(log N)
```
