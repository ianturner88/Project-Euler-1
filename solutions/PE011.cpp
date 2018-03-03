#include <iostream>
#include <math.h>

using namespace std;

int main (void)
{
	int size = 20; 
	int matrix[size][size];
	int answer = 0;
	int x, y;
	int maintenant;
	
	for (y = 0; y < 20; y++)
	{
		for (x = 0; x < 20; x++)
		{
			cin >> matrix [x][y];
		}
	}
	
	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			// 
			if (x + 3 < size)
			{
				maintenant = matrix[x][y] * matrix[x][y]
			}
		}
	}
	
}
