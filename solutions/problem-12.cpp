/// this code takes 14 hours to run. Hopefully, I find an improvement. 
#include <iostream>
#include <math.h>
using namespace std;

int main (void)
{
  int count = 0;
  long long int little;
  long long int triangle = 76576498;
  long long int i = 1;
  
  while (count < 251)
  {
    count = 0;
    i++;
    triangle += i;
    
    for (little = 2; little <= sqrt(triangle); little++)
    {
      
	  if (triangle%little == 0)
      {
        count++;
      }

    cout << "The count is: " << count << " , the little is: " << little << " and the triangle is: "<< triangle << endl;
 	}
  }
  cout << "The " << i << "th triangle number --- " << triangle <<" --- is the first triangle number to have over 500 divisors.";
}
