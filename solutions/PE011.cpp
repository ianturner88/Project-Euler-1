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
			// left to right horizontally
			if (x + 3 < size)
			{
				maintenant = matrix[x][y] * matrix[x + 1][y] * matrix[x + 2][y] * matrix[x + 3][y];
				
				if (maintenant > answer)
				{
					answer = maintenant;
				}
			}
			
			// top to bottom
			if (x + 3 < size)
			{
				maintenant = matrix[x][y] * matrix[x][y + 1] * matrix[x][y + 2] * matrix[x][y + 3];
				
				if (maintenant > answer)
				{
					answer = maintenant;
				}
			} 
			
			// rightside is down
			if (x + 3 < size)
			{
				maintenant = matrix[x][y] * matrix[x + 1][y + 1] * matrix[x + 2][y + 2] * matrix[x + 3][y + 3];
				
				if (maintenant > answer)
				{
					answer = maintenant;
				}
			}
			
			// leftside is down
			if (x > 0)
			{
				maintenant = matrix[x - 20][y -20] * matrix[x - 19][y - 19] * matrix[x - 18][y - 18] * matrix[x - 17][y - 17];
				
				if (maintenant > answer)
				{
					answer = maintenant;
				}
			}
		}
	}
	
	cout << answer;
}
