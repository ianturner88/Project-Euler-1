#include <iostream>
using namespace std;

int main (void)
{
  int testnumber = 1;
  int count;
  int n;
  int highestcount = 0;
  int Collatz = 0;
  
  while (testnumber < 100)
  {
    testnumber++;
    count = 1;
    n = testnumber;
  
    while (n > 1)
    {
      if (n % 2 == 0)
      {
        n = n / 2;
        count++;
      }
    
      if (n % 2 == 1 && n!=1)
      {
        n = 3 * n + 1;
        count++;
      }
    }
  
    if (count > highestcount)
      {
      highestcount = count;
      Collatz = testnumber;
      }
  
  cout << "Collatz: " << Collatz << " Highest Count: " << highestcount << " Number: "<< testnumber << " count: " << count << endl;
  }
}
