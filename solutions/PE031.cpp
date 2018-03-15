// 1 pence, 0.01; 2 pence, 0.02; 5 pence, 0.05; 10 pence, 0.1; 20 pence, 0.2; 50 pence, 0.5; 1 pound, 1; 2 pound, 2
// the above values are multiplied by 100, so 1 pence becomes 1, for example -> this makes the desired sum to be 200
#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	int sum = 0;
	int x, y, z, w, v, u, t, s;
	int upperlimit = 201;
	
	for (x = 0; x < 3; x += 1)
	{
		sum = x;
		
		for (y = 0; y < 4 && sum < upperlimit; y += 2)
		{
			
			sum = x + y;
			
			for (z = 0; z < 6 && sum < upperlimit; z += 5)
			{
				
				sum = x + y + z;
				
				for (w = 0; w < 11 && sum < upperlimit; z += 20)
				{
					
					sum = x + y + z + w;
					
					for (v = 0; v < 21 && sum < upperlimit; v += 10)
					{
						
						sum = x + y + z + w + v;
						
						for (u = 0; u < 41 && sum < upperlimit; u += 4)
						{
							
							sum = x + y + z + w + u;
							
							for (t = 0; t < 101 && sum < upperlimit; t += 2)
							{
								
								sum = x + y + z + w + u + t;
								
								for (s = 0; s < 201 && sum < upperlimit; s += 1)
								{
									sum = x + y + z + w + v + u + t + s;
									
									if (sum == 200)
									{
										count++;
									}
									
									sum = 0;
								}
							}
						}
					}
				}
			}
		}
	}
	
	cout << count;
}
