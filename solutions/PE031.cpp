// 1 pence, 0.01; 2 pence, 0.02; 5 pence, 0.05; 10 pence, 0.1; 20 pence, 0.2; 50 pence, 0.5; 1 pound, 1; 2 pound, 2
// the above values are multiplied by 100, so 1 pence becomes 1, for example -> this makes the desired sum to be 200
#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	int sum = 0;
	int x, y, z, w, v, u, t, s;
	
	// 2 pound = 200
	for (s = 0; s < 201; s += 200)
	{
		
		// 1 pound = 100
		for (t = 0; t < 201; t += 100)
		{
		
			// 50 pence = 50
			for (u = 0; u < 201; u += 50)
			{
		
				// 20 pence = 20
				for (v = 0; v < 201; v += 20)
				{
		
					// 10 pence = 10
					for (w = 0; w < 201; w += 10)
					{
		
						// 5 pence = 5
						for (x = 0; x < 201; x += 5)
						{
		
							// 2 pence = 2
							for (y = 0; y < 201; y += 2)
							{
		
								// 1 pence = 1
								for (z = 0; z < 201; z += 1)
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
