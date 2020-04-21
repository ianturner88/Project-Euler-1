The problem may be found here: https://projecteuler.net/problem=81

Solution:

The input matrix is read into an array of objects. 

Since one may only traverse from any element rightwards or downwards,
the path downwards and rightwards to the next adjacent element in the 
matrix is calculated from every element in the matrix. If the minimum 
sum to reach a given element is greater than the option currently 
being calculated, the new minimum value is updated.

The cheapest path to every element is stored in a vector and displayed
at the end of the program's execution.

The output can be seen here:
![Output](https://github.com/ianturner88/ProjectEuler/blob/master/PE081/PE081/images/Output.png)

![Object](https://github.com/ianturner88/ProjectEuler/blob/master/PE081/PE081/images/Object.png)