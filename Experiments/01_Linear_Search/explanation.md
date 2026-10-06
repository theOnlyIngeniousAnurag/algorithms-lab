# Linear Search — Logic & Detailed Explanation

## 1. What is Linear Search?

**Linear Search** is a simple searching technique in which the elements of an array are checked **one by one from the beginning until the required key is found or the array ends**.

It can be used on both sorted and unsorted arrays.

---

## 2. Basic Idea

Suppose the array is:

```text
10  25  7  42  18
```

and the key is:

```text
42
```

Linear Search checks:

```text
10 → not 42
25 → not 42
7  → not 42
42 → found
```

The search stops as soon as the key is found.

---

## 3. Step-by-Step Logic

1. Read the array size and array elements.
2. Read the key to be searched.
3. Start from the first element.
4. Compare the current element with the key.
5. If both are equal:
   - The key has been found.
   - Store/display its position.
   - Stop searching.
6. Otherwise, move to the next element.
7. Continue until the key is found or all elements have been checked.
8. If the complete array is checked without finding the key, report that the key is not present.

---

## 4. Algorithm

```text
Algorithm LINEAR_SEARCH

Input:
    A[0...N-1] : array of N elements
    key        : element to be searched

Output:
    Position of key if found; otherwise, "Key not found"

Steps:
1. Read N.
2. Read N elements into A.
3. Read key.
4. For i ← 0 to N-1 do
       If A[i] = key then
           Display "Key found at position i"
           Stop
5. Display "Key not found".
6. Stop.
```

---

## 5. Example

Array:

```text
5  12  8  20  15
```

Key:

```text
20
```

Comparisons:

```text
5  ≠ 20
12 ≠ 20
8  ≠ 20
20 = 20  ← Found
```

Therefore, the key is found at index `3` (position `4` if positions are counted from 1).

---

## 6. Complexity

| Case | Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(n) |
| Worst Case | O(n) |
| Auxiliary Space | O(1) |

### Why?

- **Best case:** The key is the first element, so only one comparison is required.
- **Worst case:** The key is the last element or is absent, so all `n` elements may be checked.
- **Space:** Only a few variables are required apart from the input array.
