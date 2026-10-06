# Lab 01 — Linear Search & Binary Search

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

## 🎯 Aim

To understand and implement two fundamental searching techniques:

1. Linear Search
2. Binary Search

The experiments also focus on understanding the logic, working steps, requirements, and time complexity of both techniques.

---

## 📌 Experiments

### Experiment 1 — Linear Search

- Understand the logic of Linear Search.
- Explain how an element is searched sequentially in an array.
- Implement a C program to search for a key element using Linear Search.

### Experiment 2 — Binary Search

- Understand the logic of Binary Search.
- Explain why Binary Search requires a sorted array.
- Implement a C program to search for a key element using Binary Search.

---

## 📂 Folder Structure

```text
Lab-01/
│
├── README.md
│
├── Linear_Search/
│   ├── linear_search.c
│   └── explanation.md
│
└── Binary_Search/
    ├── binary_search.c
    └── explanation.md
```

---

## 🔬 Important Difference

| Feature | Linear Search | Binary Search |
|---|---|---|
| Array requirement | Sorted or unsorted | **Must be sorted** |
| Searching method | Checks elements one by one | Repeatedly divides the search range |
| Best Case | O(1) | O(1) |
| Average Case | O(n) | O(log n) |
| Worst Case | O(n) | O(log n) |
| Extra Space | O(1) | O(1) for iterative implementation |

---

## ▶️ Compilation

### Linear Search

```bash
gcc linear_search.c -o linear_search
```

### Binary Search

```bash
gcc binary_search.c -o binary_search
```

Run the generated executable from the terminal.

---

## 📝 Result

Both searching techniques were studied and implemented successfully in C.

The experiment demonstrates that Binary Search can be significantly more efficient than Linear Search for large **sorted** arrays because it eliminates approximately half of the remaining search space after each comparison.
