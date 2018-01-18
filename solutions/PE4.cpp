#include <iostream>
#include <math.h>
using namespace std;

int main (void)
{
  int threedigit = 999;
  int product = 0;
  int limit = 0;
  int firstdivisor = 0, seconddivisor = 0;
  int palindrome = 0;
  int dummyfirstdivisor = 0;
  int firstfinal = 0;
  
  while (threedigit > 100)
  {
    threedigit--;
    
    product = threedigit*1000 + (threedigit%10)*100 + (threedigit/10)%10*10 + (threedigit/100)%10;
    
    limit = sqrt(product);
    firstdivisor = 1000;
    
    while (firstdivisor > limit)
      {
      firstdivisor--;
      dummyfirstdivisor = firstdivisor;
        
        if (product % firstdivisor == 0)
        {
          threedigit = 0;
          seconddivisor = product / firstdivisor;
          firstfinal = firstdivisor;
          firstdivisor = 0;
        }
      }    
    }
    cout << product << " " << firstfinal << " " << seconddivisor;
}
