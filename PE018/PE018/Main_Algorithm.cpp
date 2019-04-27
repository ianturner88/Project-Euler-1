#include <vector>
#include <iostream>

#include "Functions_Algorithm.h"

int Algorithm(std::vector <std::vector<int>> pyramid, int row_counter)
{
	//accounts for 1st row being row 0
	row_counter -= 1;

	return 0;
}

int Compare_Elements_of_Row_N(std::vector<int>& maximized_row, std::vector <std::vector<int>> pyramid, 
	int row_counter)
{
	/*Compare all adjacent pairs of numbers. Place the greater of the 2 pairs in the newly formed maximized_row*/
	
	for (int i = 0; i < pyramid[row_counter].size(); i++)
	{
		/*cycle through the line*/
	}
}