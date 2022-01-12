/*
Name : Rohit Saini   Roll no: 6
Panel: A1   Erp: 1032200897

Algorithm:
1. Define n numbers.
2. Declare Message "Sum:".
3. Define a Counter Variable with size n.
4. In Section .bss Define sum, num, temp variables.
5. Using Rsi set pointer to 1st number in n numbers.
6. Set ax, bx to 00H and cx register to Counter.
7. Define add procedure as:
    7.1 Move data from rsi to bl register
    7.2 add it to ax
    7.3 Jump to Skip procedure
    7.4 Increase the ah register
8. Define Skip procedure as:
    8.1 Increase rsi
    8.2 Decrease cx register
    8.3 Jump to add if cs not zero
    8.4 Move content of ax to word[sum]
    8.5 Display Message
    8.6 Move sum to ax
9. Define 4 digit Display routine
10. Exit 
*/