// 1 pence, 0.01; 2 pence, 0.02; 5 pence, 0.05; 10 pence, 0.1; 20 pence, 0.2; 50 pence, 0.5; 1 pound, 1; 2 pound, 2

#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	int sum = 0;
	int x, y, z, w, v, u, t, s;
	
	for (x = 0; x < 200; x += 1)
	{
		for (y = 0; y < 100; y += 2)
		{
			for (z = 0; z < 40; z += 5)
			{
				for (w = 0; w < 20; z += 20)
				{
					for (v = 0; v < 10; v += 10)
					{
						for (u = 0; u < 4; u += 4)
						{
							for (t = 0; t < 2; t += 2)
							{
								for (s = 0; s < 1; s += 1)
								{
									sum = x + y + z + w + v + u + t + s;
									
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
		}
	}
	
	cout << count;
}
