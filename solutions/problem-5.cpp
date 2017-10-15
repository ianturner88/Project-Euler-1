// https://projecteuler.net/problem=5
#include <iostream>
using namespace std;

int  main (void)
{
  int small = 1, big = 2, i = 0;
  
  while (small < 21) 
  {
    for (small = 2; small < 21; small++)
    {
      if (big % small == 0)
      {
        small++;
      }
      
      if (big % small != 0)
      {
        big++;
        break;
      }
      
      if (big == small)
      {
        big++;
        break;
      }
    }
  }
  cout << big;
}  
