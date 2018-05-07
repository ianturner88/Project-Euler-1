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
	if (N1.length < N2.length)
	{
		swap(N1, N2);
	}
	
	int L1 = N1.length;
	int L2 = N2.length;
	int sum = 0;
	int carry = 0;
	
	for (int i = L1 - 1; i >= 0; i--)
	{
		sum = ((N1[i] - '0') + (N2[i] - '0') + carry);
		carry = sum / 10; 
	}
	
	
}
