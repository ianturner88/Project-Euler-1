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
	
	// 2 pound = 200
	for (x = 0; x < upperlimit && sum < upperlimit; x += 200)
	{
		sum = x;
		
		// 1 pound = 100
		for (y = 0; y < upperlimit && sum < upperlimit; y += 100)
		{
			
			sum = x + y;
			
			// 50 pence = 50
			for (z = 0; z < upperlimit && sum < upperlimit; z += 5)
			{
				
				sum = x + y + z;
				
				// 20 pence = 20
				for (w = 0; w < upperlimit && sum < upperlimit; w += 20)
				{
					
					sum = x + y + z + w;
					
					// 10 pence = 10
					for (v = 0; v < upperlimit && sum < upperlimit; v += 10)
					{
						
						sum = x + y + z + w + v;
						
						// 5 pence = 5
						for (u = 0; u < upperlimit && sum < upperlimit; u += 5)
						{
							
							sum = x + y + z + w + u;
							
							// 2 pence = 2
							for (t = 0; t < upperlimit && sum < upperlimit; t += 2)
							{
								
								sum = x + y + z + w + u + t;
								
								// 1 pence = 1
								for (s = 0; s < upperlimit && sum < upperlimit; s += 1)
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
