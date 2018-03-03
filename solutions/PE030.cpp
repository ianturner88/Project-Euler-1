#include <iostream>
#include <math.h>

using namespace std;

int main (void)
{
  int number = 1;
  int remainder = 0;
  int FourSum = 0;
  int dummy = 0;
  int dummysum = 0;
  int count = 0;
  
  while (number < pow(10,7))
  {
    number++;
    dummy = number;
	remainder = 0;
	dummysum = 0;
    
    while (dummy != 0)
    {
      remainder = dummy % 10;
      remainder = pow (remainder, 5);
      dummysum += remainder;
      dummy = dummy / 10;
      //cout << "Number: " << number << "   Sum: " << dummysum << endl;
    }
    
    if (dummysum == number)
    {
      count++;
	  FourSum += dummysum;
      cout << number << endl;
    }
  }
  
  cout << "Foursum: " << FourSum << "   count: " << count;
}
