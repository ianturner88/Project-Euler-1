#include <iostream>
#include <math.h>

using namespace std;

int main (void)
{
	int n = 2;
	int r;
	int rsum;
	int answer = 0;
	int sum;
	int dummynumber;
	
	while (n < pow(10, 7))
	{
		n++;
		rsum = 1;
		sum = 0;
		dummynumber = n;
		
		while(dummynumber > 0)
		{
			r = dummynumber % 10;
			dummynumber = dummynumber / 10;
			rsum = 1;
			
			while (r > 0)
			{
				rsum *= r;
				
				r--; 
			}
			
			sum += rsum;	
		}
			
		if (sum == n)
		{
			answer += n;
			cout << n << endl;
		}
	}
	
	cout << "Answer: " << answer;
}
