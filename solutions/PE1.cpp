#include <iostream>
using namespace std;

int main (void)
{
  int x,y,z;
  int sum=0, sum15=0;
  int upperlimit;
  
  cout << "Please enter an upperlimit limit" << endl;
  cin >> upperlimit;
  
  for (x=0; x<upperlimit; x+=3)
  {
    sum += x;
  }
  
  for (y=0; y<upperlimit; y+=5)
  {
    sum += y;
  }
  
  for (z=0; z<upperlimit; z+=15)
  {
    sum15 += z;
  }
  
  sum = sum - sum15;
  
  cout << sum;
}
