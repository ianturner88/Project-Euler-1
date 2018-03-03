#include <iostream>
#include <math.h>

using namespace std;

int main (void)
{
	int n = 40584;
	int r;
	int rsum;
	int answer = 0;
	int sum;
	int dummynumber;
	
	while (n < 40586)
	{
		n++;
		rsum = 1;
		sum = 0;
		dummynumber = n;
		
		while(dummynumber > 1)
		{
			r = dummynumber % 10;
			dummynumber = dummynumber / 10;
			rsum = 1;
			
			while (r > 1)
			{
				rsum *= r;
				
				r--; 
			}
			
			if (r != 0)
			{
				sum += rsum;	
			}
		}
		
		sum += 1;
		
		if (sum == n)
		{
			answer += n;
			cout << n << endl;
		}
	}
	
	cout << answer;
}
