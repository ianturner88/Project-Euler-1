#include <iostream>
#include <math.h>
using namespace std;

int main (void)
{
  int prime = 0;
  int small = 1, big = 8, flag = 0;
  int dummyprime = 0, count = 0;
  int circularprime = 0, remainderprime = 0, chopper = 0;
  int numbercp = 4;
  int sqrtlimit = 0;
  int primecheck = 0;
  int circularcount = 0;

  while (big < 1000000)
  {
    big++;
    flag = 1;
    sqrtlimit = sqrt(big);
    primecheck = 0;
    small = 1;
    count = 0;
    
    while (small < sqrtlimit && flag != 0)
    {
      small++;
	  if (big % small == 0)
      {
        flag = 0;
      }
    }
    
    if (flag == 1)
    {
      prime = big;
      dummyprime = prime;
      primecheck = 1;
    }
    
    while (dummyprime != 0)
    {
      dummyprime = dummyprime/10;
      count++;
    }
    
    circularprime = prime;
    flag = 1;
    circularcount = count;
    count = count - 1;
    
    while (circularcount > 1 && primecheck == 1 && flag != 0)
    {
	  circularcount--;
	  remainderprime = circularprime%10;
      chopper = circularprime/10;
      circularprime = remainderprime*pow(10,count) + chopper;
      
      sqrtlimit = sqrt(circularprime);
      small = 1;
      
      while (small < sqrtlimit && flag != 0)
      {
        small++;
		if (circularprime%small == 0)
        {
          flag = 0;
        }
      }
    }
    
    if (flag == 1 && primecheck == 1)
    {
      numbercp++;
    }
  }
  
  cout << numbercp;
}
