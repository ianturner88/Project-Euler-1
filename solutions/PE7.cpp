#include <iostream>
using namespace std;

int main (void)
{
  int big = 8, little = 2;
  int count = 3;
  int upperlimit = 4;
  
  cout << "Please enter nth prime you'd like to find" <<endl;
  cin >> upperlimit;

  while (count < upperlimit - 1)
  {
    big++;
    count++;
    little = 2;
    while (little < ((big / 2) + 1))
    {
      if (big % little == 0)
      {
        big++;
        little = 2;
      }
      
      else 
      {
        little++;
      }
    }
  }
  cout << big;
}
