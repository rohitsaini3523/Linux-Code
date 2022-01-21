/*
Name: Rohit Saini
Roll no: 6 
Pane: A1
ERP: 1032200897

Algorithm:
i) For Sorting the numbers:
    1. We will use the concept of bubble sort
    2. Define two counter variable 1st with size of n
    3. Define nth length array
    4. Define 2nd counter as n-1 Move array to rsi [Means the 1st number of array to the rsi]
    5. Compare the rsi with its adjacent number
    6. If rsi is less or equal increment rsi index decrement counter 
        with value n-1, use instruction JNZ and jump to step 5 and if
        Zero then decrement counter with value n and jump to step 4
ii) Displaying Sorted Number
    1. Define an empty array
    2. using rsi to array(with numbers) and rdi to array(empty)
    3. write 2 digit display routine which repeat itself 2*n times
    4. In display routine instead of printing number on screen
        move it to empty array.
    5. Outside the display routine print the second array 
*/