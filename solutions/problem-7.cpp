#include <iostream>
using namespace std;

int main(void)
{
  int i, num = 5, count = 2, found;

  while (count < 100001) {
  	found = 1; // assume num is prime
    for (i = 2; i <= (num / 2); i++)
    {
      if (num % i == 0) {
      	  found = 0; // change the flag to zero if num is divisible by a number
      	  break;
      }
    }
    if (found) count++; // increment count if found is 1 (found a prime)
	num++;
  }
  cout << count << "th prime is: " << --num;
  return 0;
}
