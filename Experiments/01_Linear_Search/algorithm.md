Experiment 1: Linear Search
Aim: To search a given key element in an array using the Linear Search algorithm.


Algorithm: Linear_Search(A, N, key)
1. Start
2. Read the value of N (size of array)
3. Read N elements into array A
4. Read the key element to be searched
5. Set flag = 0
6. for i = 0 to N - 1, repeat
If A[i] == key then
    . Display "Element found at position i"
    . Set flag = 1
    . Exit the loop
7. If flag != 1 then
    . Display "Element not found"
8. Stop
