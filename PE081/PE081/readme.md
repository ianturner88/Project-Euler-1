The problem may be found here: https://projecteuler.net/problem=81

Solution:

The input matrix is read into an array of objects. 
![Object](https://github.com/ianturner88/ProjectEuler/blob/master/PE081/PE081/images/Object.png)

The element value parameter contains the value of the matrix at a given
point and is initialized when the file is read in. 

The cheapest sum parameter holds the current value of the cheapest
path to the given element. One may only traverse the matrix going
either rightwards or downwards. If the minimum sum to reach a given 
element is greater than the option currently being calculated, the 
new minimum value is updated.

If the round parameter is 0, the first 'pass' at the given element 
will be listed as the cheapest path to that point; without the 
round parameter, the cheapest path would always be 0, and the 
solution would never be calculated.

The cheapest path vector contains the shortest path across the matrix
to the element in question and is displayed at the end of the 
program's execution.

The output can be seen here:
![Output](https://github.com/ianturner88/ProjectEuler/blob/master/PE081/PE081/images/Output.png)
