# Insertion Sort Using a Doubly Linked List — Detailed Explanation

## 1. What Is a Doubly Linked List?

A Doubly Linked List is a collection of nodes where every node contains:

```text
[data | prev | next]
```

Example:

```text
NULL ← [10] ⇄ [30] ⇄ [20] → NULL
```

`prev` points to the previous node and `next` points to the next node.

---

## 2. Why Is It Called "Doubly"?

Because each node can be traversed in both directions:

```text
Forward  → using next
Backward → using prev
```

This differs from a singly linked list, where each node normally stores only a `next` pointer.

---

## 3. How Insertion Sort Works Here

The list is initially created in the input order.

For each node after the first:

1. Save its value as `key`.
2. Move backward using `prev`.
3. While the previous value is larger than `key`, shift that value forward.
4. Insert the `key` into the correct position.

Conceptually:

```text
Sorted portion | Remaining portion
       ↑
      key
```

---

## 4. ELI10 Explanation

Imagine cards arranged in your hand.

You pick one card:

```text
[5] [3] [4]
```

Pick `3`.

Since `5 > 3`, move `5` to the right:

```text
[5] [5] [4]
```

Put `3` where the empty position is:

```text
[3] [5] [4]
```

Then take `4` and insert it:

```text
[3] [4] [5]
```

The program performs the same idea with linked-list node data.

---

## 5. Important Implementation Choice

There are two broad ways to implement insertion sorting with linked nodes:

### Approach A — Shift node data

Keep the links unchanged and move values between nodes.

This is the approach used here.

### Approach B — Relink nodes

Physically remove a node and reconnect its `prev` and `next` pointers to insert it elsewhere.

That approach demonstrates pointer manipulation more deeply but requires more code and is easier to get wrong.

For a basic Algorithms Lab implementation, **data shifting is simpler and easier to verify**.

---

## 6. Algorithm

```text
Algorithm INSERTION_SORT_DOUBLY_LINKED_LIST

Input:
    head : pointer to first node of doubly linked list

Output:
    Doubly linked list sorted in ascending order

Variables:
    current, previous : node pointers
    key : integer

Steps:
1. If head = NULL, stop.
2. current ← head.next
3. While current ≠ NULL do
4.     key ← current.data
5.     previous ← current.prev
6.     While previous ≠ NULL AND previous.data > key do
7.         previous.next.data ← previous.data
8.         previous ← previous.prev
9.     If previous = NULL then
10.        head.data ← key
11.    Else
12.        previous.next.data ← key
13.    current ← current.next
14. Stop.
```

---

## 7. Best Case

Already sorted list:

```text
1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5
```

Every new value is already greater than or equal to the previous value.

Only one comparison is needed for each inserted element.

Therefore:

```text
Best Case = O(n)
```

---

## 8. Average Case

For random ordering, elements generally need to move through part of the sorted prefix.

Therefore:

```text
Average Case = O(n²)
```

---

## 9. Worst Case

Reverse-sorted list:

```text
5 ⇄ 4 ⇄ 3 ⇄ 2 ⇄ 1
```

Each new element must move across almost the entire sorted prefix.

Therefore:

```text
Worst Case = O(n²)
```

---

## 10. Space Complexity

The linked list itself contains `n` nodes:

```text
Total list storage = O(n)
```

The sorting algorithm uses only a constant number of pointers and a temporary key:

```text
Auxiliary sorting space = O(1)
```

Therefore:

```text
Total data structure space = O(n)
Auxiliary sorting space = O(1)
```

---

## 11. Stability

The implementation shifts values only when:

```text
previous.data > key
```

and not when:

```text
previous.data == key
```

Therefore equal values preserve their relative order.

Hence the sorting logic is:

```text
Stable
```

---

## 12. Properties

| Property | Insertion Sort on DLL |
|---|---|
| Comparison based | Yes |
| Best Case | O(n) |
| Average Case | O(n²) |
| Worst Case | O(n²) |
| Auxiliary sorting space | O(1) |
| List storage | O(n) |
| Stable | Yes |
| Adaptive | Yes |
| In-place with respect to node storage | Yes, values are rearranged inside existing nodes |

---

## 13. Important Observation

Using a Doubly Linked List does **not automatically make Insertion Sort O(n log n)**.

The sorting process still has to move through a growing sorted portion.

Therefore its asymptotic time complexity remains:

```text
Best     → O(n)
Average  → O(n²)
Worst    → O(n²)
```
