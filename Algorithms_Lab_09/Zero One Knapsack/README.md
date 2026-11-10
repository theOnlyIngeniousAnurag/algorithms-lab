# 0/1 Knapsack — Detailed Explanation

## 1. What Is 0/1 Knapsack?

The 0/1 Knapsack problem is similar to Fractional Knapsack, but an item **cannot be divided**.

For every item, there are only two choices:

```text
0 → Do not take the item
1 → Take the entire item
```

Hence the name:

```text
0/1 Knapsack
```

---

## 2. Example

Suppose:

| Item | Weight | Profit |
|---|---:|---:|
| 1 | 10 | 60 |
| 2 | 20 | 100 |
| 3 | 30 | 120 |

Capacity:

```text
50
```

You may take:

```text
Item 1 + Item 2
```

or:

```text
Item 2 + Item 3
```

but you cannot take two-thirds of Item 3.

---

## 3. Why Fractional Greedy Does Not Always Work

Consider:

| Item | Weight | Profit | Ratio |
|---|---:|---:|---:|
| A | 10 | 60 | 6 |
| B | 20 | 100 | 5 |
| C | 30 | 120 | 4 |

Capacity:

```text
50
```

Greedy ratio selection chooses:

```text
A + B = profit 160
```

and then cannot fit C.

But:

```text
B + C
```

has:

```text
Weight = 50
Profit = 220
```

Therefore, simply choosing the highest profit/weight ratio does **not** always produce the optimal 0/1 solution.

This is the key difference.

---

## 4. ELI10 Explanation

Imagine a bag that can carry 50 kg.

You have:

```text
Laptop → 10 kg
TV     → 20 kg
Speaker → 30 kg
```

You cannot take half a TV.

For every item you must ask:

```text
Take it?
OR
Leave it?
```

The algorithm systematically compares these possibilities and keeps the best achievable profit for each capacity.

---

## 5. Dynamic Programming Idea

Define:

```text
dp[i][w]
```

as:

> Maximum profit obtainable using the first `i` items when the available capacity is `w`.

For every item, there are two possibilities.

### Option 1 — Do not take the item

```text
dp[i-1][w]
```

### Option 2 — Take the item

Only possible when:

```text
weight[i-1] <= w
```

Then:

```text
profit[i-1] + dp[i-1][w - weight[i-1]]
```

Choose the better option.

Therefore:

```text
dp[i][w] =
max(
    dp[i-1][w],
    profit[i-1] + dp[i-1][w-weight[i-1]]
)
```

---

## 6. Complete Algorithm

```text
Algorithm ZERO_ONE_KNAPSACK

Input:
    n : integer (number of items)
    W : integer (knapsack capacity)
    weight[0...n-1] : weights
    profit[0...n-1] : profits

Output:
    Maximum profit obtainable without exceeding capacity

Variables:
    dp[0...n][0...W] : DP table
    i, w : integers

Steps:

1. For w ← 0 to W do
       dp[0][w] ← 0
   End For

2. For i ← 0 to n do
       dp[i][0] ← 0
   End For

3. For i ← 1 to n do
       For w ← 1 to W do

           If weight[i-1] <= w then

               include ← profit[i-1]
                          + dp[i-1][w-weight[i-1]]

               exclude ← dp[i-1][w]

               dp[i][w] ← max(include, exclude)

           Else

               dp[i][w] ← dp[i-1][w]

           End If

       End For
   End For

4. Return dp[n][W].
```

---

## 7. DP Table Example

For the example:

```text
Weights = 10, 20, 30
Profits = 60, 100, 120
Capacity = 50
```

The DP table records the best profit for each combination of:

```text
number of items
+
available capacity
```

The final cell:

```text
dp[3][50]
```

contains the maximum achievable profit.

The answer is:

```text
220
```

---

## 8. Why Dynamic Programming?

The problem contains:

### Overlapping subproblems

The same smaller capacities and item combinations are considered repeatedly.

### Optimal substructure

The optimal solution for a larger problem can be constructed from optimal solutions of smaller subproblems.

These properties make Dynamic Programming suitable.

---

## 9. Time Complexity

There are:

```text
n × W
```

DP states.

Each state is computed in constant time.

Therefore:

```text
Time = O(nW)
```

This is called **pseudo-polynomial time**, because it depends on the numeric value of capacity `W`, not only on the number of bits needed to represent `W`.

---

## 10. Space Complexity

The full DP table contains:

```text
(n + 1) × (W + 1)
```

entries.

Therefore:

```text
Space = O(nW)
```

The lab implementation intentionally keeps the full table because it makes the DP logic and table easy to understand.

A memory-optimized version can reduce space to:

```text
O(W)
```

but the full table is more useful for teaching and reconstruction of selected items.

---

## 11. Where 0/1 Knapsack Is Used

The model is useful when choices are indivisible and resources are limited.

Examples include:

- Selecting projects under a fixed budget
- Choosing products under a weight/storage limit
- Selecting investments with a fixed budget
- Resource allocation
- Equipment selection
- Portfolio-like selection problems
- Subset-selection problems

---

## 12. Fractional vs 0/1 — Why the Algorithms Differ

### Fractional

An item can be split:

```text
Take 100%, 60%, 25%, etc.
```

Therefore the highest profit/weight ratio can safely be selected first.

```text
Greedy → Optimal
```

### 0/1

An item is indivisible:

```text
Take 100% OR take 0%
```

A locally best ratio may block a better combination.

Therefore:

```text
Greedy ratio → Not always optimal
```

Dynamic Programming is used to systematically compare choices.

---

## 13. Comparison Table

| Feature | Fractional | 0/1 |
|---|---|---|
| Item divisible | Yes | No |
| Choice | Any fraction | 0 or 1 |
| Main method | Greedy | Dynamic Programming |
| Greedy ratio optimal? | Yes | No |
| Typical complexity | O(n log n) with efficient sort | O(nW) |
| Capacity type | Can be real-valued | Usually integer for DP table |
| Space | O(n) item storage | O(nW) full DP table |
| Example | Divisible raw material | Indivisible products |

---

## 14. Important Terminology

Do not write:

```text
Fractional 0/1 Knapsack
```

The correct names are:

```text
Fractional Knapsack
```

and:

```text
0/1 Knapsack
```

They are two different variants of the Knapsack problem.

---

## 15. Practical Limitation

The `O(nW)` DP approach is excellent when `W` is reasonably bounded.

If:

```text
W = 10,000,000
```

the DP table can become very large.

For very large capacities, other approaches such as:

- memory optimization,
- branch and bound,
- approximation algorithms,
- meet-in-the-middle,

may be considered depending on the constraints.

For this Algorithms Lab, the standard DP table is the clearest exact solution.
