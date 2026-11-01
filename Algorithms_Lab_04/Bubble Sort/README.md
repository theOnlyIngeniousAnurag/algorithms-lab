# Bubble Sort — Logic & Detailed Explanation

## 1. What is Bubble Sort?

Bubble Sort is a simple comparison-based sorting algorithm.

It repeatedly compares **adjacent elements** and swaps them if they are in the wrong order.

For ascending order:

```text
A[j] > A[j+1]
        ↓
     swap
```

After every complete pass, the largest remaining element moves to the end of the unsorted portion.

---

## 2. ELI10 Idea

Imagine people standing in a line according to height.

If a taller person is standing before a shorter person:

```text
Tall → Short
```

swap them.

Keep doing this from left to right.

The largest value slowly "bubbles" toward the end.

---

## 3. Example

Input:

```text
5  3  4  1  2
```

First pass:

```text
5 3 → swap
3 5 4 1 2

5 4 → swap
3 4 5 1 2

5 1 → swap
3 4 1 5 2

5 2 → swap
3 4 1 2 5
```

The largest value `5` is now fixed at the end.

The next pass works on:

```text
3 4 1 2
```

Eventually:

```text
1 2 3 4 5
```

---

## 4. Early-Exit Optimization

The implementation uses:

```c
swapped = 0;
```

and sets it to `1` whenever a swap occurs.

If an entire pass finishes without a swap, the array is already sorted.

The algorithm stops immediately.

This changes the best-case time from:

```text
O(n²)
```

to:

```text
O(n)
```

for an already sorted array.

---

## 5. Algorithm

```text
Algorithm BUBBLE_SORT

Input:
    A[0...N-1] : array of N elements

Output:
    A sorted in ascending order

Variables:
    i, j, temp : integer
    swapped : boolean

Steps:
1. For i ← 0 to N-2 do
2.     swapped ← false
3.     For j ← 0 to N-i-2 do
4.         If A[j] > A[j+1] then
5.             Swap A[j] and A[j+1]
6.             swapped ← true
7.     If swapped = false then
8.         Break
9. Stop
```

---

## 6. Best Case

Input is already sorted:

```text
1 2 3 4 5
```

The first pass performs comparisons but no swaps.

The early-exit condition stops the algorithm.

```text
Best Case = O(n)
```

---

## 7. Average Case

For random input, many comparisons and swaps are generally required.

```text
Average Case = O(n²)
```

---

## 8. Worst Case

Reverse-sorted input produces the maximum number of swaps.

Example:

```text
5 4 3 2 1
```

```text
Worst Case = O(n²)
```

---

## 9. Space Complexity

Bubble Sort sorts the array in place and uses only a few temporary variables.

Therefore:

```text
Auxiliary Space = O(1)
```

---

## 10. Properties

| Property | Bubble Sort |
|---|---|
| Comparison based | Yes |
| In-place | Yes |
| Stable | Yes |
| Adaptive with early exit | Yes |
| Best Case | O(n) |
| Average Case | O(n²) |
| Worst Case | O(n²) |
| Auxiliary Space | O(1) |

---

## 11. Practical Note

Bubble Sort is easy to understand but is generally inefficient for large datasets.

Its educational value is high because it clearly demonstrates:

- Comparisons
- Swapping
- Passes
- Best/worst-case behavior
- Basic complexity analysis
