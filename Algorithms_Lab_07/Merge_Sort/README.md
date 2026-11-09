# Merge Sort — Detailed Explanation

## 1. What Is Merge Sort?

Merge Sort is a **comparison-based sorting algorithm** based on the **Divide and Conquer** technique.

Its main idea is:

```text
Divide → Conquer → Combine
```

The array is divided into smaller portions until each portion contains only one element.

A single element is already sorted.

The sorted portions are then merged to produce larger sorted portions.

---

## 2. ELI10 Explanation

Imagine you have many books that need to be arranged alphabetically.

Instead of sorting all books at once:

1. Split them into two groups.
2. Split each group again.
3. Continue until every group has one book.
4. Start joining the groups.
5. Whenever two groups are joined, compare their front books and take the smaller one.
6. Continue until everything is merged.

That is Merge Sort.

---

## 3. Example

Consider:

```text
38 12 27 43 9 31 18 25
```

### Divide

```text
38 12 27 43        9 31 18 25

38 12   27 43     9 31   18 25

38  12  27  43    9  31  18  25
```

### Merge small portions

```text
12 38    27 43     9 31    18 25
```

Then:

```text
12 27 38 43       9 18 25 31
```

Finally:

```text
9 12 18 25 27 31 38 43
```

---

## 4. Complete Algorithm

The following is intentionally written as **one complete Merge Sort algorithm**, including the merging operation, so that the algorithm directly corresponds to the program.

```text
Algorithm MERGE_SORT(A, left, right)

Input:
    A[0...n-1] : array of n elements
    left       : starting index of the current portion
    right      : ending index of the current portion

Output:
    A[left...right] sorted in ascending order

Variables:
    mid, i, j, k : integer
    temp         : temporary array

Steps:

1. If left >= right, return.

2. mid ← left + (right - left) / 2

3. Call MERGE_SORT(A, left, mid)

4. Call MERGE_SORT(A, mid + 1, right)

5. Create temporary array temp of size (right - left + 1).

6. i ← left
   j ← mid + 1
   k ← 0

7. While i <= mid AND j <= right do
       If A[i] <= A[j] then
           temp[k] ← A[i]
           i ← i + 1
       Else
           temp[k] ← A[j]
           j ← j + 1
       End If
       k ← k + 1
   End While

8. While i <= mid do
       temp[k] ← A[i]
       i ← i + 1
       k ← k + 1
   End While

9. While j <= right do
       temp[k] ← A[j]
       j ← j + 1
       k ← k + 1
   End While

10. Copy all elements of temp back into A[left...right].

11. Return.
```

---

## 5. Why Does the Algorithm Work?

At every recursive level:

- The left half becomes sorted.
- The right half becomes sorted.
- The merge step combines the two sorted halves.

The important point is that **merging two sorted arrays takes linear time**.

For example:

```text
Left:  12 27 38
Right: 9 18 31
```

Compare their first elements:

```text
9 < 12 → take 9
12 < 18 → take 12
18 < 27 → take 18
27 < 31 → take 27
31 < 38 → take 31
38 remains → take 38
```

Result:

```text
9 12 18 27 31 38
```

---

## 6. Divide-and-Conquer Structure

For `n` elements:

```text
Level 0:        n
               / \
Level 1:      n/2 n/2
             / \ / \
Level 2:    n/4 ...
```

The number of levels is approximately:

```text
log₂(n)
```

At each level, approximately `n` elements are processed during merging.

Therefore:

```text
Time = n × log₂(n)

     = O(n log n)
```

---

## 7. Recurrence Relation

Merge Sort can be represented by:

```text
T(n) = 2T(n/2) + O(n)
```

Why?

- `2T(n/2)` → recursively sort two halves
- `O(n)` → merge the two sorted halves

Using the standard recurrence analysis:

```text
T(n) = O(n log n)
```

---

## 8. Best Case

Even if the array is already sorted, Merge Sort still divides the array and performs the merge process.

Therefore:

```text
Best Case = O(n log n)
```

---

## 9. Average Case

For randomly ordered data:

```text
Average Case = O(n log n)
```

---

## 10. Worst Case

Even when the input is arranged in the most unfavorable order, the array is still divided into halves and merged.

Therefore:

```text
Worst Case = O(n log n)
```

---

## 11. Space Complexity

The standard implementation uses a temporary array while merging.

Therefore:

```text
Auxiliary Space = O(n)
```

The recursive calls also require stack space of approximately:

```text
O(log n)
```

The dominant auxiliary storage is the temporary merge array:

```text
Overall auxiliary space = O(n)
```

---

## 12. Stability

The program uses:

```c
if (a[i] <= a[j])
```

When two values are equal, the element from the left half is selected first.

Therefore the implementation is:

```text
Stable
```

---

## 13. Important Properties

| Property | Merge Sort |
|---|---|
| Technique | Divide and Conquer |
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n log n) |
| Auxiliary Space | O(n) |
| Stable | Yes |
| Adaptive | No |
| Comparison Based | Yes |

---

## 14. Why Merge Sort Is Useful

Merge Sort is particularly useful when:

- Predictable `O(n log n)` performance is required.
- Stable sorting is useful.
- Large datasets need reliable sorting.
- External sorting is required for data that cannot fit entirely in memory.
- A divide-and-conquer solution is desirable.

---

## 15. Practical Observation

CPU measurements for small `N` can be extremely small and may fluctuate.

Possible reasons include:

- Operating-system scheduling
- Background processes
- CPU frequency changes
- Cache behavior
- Compiler optimization
- Timer resolution

Therefore, the program performs repeated trials and reports the average CPU time per repetition.

The experimental values should be treated as observations, while the asymptotic complexity comes from algorithm analysis.
