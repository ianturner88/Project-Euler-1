#include <iostream>
#include <math.h>
using namespace std;

int main (void)
{
  int upperlimit = 100, square, difference, sumsquare;
  int sum = 0;
  
  for (int i = 0; i <= upperlimit; i++)
  {
    sum = pow(i,2);
    sumsquare += sum;
  }
  
  for (int i = 0; i <= upperlimit; i++)
  {
    square += i;
  }
  
  square = pow (square,2);

  difference = square - sumsquare;
  
  cout << difference;
}
