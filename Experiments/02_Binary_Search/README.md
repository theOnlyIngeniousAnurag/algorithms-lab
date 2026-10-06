# Binary Search — Logic & Detailed Explanation

## 1. What is Binary Search?

**Binary Search** is an efficient searching technique that repeatedly divides a **sorted array** into two halves.

Instead of checking every element one by one, it checks the middle element and decides which half can contain the key.

> **Important:** Binary Search works correctly only when the array is sorted in the required order.

---

## 2. Basic Idea

Suppose the sorted array is:

```text
10  20  30  40  50  60  70
```

and the key is:

```text
60
```

### Step 1

Middle element:

```text
40
```

Since:

```text
60 > 40
```

the key can only be in the **right half**.

### Step 2

Search the right half:

```text
50  60  70
```

Middle element:

```text
60
```

The key is found.

---

## 3. Step-by-Step Logic

1. Read a sorted array.
2. Read the key to be searched.
3. Set:
   - `beg = 0`
   - `end = N - 1`
4. While `beg <= end`:
   - Calculate the middle position:
     `mid = (beg + end) / 2`
   - If `A[mid] == key`, the key is found.
   - If `A[mid] > key`, search the left half by setting:
     `end = mid - 1`
   - Otherwise, search the right half by setting:
     `beg = mid + 1`
5. If `beg > end`, the key is not present.
6. Stop.

---

## 4. Algorithm

```text
Algorithm BINARY_SEARCH

Input:
    A[0...N-1] : sorted array of N elements
    key        : element to be searched

Output:
    Position of key if found; otherwise, "Key not found"

Variables:
    beg, end, mid : integer

Steps:
1. Read N.
2. Read N elements of the sorted array A.
3. Read key.
4. beg ← 0
5. end ← N - 1
6. While beg ≤ end do
       mid ← (beg + end) / 2

       If A[mid] = key then
           Display "Key found at position mid"
           Stop

       Else if A[mid] > key then
           end ← mid - 1

       Else
           beg ← mid + 1

7. Display "Key not found".
8. Stop.
```

---

## 5. Example

Sorted array:

```text
10  20  30  40  50  60  70
```

Key:

```text
60
```

Search process:

```text
beg = 0, end = 6
mid = 3 → A[3] = 40

60 > 40
Search right half

beg = 4, end = 6
mid = 5 → A[5] = 60

60 = 60
Key found
```

---

## 6. Complexity

| Case | Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(log n) |
| Worst Case | O(log n) |
| Auxiliary Space | O(1) |

### Why?

After every unsuccessful comparison, approximately half of the remaining elements are discarded.

For example:

```text
n
n/2
n/4
n/8
...
```

Therefore, the number of comparisons grows logarithmically, giving **O(log n)** time complexity.
