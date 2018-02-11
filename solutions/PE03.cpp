#include <iostream>
using namespace std;
//process specifications & data dictionaries
int main (void)
{
  long int big = 600851475143;
  int small = 2;
  int primechecker, largestprime=0;
  bool isPrime=0;
  
  for (small; small <= big / 2; small++)
  {
    if (big%small==0)
    {
      isPrime=1;
      for (primechecker = 2; primechecker <= small/2; primechecker++)
      {
        if (small%primechecker==0)
        {
          isPrime = 0;
          break;
        }
        
        else
        {
          isPrime = 1;
          largestprime = small;
        }
      }
    if(isPrime) cout << largestprime << endl;
    }
  }
}
