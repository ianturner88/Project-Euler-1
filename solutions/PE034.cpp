#include <iostream>
#include <math.h>

using namespace std;

int main (void)
{
	int n = 144;
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
		
		//8! = 40320     
		//1! = 1 (40321)        
		//3! = 6 (40327)         
		//6! = 720 (41047)             
		//8! = 40320 (81367)
			
		if (sum == n)
		{
			answer += n;
			cout << n << endl;
		}
	}
	
	cout << "Answer: " << answer;
}
