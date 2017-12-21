#include <iostream>
#include <math.h>
using namespace std;

int main (void)
{
  int integer = 1;
  int upperlimit;
  int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
  
  cout << "Please enter an upperlimit" <<endl;
  cin >> upperlimit;
  
  for (integer; integer < upperlimit + 1; integer++)
  {
    sum1 += pow(integer,2);
  }
  
  integer = 1;
  
  while (integer < upperlimit + 1)
  {
    sum2 += integer;
    integer++;
  }
  
  sum3 = pow(sum2, 2);
  
  sum4 = sum3 - sum1;
  
  cout << sum4;
}
