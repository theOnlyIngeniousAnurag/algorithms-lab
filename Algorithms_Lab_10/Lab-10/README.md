# Lab 10 — Activity Selection

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

# 🎯 Aim

To implement the **Activity Selection Problem** using the Greedy method and analyze its time and space complexity.

---

# 📌 Experiment

The Activity Selection Problem is a classic **Greedy Algorithm** problem.

Given a set of activities, where every activity has:

- A start time
- A finish time

the objective is to select the **maximum number of mutually compatible activities** that can be performed by a single person/resource.

Two selected activities are compatible when:

```text
Start time of next activity >= finish time of previously selected activity
```

---

# 🧠 What the Algorithm Does

The algorithm follows the greedy rule:

> Always select the activity that finishes earliest among the remaining compatible activities.

Why?

An activity that finishes earlier leaves more time available for future activities.

Basic flow:

```text
Activities
    ↓
Sort by finish time
    ↓
Select first activity
    ↓
Find next compatible activity
    ↓
Repeat
```

---

# 📂 Folder Structure

```text
Lab-10/
│
├── README.md
│
└── Activity_Selection/
    ├── activity_selection.c
    ├── explanation.md
    ├── sample_output.md
    ├── observation.md
    └── graph_guide.md
```

---

# 📈 Complexity

The implementation first sorts activities by finish time using **Quick Sort**.

Therefore:

```text
Average sorting time = O(n log n)
Worst sorting time   = O(n²)
Selection step       = O(n)
```

Hence, for the implemented program:

```text
Average Time = O(n log n)
Worst Time   = O(n²)
```

The actual greedy selection itself is linear after sorting.

If an efficient guaranteed `O(n log n)` sorting algorithm is used, the complete Activity Selection solution can be `O(n log n)`.

---

# 🧠 Important Greedy Insight

The correct greedy criterion is:

```text
Earliest finish time
```

It is **not**:

```text
Earliest start time
Shortest duration
Highest duration
```

Choosing the earliest-finishing compatible activity leaves the largest possible remaining time for other activities.

---

# 📊 Experimental Analysis

The program measures CPU time for:

```text
Sorting + Greedy Selection
```

For a meaningful experiment:

- Use different input sizes.
- Keep the generation method consistent.
- Repeat the operation multiple times.
- Record actual CPU time.

CPU timings depend on the execution environment.

Do not replace measured values with theoretical values.

---

# 📋 Observation Table

Suggested values:

```text
100
500
1000
2000
5000
10000
```

Record actual measurements in:

```text
observation.md
```

---

# 📈 Graph

### Title

```text
Graph showing Number of Activities (N) vs CPU Time for Activity Selection
```

### X-axis

```text
Number of Activities (N)
```

Recommended:

```text
1 major division = 1000 activities
```

### Y-axis

```text
CPU Time (seconds)
```

Choose the scale after obtaining actual measurements.

### Expected behavior

The dominant operation is sorting:

```text
Average → O(n log n)
Worst   → O(n²)
```

The greedy selection itself is:

```text
O(n)
```

---

# 📝 Result

The Activity Selection Problem was successfully implemented using the Greedy method. Activities are sorted according to finish time and the maximum compatible set is selected. The experiment demonstrates that the greedy selection is linear after sorting, while the overall complexity depends on the sorting method used.
