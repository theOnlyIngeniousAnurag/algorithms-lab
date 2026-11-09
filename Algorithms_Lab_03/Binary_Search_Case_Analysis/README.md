# Binary Search — Best, Average & Worst Case Analysis

## 1. Requirement

Binary Search requires a sorted array.

The program generates:

```text
0, 2, 4, 6, 8, ...
```

so the array is already sorted.

---

## 2. Best Case

The key equals the first middle element examined.

Therefore only one comparison is needed:

```text
Time = O(1)
```

---

## 3. Average Case

For typical successful/unsuccessful searches, Binary Search continues reducing the search interval by approximately half.

The number of levels grows logarithmically:

```text
n → n/2 → n/4 → n/8 → ...
```

Therefore:

```text
Average Time = O(log N)
```

The program uses a representative successful search. A rigorous statistical experiment can average many representative keys.

---

## 4. Worst Case

The worst case occurs when the search continues until the interval becomes empty or only one candidate remains.

The number of steps is proportional to:

```text
log₂(N)
```

Therefore:

```text
Worst Time = O(log N)
```

---

## 5. Space Complexity

The implementation is iterative.

It uses:

```text
beg
end
mid
```

and a few other constant-size variables.

Therefore:

```text
Auxiliary Space = O(1)
```

The input array itself uses:

```text
O(N)
```

storage.

---

## 6. Why the Graph May Look Almost Flat

This is an important point for the practical.

Consider the approximate number of halving steps:

```text
N = 100       → about 7
N = 1000      → about 10
N = 10000     → about 14
```

Even though the input grows by 100 times from 100 to 10000, the number of search levels grows only modestly.

Therefore CPU-time curves may be extremely close together.

That is consistent with logarithmic complexity.
