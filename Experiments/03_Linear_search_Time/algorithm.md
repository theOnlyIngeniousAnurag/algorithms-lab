**Experiment 3**: Linear Search with Random Test Cases and CPU Time Calculation

**Aim**: To implement Linear Search by generating random input values and calculate the CPU time required for execution.

**Description**:

Linear Search is a simple searching algorithm in which each element of the array is compared with the key element one by one until the required element is found or the list ends.
It is mainly used for small datasets or unsorted arrays, where simplicity is more important than speed.

**What this algorithm/technique does:**

This algorithm searches for a given key element by comparing it sequentially with each element of the array until the element is found or the array ends.



**Algorithm**: Linear_Search_Time

**Input:**

       N   : integer (number of elements in the array)
   
       key : integer (element to be searched)
   
**Output:**
        
         CPU_Time : real (execution time in seconds)
     
**Variables:**
  
    A[0…N−1] : integer array (randomly generated input)
     i        : integer (loop index)
     start    : clock (start time)
     end      : clock (end time)

**Steps:**
      
      1. Input N
      2. For i ← 0 to N−1 do
              A[i] ← random()
      3. Input key
      4. start ← clock()
      5. For i ← 0 to N−1 do
              If A[i] = key then
               break
      6. end ← clock()
      7. CPU_Time ← (end − start) / CLOCKS_PER_SEC
      8. Print CPU_Time
      9. Stop
