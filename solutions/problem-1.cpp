#include <iostream>
using namespace std;
int main (void)
{
  int five, three, fifteen;
  int UpperLimit;
  int sum53 = 0, sum15 = 0;
  int sumtotal = 0;
  cout << "Please enter a number";
  cin >> UpperLimit;
  for (five = 0; five < UpperLimit; five += 5)
  {
    sum53 = sum53 + five;
  }
  
  for (three = 0; three < UpperLimit; three += 3)
  {
    sum53 = sum53 + three; 
  }
  
  for (fifteen = 0; fifteen < UpperLimit; fifteen += 15)
  {
    sum15 = sum15 + fifteen; 
  } 
  
  sumtotal = sum53 - sum15;
  
  cout << sumtotal;
}
