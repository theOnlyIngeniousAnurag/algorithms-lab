# Fractional Knapsack — Detailed Explanation

## 1. Problem Statement

We are given `n` items.

Each item has:

- A weight
- A profit

The knapsack has a maximum capacity.

Unlike 0/1 Knapsack, an item **can be divided**.

For example, if an item weighs `20 kg` and only `5 kg` of capacity is available, we can take:

```text
5/20 = 0.25
```

of the item.

The objective is:

```text
Maximize total profit
```

without exceeding the capacity.

---

## 2. ELI10 Explanation

Imagine a truck has limited space.

You have several materials:

```text
Material A → high profit per kg
Material B → medium profit per kg
Material C → low profit per kg
```

If the material can be divided, always take the material that gives the **highest profit for each unit of weight** first.

If only part of the final item fits, take that part.

That is Fractional Knapsack.

---

## 3. Greedy Idea

For every item calculate:

```text
Profit-to-weight ratio = Profit / Weight
```

Example:

| Item | Weight | Profit | Profit/Weight |
|---|---:|---:|---:|
| 1 | 10 | 60 | 6.0 |
| 2 | 20 | 100 | 5.0 |
| 3 | 30 | 120 | 4.0 |

Select items in descending ratio:

```text
Item 1 → 6.0
Item 2 → 5.0
Item 3 → 4.0
```

---

## 4. Example

Capacity:

```text
50
```

Items:

```text
Item 1: weight 10, profit 60
Item 2: weight 20, profit 100
Item 3: weight 30, profit 120
```

Take Item 1 completely:

```text
Weight used = 10
Profit = 60
Remaining capacity = 40
```

Take Item 2 completely:

```text
Weight used = 30
Profit = 160
Remaining capacity = 20
```

Only 20 of Item 3 can be taken:

```text
Fraction = 20/30 = 2/3
```

Profit obtained:

```text
120 × 2/3 = 80
```

Total:

```text
60 + 100 + 80 = 240
```

Therefore:

```text
Maximum Profit = 240
```

---

## 5. Complete Algorithm

```text
Algorithm FRACTIONAL_KNAPSACK

Input:
    n : integer (number of items)
    W : real (maximum knapsack capacity)
    weight[0...n-1] : weights of items
    profit[0...n-1] : profits of items

Output:
    Maximum profit that can be obtained

Variables:
    ratio[i] : profit-to-weight ratio
    remaining : remaining capacity
    totalProfit : total profit

Steps:

1. For i ← 0 to n-1 do
       ratio[i] ← profit[i] / weight[i]
   End For

2. Sort all items in descending order of ratio.

3. remaining ← W
   totalProfit ← 0

4. For i ← 0 to n-1 do

       If remaining = 0 then
           Break
       End If

       If weight[i] <= remaining then
           totalProfit ← totalProfit + profit[i]
           remaining ← remaining - weight[i]
       Else
           fraction ← remaining / weight[i]
           totalProfit ← totalProfit + profit[i] × fraction
           remaining ← 0
       End If

   End For

5. Return totalProfit.
```

---

## 6. Why Does Greedy Work?

Suppose one kilogram of Item A gives:

```text
₹10
```

and one kilogram of Item B gives:

```text
₹5
```

If the items are divisible, replacing one kilogram of B with one kilogram of A always improves or maintains the profit.

Therefore, taking the highest ratio first is optimal.

This is the key reason the greedy strategy works for Fractional Knapsack.

---

## 7. Time Complexity

The implementation first sorts the items.

This lab program uses Bubble Sort:

```text
Sorting = O(n²)
```

The actual greedy selection requires:

```text
O(n)
```

Therefore the current implementation has:

```text
Overall Time = O(n²)
```

If an efficient sorting algorithm such as Merge Sort or Quick Sort is used:

```text
Overall Time = O(n log n)
```

---

## 8. Space Complexity

The program stores information for `n` items:

```text
O(n)
```

The sorting is performed within the item array.

Therefore:

```text
Auxiliary space ≈ O(1)
Total item storage = O(n)
```

---

## 9. Important Properties

| Property | Fractional Knapsack |
|---|---|
| Item divisible | Yes |
| Technique | Greedy |
| Greedy optimal | Yes |
| Current implementation | Bubble Sort + Greedy |
| Current time | O(n²) |
| Efficient sorting version | O(n log n) |
| Space | O(n) for item storage |

---

## 10. Applications

Fractional Knapsack is useful when resources are divisible, such as:

- Liquid/material allocation
- Cargo where materials can be divided
- Bandwidth/resource allocation
- Budget allocation in divisible units
- Raw material selection

---

## 11. Key Limitation

The greedy strategy depends on divisibility.

If an item cannot be divided, selecting the highest ratio first may produce a non-optimal answer.

That leads to the 0/1 Knapsack problem.
