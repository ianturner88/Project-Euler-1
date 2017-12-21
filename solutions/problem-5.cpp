#include <iostream>
using namespace std;

int main (void)
{
  int big = 3, little = 2;
  
  while (little < 21)
  {
    if (big % little == 0)
    {
      little ++;
    }
  
    else
    {
      big++;
      little = 2;
    }
  } 
  cout << big;
}
