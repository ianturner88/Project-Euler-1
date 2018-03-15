#include <iostream>
using namespace std;

int main()
{
	int count;
	int x, y, z;
	int sum = 0;
	
	for	(x = 0; x < 11 && sum < 11; x += 3)
	{
		sum = 0;
		sum = x;
		
		for ( y = 0; y < 11 && sum < 11; y += 2)
		{
			sum = 0;
			sum = x + y;
			
			for (z = 0; z < 11 && sum < 11; z++)
			{
				sum = x + y + z;
				
				if (sum == 10)
				{
					count++;
				}
				
				sum = 0;
			}
		}
	}
	
	cout << count;
}
