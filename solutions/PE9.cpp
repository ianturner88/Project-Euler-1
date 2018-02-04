#include <iostream>
using namespace std;

int main (void)
{
  int a = 0, b = 0, c = 0;
  int sum;
  int product;
  
  while (a < 999/2)
  {
    a++;
    b = 0;
	
	while (b < 999/2)
	{
      b++;
	  c = 1000 - a - b;
      
      if (a*a + b*b == c*c)
      {
        product = a * b * c;
  		cout << "The product is: " << product << "." << endl;
  		cout << "a: " << a << " b: " << b << " c: " << c << endl;
      }
    }
  }
}
