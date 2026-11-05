# Lab 06 — Insertion Sort Using Doubly Linked List

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

## 🎯 Aim

To implement **Insertion Sort using a Doubly Linked List** and analyze its time and space complexity experimentally for different input sizes.

The experiment covers the linked-list structure, insertion-sort logic, node traversal, sorting approaches, CPU-time measurement, sample output, observation table, and detailed graphing.

---

## 📌 Experiment

### Insertion Sort Using Doubly Linked List

Study and implement:

- Doubly Linked List structure
- `prev` and `next` pointers
- Creating and displaying a doubly linked list
- Insertion Sort logic
- Sorting data stored in linked-list nodes
- Best, average, and worst cases
- CPU execution-time analysis
- Time complexity
- Space complexity
- Stability
- In-place vs auxiliary-memory considerations
- Sample output
- Observation table
- Detailed graph

---

## 📂 Folder Structure

```text
Lab-06/
│
├── README.md
│
└── Insertion_Sort_Doubly_Linked_List/
    ├── insertion_sort_dll.c
    ├── explanation.md
    ├── sample_output.md
    ├── observation.md
    └── graph_guide.md
```

---

# 🧠 Complexity Summary

For the implementation in this lab, the linked list is built first and the **node data values are shifted during sorting**.

| Case | Time Complexity |
|---|---|
| Best | O(n) |
| Average | O(n²) |
| Worst | O(n²) |

### Auxiliary Space

The sorting operation uses a constant number of pointer/temporary variables:

```text
O(1) auxiliary space
```

The doubly linked list itself requires:

```text
O(n)
```

memory for its nodes.

Therefore, the distinction is:

```text
Sorting auxiliary space → O(1)
Total storage for the linked list → O(n)
```

---

# 🔗 Why Use a Doubly Linked List?

A Doubly Linked List stores:

```text
data | prev | next
```

Each node points to:

- The previous node
- The next node

This allows movement in both directions.

For example:

```text
NULL ← [10] ⇄ [30] ⇄ [20] → NULL
```

---

# 📈 Experimental Analysis

The program measures CPU time for:

- Best case → already sorted linked-list data
- Average case → randomly generated linked-list data
- Worst case → reverse-sorted linked-list data

The sorting function is measured repeatedly to make very small CPU times more observable.

> CPU-time values are machine-dependent and should be recorded from the actual execution environment.

---

# 📊 Observation Table

Suggested input sizes:

```text
100
500
1000
2000
5000
10000
```

Record the actual CPU times in:

```text
Lab-06/Insertion_Sort_Doubly_Linked_List/observation.md
```

---

# 📈 Graph

### Title

```text
Graph showing Input Size (N) vs CPU Time for Insertion Sort Using Doubly Linked List
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

Choose the scale based on the largest actual measured value.

### Curves

Plot:

- Best Case
- Average Case
- Worst Case

Expected theoretical behavior:

```text
Best     → O(n)
Average  → O(n²)
Worst    → O(n²)
```

---

## ⚠️ Important Implementation Note

This program performs insertion sort by **shifting node data values**, rather than physically unlinking and relinking nodes.

For example:

```text
Before:
5 ⇄ 3 ⇄ 4

After shifting values:
3 ⇄ 4 ⇄ 5
```

The node links remain intact.

This keeps the implementation simple and makes the sorting logic easy to understand.

---

## 📝 Result

Insertion Sort was successfully implemented using a Doubly Linked List. The experiment demonstrates linear best-case behavior and quadratic average/worst-case behavior for the implemented sorting logic, with O(1) auxiliary sorting space and O(n) memory required for the linked-list nodes.
