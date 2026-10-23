# Linear Search — Best, Average & Worst Case Analysis

## 1. Logic

Linear Search examines elements sequentially from the beginning of the array.

For each position:

```text
Compare A[i] with key
        ↓
Equal? ── Yes → Found
   │
   No
   ↓
Move to next element
```

If the key is absent, every element is examined.

---

## 2. Best Case

The key is the first element:

```text
A[0] = key
```

Only one comparison is required.

Therefore:

```text
Comparisons = 1
Time = O(1)
```

---

## 3. Average Case

For a successful search where the key is equally likely to occur at any position:

```text
Average comparisons = (N + 1) / 2
```

Therefore:

```text
Time = O(N)
```

The program uses a middle-position key as a simple representative practical test. A more statistically rigorous experiment can average multiple randomly selected successful positions.

---

## 4. Worst Case

The worst case occurs when:

- The key is the last element, or
- The key is not present.

The program uses an absent key:

```text
100001
```

because generated array values are between `0` and `99999`.

Thus approximately `N` elements are checked.

```text
Time = O(N)
```

---

## 5. Space Complexity

The iterative search itself uses only a few variables:

```text
O(1) auxiliary space
```

The array containing the input data requires:

```text
O(N) storage
```

---

## 6. Why Repetitions Are Used

A single Linear Search can finish so quickly that:

```text
CPU Time ≈ 0
```

may be displayed for small input sizes.

The program therefore repeats the same search many times and divides the measured time by the number of repetitions.

This does **not** change the algorithm's complexity. It only makes experimental timing more measurable.

---

## 7. Sample Output

Example format:

```text
Enter number of elements: 1000

Input Size = 1000
Repetitions per measurement = 10000

Best Case:
Key = 4821
CPU Time = 0.000000XXX seconds

Average Case (representative middle position):
Key = 7312
CPU Time = 0.00000XXX seconds

Worst Case:
Key = 100001 (not present)
CPU Time = 0.00000XXX seconds
```

The exact values will vary between systems.
