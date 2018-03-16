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
	for (x = 0; x < 201; x += 200)
	{
		//sum = x;
		
		// 1 pound = 100
		for (y = 0; y < 301; y += 100)
		{
			
			//sum = x + y;
			
			// 50 pence = 50
			for (z = 0; z < 51; z += 5)
			{
				
				//sum = x + y + z;
				
				// 20 pence = 20
				for (w = 0; w < 101; w += 20)
				{
					
					//sum = x + y + z + w;
					
					// 10 pence = 10
					for (v = 0; v < 21; v += 10)
					{
						
						//sum = x + y + z + w + v;
						
						// 5 pence = 5
						for (u = 0; u < 41; u += 5)
						{
							
							//sum = x + y + z + w + u;
							
							// 2 pence = 2
							for (t = 0; t < 101; t += 2)
							{
								
								//sum = x + y + z + w + u + t;
								
								// 1 pence = 1
								for (s = 0; s < 201; s += 1)
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
