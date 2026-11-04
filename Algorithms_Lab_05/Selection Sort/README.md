# Selection Sort — Logic & Detailed Explanation

## 1. What is Selection Sort?

Selection Sort is a simple comparison-based sorting algorithm.

It divides the array conceptually into:

```text
Sorted part | Unsorted part
```

At every pass, it finds the **smallest element in the unsorted part** and places it at the beginning of that part.

---

## 2. ELI10 Idea

Imagine a group of students standing randomly by height.

You want the shortest student first.

You:

1. Look through everyone.
2. Find the shortest student.
3. Put that student at the first position.
4. Now ignore that position.
5. Find the shortest student among the remaining students.
6. Repeat.

That is Selection Sort.

---

## 3. Example

Consider:

```text
64 25 12 22 11
```

### Pass 1

Smallest value:

```text
11
```

Swap it with the first element:

```text
11 25 12 22 64
```

### Pass 2

Unsorted part:

```text
25 12 22 64
```

Smallest:

```text
12
```

Result:

```text
11 12 25 22 64
```

### Pass 3

Smallest in:

```text
25 22 64
```

is `22`:

```text
11 12 22 25 64
```

### Final

```text
11 12 22 25 64
```

---

## 4. Algorithm

```text
Algorithm SELECTION_SORT

Input:
    A[0...N-1] : array of N elements

Output:
    A sorted in ascending order

Variables:
    i, j, minIndex, temp : integer

Steps:
1. For i ← 0 to N-2 do
2.     minIndex ← i
3.     For j ← i+1 to N-1 do
4.         If A[j] < A[minIndex] then
5.             minIndex ← j
6.     If minIndex ≠ i then
7.         Swap A[i] and A[minIndex]
8. Stop
```

---

## 5. Best Case

Already sorted:

```text
1 2 3 4 5
```

Even though no major rearrangement is necessary, Selection Sort still scans the remaining unsorted portion to determine the minimum.

Therefore:

```text
Best Case = O(n²)
```

---

## 6. Average Case

For random data, the algorithm still searches the remaining portion for the minimum on every pass.

Therefore:

```text
Average Case = O(n²)
```

---

## 7. Worst Case

For reverse-sorted data:

```text
5 4 3 2 1
```

the algorithm still performs essentially the same number of comparisons.

Therefore:

```text
Worst Case = O(n²)
```

---

## 8. Number of Comparisons

The comparisons are approximately:

```text
(n-1) + (n-2) + ... + 2 + 1
```

which equals:

```text
n(n-1) / 2
```

Therefore:

```text
Θ(n²)
```

This is why Selection Sort is quadratic in all three cases.

---

## 9. Number of Swaps

The standard implementation performs at most:

```text
n - 1
```

swaps.

This is an important practical advantage over algorithms that may perform many more swaps.

---

## 10. Space Complexity

The algorithm sorts the original array in place.

Only a few variables are needed:

```text
i
j
minIndex
temp
```

Therefore:

```text
Auxiliary Space = O(1)
```

The input array itself occupies O(n) storage.

---

## 11. Properties

| Property | Selection Sort |
|---|---|
| Comparison based | Yes |
| In-place | Yes |
| Stable | **No, standard version** |
| Adaptive | No |
| Best Case | O(n²) |
| Average Case | O(n²) |
| Worst Case | O(n²) |
| Auxiliary Space | O(1) |
| Maximum swaps | n−1 |

### Why is it not stable?

A swap between the current element and the minimum element can change the relative order of equal elements.

A special stable implementation is possible, but the standard swap-based version used here is not stable.

---

## 12. When Is Selection Sort Useful?

Selection Sort is useful when:

- Simplicity is important.
- Memory usage should remain O(1).
- The number of swaps should be small.
- Input sizes are small.
- The algorithm is being studied for educational purposes.

It is generally not preferred for large datasets because of its O(n²) time complexity.
