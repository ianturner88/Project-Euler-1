The problem may be found here: https://projecteuler.net/problem=81

Solution:

The input matrix is read into an array of objects. 

One may only traverse from any element rightwards or downwards, and 
one must land in the bottom right corner of the matrix to complete
the task. The path downwards and rightwards to the next adjacent 
element in the matrix is calculated from every element in the matrix.
If the minimum sum to reach a given element is greater than the option 
currently being calculated, the new minimum value is updated.

The cheapest path to every element is stored in a vector and displayed
at the end of the program's execution.

