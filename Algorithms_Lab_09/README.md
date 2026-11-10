# Lab 09 — Fractional Knapsack and 0/1 Knapsack

**Subject:** Design & Analysis of Algorithms  
**Language:** C

---

# 🎯 Aim

To study and implement:

1. **Fractional Knapsack using the Greedy technique**
2. **0/1 Knapsack using Dynamic Programming**

and compare their logic, applicability, constraints, time complexity, and practical use.

---

# 📌 Experiments

## Experiment 1 — Fractional Knapsack

Implement the Fractional Knapsack problem using the **Greedy method**.

The experiment includes:

- Profit-to-weight ratio
- Greedy selection
- Full and fractional item selection
- Maximum profit
- Algorithm
- C implementation
- Time and space complexity
- Sample output
- Observation table
- Detailed graph

## Experiment 2 — 0/1 Knapsack

Implement the 0/1 Knapsack problem using **Dynamic Programming**.

The experiment includes:

- Difference from Fractional Knapsack
- Why greedy selection does not always work
- DP table
- Include/exclude decision
- Maximum profit
- Algorithm
- C implementation
- Time and space complexity
- Sample output
- Observation table
- Detailed graph

---

# 🧠 Fractional vs 0/1 Knapsack

| Feature | Fractional Knapsack | 0/1 Knapsack |
|---|---|---|
| Item can be divided? | Yes | No |
| Main technique | Greedy | Dynamic Programming |
| Selection | Full or fractional | Full or not selected |
| Typical time | O(n log n) | O(nW) |
| Greedy always optimal? | Yes | No |
| Suitable for divisible resources | Yes | No |
| Common example | Liquid/material resource allocation | Item selection with indivisible objects |

Here `W` represents the knapsack capacity.

---

# 📂 Folder Structure

```text
Lab-09/
│
├── README.md
│
├── Fractional_Knapsack/
│   ├── fractional_knapsack.c
│   ├── explanation.md
│   ├── sample_output.md
│   ├── observation.md
│   └── graph_guide.md
│
└── Zero_One_Knapsack/
    ├── zero_one_knapsack.c
    ├── explanation.md
    ├── sample_output.md
    ├── observation.md
    └── graph_guide.md
```

---

# 📝 Important Terminology

The second experiment is commonly called:

```text
0/1 Knapsack
```

It is **not** a "fractional 0/1" problem.

The meaning of `0/1` is:

```text
0 → item is not selected
1 → item is selected completely
```

No item can be divided.

---

# 📈 Overall Complexity

## Fractional Knapsack

The program calculates the profit/weight ratio and sorts items by this ratio.

With the sorting method used:

```text
Time = O(n²)
```

because the implementation uses Bubble Sort.

However, the **Fractional Knapsack greedy algorithm itself**, when using an efficient comparison sort, is:

```text
O(n log n)
```

The selection after sorting is:

```text
O(n)
```

Therefore:

```text
Efficient implementation = O(n log n)
Current lab implementation = O(n²)
```

---

## 0/1 Knapsack

The Dynamic Programming solution uses:

```text
n × W
```

states.

Therefore:

```text
Time  = O(nW)
Space = O(nW)
```

where:

- `n` = number of items
- `W` = knapsack capacity

---

# 📊 Experimental Observation

CPU measurements are machine-dependent.

Therefore:

- Run the programs on the same machine.
- Keep compiler settings consistent.
- Record actual CPU times.
- Do not replace experimental measurements with theoretical values.

For the 0/1 Knapsack graph, capacity is an important part of the input size. The graph guide therefore explains both a controlled `N`-vs-time experiment and the dependence on `W`.

---

# 📝 Result

The experiments demonstrate that:

- Fractional Knapsack is optimally solved by a greedy ratio-based strategy because items can be divided.
- 0/1 Knapsack cannot generally be solved optimally using the same greedy rule because each item must be taken completely or rejected.
- Dynamic Programming provides an exact solution for 0/1 Knapsack with pseudo-polynomial `O(nW)` time complexity.
