# Quick Sort — Detailed Explanation

## 1. What Is Quick Sort?

Quick Sort is a **comparison-based sorting algorithm** that uses the **Divide and Conquer** technique.

It selects one element as a **pivot** and partitions the array around it.

After partitioning:

```text
Smaller elements | Pivot | Larger elements
```

The same process is recursively applied to the left and right parts.

---

## 2. ELI10 Explanation

Imagine choosing one student as a reference.

Everyone shorter than that student stands on the left.

Everyone taller stands on the right.

Now the reference student is in its correct relative position.

Repeat the same process for the left and right groups.

That is the basic idea of Quick Sort.

---

## 3. Example

Consider:

```text
5 2 8 1 7 3
```

Choose the first element:

```text
Pivot = 5
```

After partitioning, one possible arrangement is:

```text
3 2 1 | 5 | 7 8
```

Now recursively sort:

```text
3 2 1
```

and:

```text
7 8
```

Eventually:

```text
1 2 3 5 7 8
```

---

## 4. Pivot Selection in This Lab

This implementation always selects:

```text
First element = Pivot
```

For example:

```text
[5, 2, 8, 1, 7]
 ^
 Pivot
```

This makes the worst-case behavior easy to demonstrate.

For a sorted array:

```text
1 2 3 4 5
^
Pivot
```

the first element is the smallest element.

Therefore, the partition becomes highly unbalanced:

```text
[] | 1 | 2 3 4 5
```

Then:

```text
[] | 2 | 3 4 5
```

and so on.

This leads to:

```text
O(n²)
```

---

## 5. Complete Algorithm

```text
Algorithm QUICK_SORT(A, low, high)

Input:
    A[0...n-1] : array of n elements
    low        : starting index
    high       : ending index

Output:
    A[low...high] sorted in ascending order

Variables:
    pivot, i, j, temp, pivotIndex : integer

Steps:

1. If low >= high, return.

2. pivot ← A[low]

3. i ← low + 1
   j ← high

4. Repeat:
       While i <= high AND A[i] <= pivot
           i ← i + 1

       While A[j] > pivot
           j ← j - 1

       If i < j then
           Swap A[i] and A[j]
       Else
           Exit the repeat loop
   Until the partition is complete.

5. Swap A[low] and A[j].

6. pivotIndex ← j

7. Call QUICK_SORT(A, low, pivotIndex - 1)

8. Call QUICK_SORT(A, pivotIndex + 1, high)

9. Return.
```

---

## 6. How Partitioning Works

Suppose:

```text
A = 7 2 9 4 5 1 8
```

Choose:

```text
pivot = 7
```

Two pointers are used:

```text
i → searches from the left
j → searches from the right
```

The algorithm finds values on the wrong side and swaps them.

When the pointers cross, the pivot is placed between the two partitions.

The final structure becomes:

```text
values <= pivot | pivot | values > pivot
```

The exact arrangement can vary depending on duplicate values.

---

## 7. Best Case

The best case occurs when each pivot divides the array into approximately equal parts.

For example:

```text
n
├── n/2
└── n/2
```

The recurrence is approximately:

```text
T(n) = 2T(n/2) + O(n)
```

Therefore:

```text
Best Case = O(n log n)
```

---

## 8. Average Case

For sufficiently varied/random input, partitions are generally reasonably balanced on average.

Therefore:

```text
Average Case = O(n log n)
```

The exact average depends on the pivot-selection strategy and input distribution.

---

## 9. Worst Case

The worst case occurs when the pivot repeatedly becomes the smallest or largest element.

For example, with the first-element pivot:

```text
1 2 3 4 5
^
pivot
```

The partitions become:

```text
0 elements | pivot | n-1 elements
```

The recurrence becomes:

```text
T(n) = T(n-1) + O(n)
```

Therefore:

```text
Worst Case = O(n²)
```

---

## 10. Space Complexity

Quick Sort does not normally require an auxiliary array like Merge Sort.

However, recursive calls require stack space.

### Balanced recursion

```text
O(log n)
```

### Highly unbalanced recursion

```text
O(n)
```

Therefore:

```text
Best/Average auxiliary stack = O(log n)
Worst auxiliary stack = O(n)
```

The array itself is sorted in place.

---

## 11. Stability

This implementation is:

```text
Not stable
```

Equal elements may change their relative order during swapping.

---

## 12. In-Place Property

Quick Sort rearranges elements within the original array.

It does not require another array of size `n`.

Therefore it is generally considered an:

```text
In-place sorting algorithm
```

apart from its recursion stack.

---

## 13. Properties

| Property | Quick Sort |
|---|---|
| Technique | Divide and Conquer |
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n²) |
| Best/Average Stack | O(log n) |
| Worst Stack | O(n) |
| Stable | No |
| In-place | Yes |
| Comparison Based | Yes |

---

## 14. Quick Sort vs Merge Sort

| Feature | Quick Sort | Merge Sort |
|---|---|---|
| Best | O(n log n) | O(n log n) |
| Average | O(n log n) | O(n log n) |
| Worst | O(n²) | O(n log n) |
| Extra array | Not normally required | O(n) |
| Stable | Usually no | Yes |
| Main operation | Partition | Merge |

---

## 15. Why Quick Sort Is Important

Quick Sort is important because it is:

- Efficient on average
- In-place
- Widely used in practical sorting implementations
- A classic example of divide and conquer
- Useful for understanding recursion and partitioning

---

## 16. Experimental Timing Note

CPU time can be extremely small for small input sizes.

Measured values can vary because of:

- Operating-system scheduling
- Background processes
- CPU frequency changes
- Cache effects
- Compiler optimization
- Timer resolution

Therefore, the program performs repeated measurements.

The experimental timing should support the theoretical analysis, not replace it.

---

## 17. Important Lab Observation

For this experiment, the pivot is deliberately the **first element**.

Therefore:

```text
Sorted input → potentially worst case
Reverse sorted input → potentially worst case
Balanced/random input → generally better
```

This is why pivot selection is an important practical consideration in Quick Sort.
