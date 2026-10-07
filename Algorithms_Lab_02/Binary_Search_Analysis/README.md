# Binary Search — Experimental Time Complexity Analysis

## 1. Purpose

This program implements **iterative Binary Search** on a sorted array and measures the CPU time taken by the search operation.

---

## 2. Why Must the Array Be Sorted?

Binary Search decides which half to discard based on comparison with the middle element.

Without sorted order, this decision is not valid.

Therefore:

```text
Sorted array + Binary Search = valid
Unsorted array + Binary Search = invalid
```

---

## 3. How the Program Creates the Test Data

The program generates:

```text
0, 2, 4, 6, 8, 10, ...
```

This guarantees a sorted array.

The input size `N` determines how many elements are generated.

---

## 4. Time Measurement

Only the Binary Search function call is placed between:

```c
start = clock();
```

and:

```c
end = clock();
```

This keeps the timing focused on the algorithm.

---

## 5. Theoretical Analysis

At each step, Binary Search approximately halves the remaining search space.

After `k` steps:

```text
remaining elements ≈ n / 2^k
```

The search ends when approximately one element remains:

```text
n / 2^k ≈ 1
```

Therefore:

```text
2^k ≈ n
```

Taking logarithms:

```text
k ≈ log₂ n
```

Hence:

```text
Worst Case = O(log n)
Average Case = O(log n)
```

The best case occurs when the first middle-element comparison finds the key:

```text
Best Case = O(1)
```

---

## 6. Space Complexity

The implementation is iterative and uses only a few variables:

```text
beg
end
mid
```

Therefore:

```text
Auxiliary Space = O(1)
```

The array itself requires:

```text
O(n)
```

storage.
