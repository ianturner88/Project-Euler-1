/*RTF: 
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/

Solution: 
The handwritten solution is faster than typing up code, so I will use pen and paper for this one.

First, find the prime factors of all the numbers one through 20. 

Second, filter out any duplicates. For example, the prime factors of 10 are 2 & 5, but since 2 and 5 
are the prime facotrs of 2 & 5 themselves, we need not add the prime factors of 10 to our list. 

Three, multiply all the prime factors not filtered out to the get the answer.

1: 1
2: 2
3: 3
4: 2 * 2
5: 5
6: 2 * 3
7: 7
8: 2 * 2 * 2
9: 3 * 3
10: 2 * 5
11: 11
12: 2 * 2 * 3
13: 13
14: 2 * 7
15: 3 * 5
16: 2 * 2 * 2 * 2
17: 17
18: 2 * 3 * 3
19: 19
20: 2 * 2 * 5

Answer: 1 * 2 * 3 * 2 * 5 * 3 * 7 * 2 * 11 * 13 * 2 * 17 * 19
