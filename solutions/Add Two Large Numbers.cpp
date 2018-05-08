#include<bits/stdc++.h>
using namespace std;

void Berlin(N1, N2);

int main (void)
{
	string N1 = '1297';
	string N2 = '3829';
	Berlin (NumberOne, NumberTwo);
}

Berlin(N1, N2)
{
	// find the longer of the two numbers and make the longer one N1
	if (N1.length < N2.length)
	{
		swap(N1, N2);
	}
	
	// find the length of the two strings (aka numbers) to setup a counter
	int L1 = N1.length;
	int L2 = N2.length;
	
	// the sum is the value of the N1's & N2's [int i] spot are added together and stored in 'sum'
	int sum = 0;
	
	// carry will always have a value of 1 or 0 and is the 10's spot value of the variable 'sum'. For example, 9 + 9 would give a carry of 1
	int carry = 0;
	
	// we set a counter equal to one less than the smaller number's size. So if 19 and 2300 were added, we would only add 19 + 00 in this loop 
	for (int i = L1 - 1; i >= 0; i--)
	{
		sum = ((N1[i] - '0') + (N2[i] - '0') + carry);
		carry = sum / 10; 
	}
	
	// we have not yet added the 23 in 2300 to the sum - which is what we do in this loop.
	// there is no need for a carry since N2 has no values to be added with N1
	for (int i = L1 - L2 - 1; i >= 0; i--)
	{
		sum = (N1[i] - '0');
	}
}
