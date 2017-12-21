#include <iostream>
using namespace std;

int main (void)
{
  int F1 = 1;
  int F2 = 1;
  int Fnext = 0;
  int sum = 0;
  
  while (F1<4000000)
  {
    Fnext = F1 + F2;
    F1 = F2;
    F2 = Fnext;
    
    if (Fnext % 2 == 0)
    {
      sum += Fnext;
    }
  }
  
  cout << sum;
}
