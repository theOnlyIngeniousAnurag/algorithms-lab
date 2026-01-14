Experiment 2: Binary Search

Aim: To search a given key element in a sorted array using the Binary Search algorithm.

Algorithm: Binary_Search(A[], N, key)

1. Start
2. Read the value of N
3. Read N sorted elements into array A
4. Read the key element
5. Initialize

   beg = 0

   end = N - 1

   flag = 0
6. While beg <= end , repeat

   (i) Compute mid = (beg + end) / 2
   
    (ii) If A[mid] == key then

          Display "Element found at position mid"
   
          Set flag = 1
   
          Exit loop
   
    (iii) Else if A[mid] > key then

    Set end = mid - 1
   
    (iv) Else

    Set beg = mid + 1

7. If flag != 1 then

   . Display "Element not found"

9. Stop
