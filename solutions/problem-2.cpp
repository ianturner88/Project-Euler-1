#include <iostream>
using namespace std;

int main ()
{
  int F1 = 1, F2 = 1, FNext=0, Feven = 0;
  
  while (F1 < 4000000)
  {
  FNext = F1 + F2;
  F1 = F2;
  F2 = FNext;
  
  if (FNext%2 == 0)
    {
      Feven = Feven + FNext; 
    }
  }
  cout << Feven;
}
