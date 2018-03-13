// 1 pence, 2 pence, 5 pence, 10 pence, 20 pence, 50 pence, 1 pound, 2 pound

#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	int sum = 0;
	int x;
	
	while (sum < 2)
	{
		while (sum < 2)
		{
			x = 0.01;
			
			sum += x;
			
			if (sum == 2)
			{
				count++;
			}
			
			while (sum < 2)
			{
				x = 0.02;
				
				sum += x;
				
				if (sum == 2)
				{
					count++;
				}
				
				while (sum < 2)
				{
					x = 0.05;
					
					sum += x;
					
					if (sum == 2)
					{
						count++;
					}
					
					while (sum < 2)
					{
						x = 0.1;
						
						sum += x;
						
						if (sum == 2)
						{
							count++;
						}
					}
				}
			}
		}
	}
}
