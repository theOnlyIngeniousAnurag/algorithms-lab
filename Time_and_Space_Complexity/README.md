# Time Complexity & Space Complexity — From Basics to Advanced

## 1. What is Algorithm Analysis?

Algorithm analysis studies how efficiently an algorithm uses computational resources.

The two most important resources are:

1. **Time**
2. **Space**

We usually study how these resources change when the input size increases.

---

# PART A — TIME COMPLEXITY

## 2. What is Time Complexity?

Time complexity describes how the number of operations performed by an algorithm grows with input size `n`.

It does **not** normally mean the exact number of seconds taken on one computer.

For example, if an algorithm examines every element once:

```text
n elements → approximately n operations
```

Its time complexity is:

```text
O(n)
```

---

## 3. Input Size

The variable `n` usually represents the size of the input.

Examples:

- Array → number of elements
- String → number of characters
- Graph → number of vertices and/or edges
- Matrix → number of rows and columns

The choice of `n` depends on the problem.

---

## 4. Counting Basic Operations

Consider:

```c
for (i = 0; i < n; i++)
    printf("%d", a[i]);
```

The loop executes approximately `n` times.

Therefore:

```text
T(n) = c₁n + c₂
```

Ignoring constants and lower-order terms:

```text
T(n) = O(n)
```

---

## 5. Common Time Complexities

From generally faster growth to slower scalability:

| Complexity | Name | Typical Example |
|---|---|---|
| O(1) | Constant | Array access |
| O(log n) | Logarithmic | Binary Search |
| O(n) | Linear | Linear Search |
| O(n log n) | Linearithmic | Merge Sort |
| O(n²) | Quadratic | Bubble Sort |
| O(n³) | Cubic | Basic triple nested loop |
| O(2ⁿ) | Exponential | Some recursive subset algorithms |
| O(n!) | Factorial | Brute-force permutations |

The exact performance also depends on constants, implementation, hardware, and input characteristics.

---

## 6. Constant Time — O(1)

Example:

```c
x = a[5];
```

The operation does not depend on the size of the array.

Therefore:

```text
O(1)
```

---

## 7. Logarithmic Time — O(log n)

Binary Search repeatedly reduces the search space.

```text
n
n/2
n/4
n/8
...
```

Therefore:

```text
O(log n)
```

---

## 8. Linear Time — O(n)

If every element is examined once:

```text
n elements → n operations
```

Therefore:

```text
O(n)
```

Linear Search is a common example.

---

## 9. Linearithmic Time — O(n log n)

Many efficient comparison-based sorting algorithms have this complexity.

Examples include:

- Merge Sort
- Heap Sort
- Average-case Quick Sort

A common pattern is:

```text
divide → solve subproblems → combine
```

---

## 10. Quadratic Time — O(n²)

Two nested loops often produce quadratic complexity.

Example:

```c
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        ...
```

Approximately:

```text
n × n = n²
```

Therefore:

```text
O(n²)
```

---

# PART B — CASE ANALYSIS

## 11. Best Case

The best case represents the most favorable input arrangement.

For Linear Search:

```text
Key = first element
```

Complexity:

```text
O(1)
```

---

## 12. Worst Case

The worst case represents the most unfavorable input arrangement.

For Linear Search:

```text
Key = last element
```

or:

```text
Key is absent
```

Complexity:

```text
O(n)
```

---

## 13. Average Case

Average-case analysis considers the expected work over a specified distribution of inputs.

It requires assumptions about how inputs are distributed.

For Linear Search, the average number of comparisons for a successful search under a uniform position assumption is approximately:

```text
(n + 1) / 2
```

which is still:

```text
O(n)
```

---

# PART C — ASYMPTOTIC NOTATION

## 14. Big-O — O(g(n))

Big-O gives an asymptotic **upper bound** on growth.

Informally:

```text
T(n) does not grow faster than a constant multiple of g(n)
for sufficiently large n.
```

Example:

```text
3n² + 5n + 7 = O(n²)
```

---

## 15. Big-Omega — Ω(g(n))

Big-Ω gives an asymptotic **lower bound**.

Example:

```text
3n² + 5n + 7 = Ω(n²)
```

---

## 16. Big-Theta — Θ(g(n))

Big-Theta gives a **tight asymptotic bound**.

Example:

```text
3n² + 5n + 7 = Θ(n²)
```

So, when the growth is tightly bounded above and below by the same function:

```text
Θ(n²)
```

is more precise than simply saying:

```text
O(n²)
```

---

## 17. Dropping Constants

Consider:

```text
T(n) = 5n
```

The constant `5` does not change the growth category:

```text
T(n) = O(n)
```

Similarly:

```text
100n² = O(n²)
```

---

## 18. Dropping Lower-Order Terms

Consider:

```text
T(n) = n² + 10n + 20
```

For very large `n`, the `n²` term dominates.

Therefore:

```text
T(n) = Θ(n²)
```

---

# PART D — LOOP ANALYSIS

## 19. Single Loop

```c
for (i = 0; i < n; i++)
```

Complexity:

```text
O(n)
```

---

## 20. Nested Loops

```c
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
```

Complexity:

```text
O(n²)
```

---

## 21. Consecutive Loops

```c
for (i = 0; i < n; i++)
    ...

for (j = 0; j < n; j++)
    ...
```

Total:

```text
n + n = 2n
```

Therefore:

```text
O(n)
```

Not `O(n²)`.

---

## 22. Nested Loops with Different Limits

```c
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
```

Complexity:

```text
O(nm)
```

---

# PART E — SPACE COMPLEXITY

## 23. What is Space Complexity?

Space complexity describes how much memory an algorithm requires as input size increases.

It can include:

- Input storage
- Output storage
- Temporary variables
- Auxiliary data structures
- Recursion stack

---

## 24. Auxiliary Space

Auxiliary space means the **extra memory used by the algorithm apart from the input itself**, depending on the convention being used.

Example:

```c
int sum = 0;
```

uses constant extra space:

```text
O(1)
```

---

## 25. O(n) Space

If an algorithm creates another array of size `n`:

```c
int temp[n];
```

then the additional space is:

```text
O(n)
```

---

## 26. Recursive Space

Recursive calls use stack memory.

For a recursion depth of `n`:

```text
O(n)
```

stack space may be required.

Binary Search implemented recursively has logarithmic recursion depth:

```text
O(log n)
```

auxiliary stack space.

The iterative Binary Search used in this laboratory uses:

```text
O(1)
```

auxiliary space.

---

# PART F — TIME-SPACE TRADE-OFF

## 27. What is a Time-Space Trade-Off?

Sometimes we can use additional memory to reduce execution time.

For example:

- Using a lookup table can avoid repeated calculations.
- Caching stores previously calculated results.
- Dynamic programming stores subproblem results to avoid recomputation.

Thus:

```text
More memory
     ↓
Less repeated computation
     ↓
Potentially faster execution
```

The reverse can also occur: using less memory may require more computation.

---

# PART G — ADVANCED CONCEPTS

## 28. Amortized Analysis

Amortized analysis studies the average cost of a sequence of operations rather than analyzing every individual operation independently.

Example:

A dynamic array may occasionally resize, causing one expensive operation.

Although one resize is expensive, resizing happens infrequently, so the amortized cost per insertion can still be:

```text
O(1)
```

---

## 29. Recurrence Relations

Recursive algorithms can often be represented using recurrence relations.

For Merge Sort:

```text
T(n) = 2T(n/2) + O(n)
```

which gives:

```text
T(n) = O(n log n)
```

---

## 30. Master-Theorem Pattern

For recurrences of the form:

```text
T(n) = aT(n/b) + f(n)
```

the Master Theorem can often be used to determine asymptotic complexity.

It is especially useful for divide-and-conquer algorithms.

---

## 31. Experimental vs Theoretical Analysis

### Theoretical analysis

Studies how operations grow mathematically.

Example:

```text
Binary Search → O(log n)
```

### Experimental analysis

Measures actual execution on a computer.

Example:

```text
N = 1000 → measured CPU time
N = 5000 → measured CPU time
N = 10000 → measured CPU time
```

The two approaches complement each other.

---

## 32. Important Final Point

CPU time is **not a substitute for complexity analysis**.

Two computers may execute the same program in different amounts of time, but the algorithm can still have the same asymptotic complexity.

Therefore:

```text
Theoretical Analysis + Experimental Analysis
                    ↓
        Better understanding of performance
```
