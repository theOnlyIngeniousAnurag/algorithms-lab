# Random Test Cases & CPU Time — Detailed Explanation

## 1. What is a Test Case?

A **test case** is a particular input given to a program to check its behavior and performance.

Example:

```text
Array = 10 20 30 40 50
Key = 40
```

is one test case for a searching algorithm.

---

## 2. What is a Random Test Case?

A random test case is generated automatically rather than being manually entered.

For example, a program may generate:

```text
37  82  14  65  9  41  73
```

Random testing is useful because manually selected inputs may accidentally favor or disadvantage an algorithm.

---

## 3. Why Use Random Inputs?

Random test cases help us:

- Test programs with many different inputs.
- Reduce dependence on one manually selected example.
- Study average practical behavior.
- Test larger input sizes quickly.
- Compare execution time for different values of `N`.

---

## 4. Input Size

Let:

```text
N = number of input elements
```

For example:

```text
N = 100
N = 1000
N = 5000
N = 10000
```

We can run the same algorithm for each value and compare the execution time.

---

## 5. Measuring CPU Time in C

The C standard library provides the `clock()` function through:

```c
#include <time.h>
```

The basic method is:

```c
start = clock();

/* Algorithm being measured */

end = clock();

cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
```

### Simple explanation

```text
start → start the stopwatch
algorithm runs
end   → stop the stopwatch
difference → elapsed processor clock ticks
divide by CLOCKS_PER_SEC → CPU time in seconds
```

---

## 6. Why Measure Only the Algorithm?

If we want to analyze an algorithm, the timing section should contain the main operation being studied.

For example:

```c
start = clock();

linearSearch(a, n, key);

end = clock();
```

This avoids unnecessarily including input/output operations in the measured section.

---

## 7. Repeated Measurements

A single measurement may not be reliable, especially for very small inputs.

A better experimental process is:

1. Generate an input.
2. Run the algorithm.
3. Record CPU time.
4. Repeat for several input sizes.
5. Compare the measurements.

For very fast algorithms, repeated trials can also be averaged.

---

## 8. Important Limitation

CPU time is an **experimental measurement**, not a mathematical proof of complexity.

For example, if one run gives:

```text
0.000002 seconds
```

and another gives:

```text
0.000003 seconds
```

that does not mean the algorithm suddenly became 50% slower in a meaningful asymptotic sense.

Small measurements are affected by system noise and timing overhead.

---

## 9. Best, Average and Worst Cases

For searching algorithms, input arrangement matters.

### Best Case

The key is found immediately.

For Linear Search:

```text
[KEY, ...]
```

Only one comparison is required.

### Average Case

The key is normally found somewhere in the middle of the search process.

### Worst Case

The key is at the end or absent.

For Linear Search, almost every element may need to be checked.

---

## 10. Experimental Workflow

```text
Choose input sizes
        ↓
Generate test data
        ↓
Run algorithm
        ↓
Measure CPU time
        ↓
Record observation table
        ↓
Plot graph
        ↓
Compare with theoretical complexity
```

---

## 11. Key Point

Random testing is mainly used to create varied practical inputs. Complexity analysis explains how the number of operations grows mathematically as the input size increases.
