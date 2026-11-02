# Insertion Sort — Logic & Detailed Explanation

## 1. What is Insertion Sort?

Insertion Sort builds the sorted array **one element at a time**.

At every step, it takes the next element, called the **key**, and inserts it into its correct position in the already sorted left portion.

---

## 2. ELI10 Idea

Imagine arranging playing cards in your hand.

You pick one new card and insert it into the correct position among the cards already arranged.

Insertion Sort works in exactly this style.

---

## 3. Example

Input:

```text
5 3 4 1 2
```

Initially:

```text
5 | 3 4 1 2
```

Insert `3`:

```text
3 5 | 4 1 2
```

Insert `4`:

```text
3 4 5 | 1 2
```

Insert `1`:

```text
1 3 4 5 | 2
```

Insert `2`:

```text
1 2 3 4 5
```

The left side is always sorted.

---

## 4. Algorithm

```text
Algorithm INSERTION_SORT

Input:
    A[0...N-1] : array of N elements

Output:
    A sorted in ascending order

Variables:
    i, j, key : integer

Steps:
1. For i ← 1 to N-1 do
2.     key ← A[i]
3.     j ← i - 1
4.     While j ≥ 0 AND A[j] > key do
5.         A[j+1] ← A[j]
6.         j ← j - 1
7.     A[j+1] ← key
8. Stop
```

---

## 5. Best Case

The array is already sorted:

```text
1 2 3 4 5
```

Each key is already in the correct position.

Only a small number of comparisons are needed.

Therefore:

```text
Best Case = O(n)
```

---

## 6. Average Case

For random input, elements generally need to be shifted.

The number of operations grows quadratically.

```text
Average Case = O(n²)
```

---

## 7. Worst Case

Reverse-sorted input requires the maximum number of shifts.

Example:

```text
5 4 3 2 1
```

Every new key must move across most of the already sorted portion.

Therefore:

```text
Worst Case = O(n²)
```

---

## 8. Space Complexity

Insertion Sort works directly inside the original array.

Only a few variables such as `key`, `i`, and `j` are used.

Therefore:

```text
Auxiliary Space = O(1)
```

---

## 9. Properties

| Property | Insertion Sort |
|---|---|
| Comparison based | Yes |
| In-place | Yes |
| Stable | Yes |
| Adaptive | Yes |
| Best Case | O(n) |
| Average Case | O(n²) |
| Worst Case | O(n²) |
| Auxiliary Space | O(1) |

---

## 10. Why Insertion Sort Is Useful

Insertion Sort performs particularly well when:

- The input is small.
- The data is already nearly sorted.
- Elements arrive one at a time and need to be inserted.
- Simplicity is important.

It is therefore more practically useful than Bubble Sort in many small-input situations.
