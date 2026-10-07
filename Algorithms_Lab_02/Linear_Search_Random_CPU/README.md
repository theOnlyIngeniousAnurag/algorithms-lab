# Linear Search with Random Test Cases & CPU Time

## Logic

1. Read the required input size `N`.
2. Generate `N` random array elements.
3. Select a key from the generated data.
4. Start the CPU timer.
5. Perform Linear Search.
6. Stop the CPU timer.
7. Convert clock ticks to seconds.
8. Display the search result and CPU time.

The program uses the standard C functions `rand()`, `srand()`, `time()`, and `clock()`.

## Why the Key Is Taken from the Array

The program uses:

```c
key = a[n / 2];
```

This guarantees that the key normally exists in the generated array.

This makes the program suitable for demonstrating a successful search while keeping input generation automatic.

## Complexity

The Linear Search operation has:

- Best Case: O(1)
- Average Case: O(n)
- Worst Case: O(n)
- Auxiliary Space: O(1)

The generated array itself requires O(n) storage.
