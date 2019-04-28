#include <vector>
#include <iostream>

#include "Functions_Algorithm.h"

int Compare_Elements_of_Row_N(std::vector<int> &maximized_row, std::vector <std::vector<int>> pyramid,
	int row_counter, std::vector<int> &answer)
{
	/*Compare all adjacent pairs of numbers. Place the greater of the 2 pairs in the newly formed maximized_row
	example: 8  5  9  3
	becomes: 8  9  9
	*/

	int element_n, element_n_plus_one;

	for (int i = 0; (i < pyramid[row_counter].size()) && (i < row_counter); i++)
	{
		/*cycle through the line, doing comparisons*/

		//the nth element of a given row
		int element_n = maximized_row[i];
		//the (nth + 1) element of a given row
		int element_n_plus_one = maximized_row[i + 1];

		if (element_n_plus_one > element_n)
		{
			//the max value is saved
			element_n = element_n_plus_one;
		}

		//the max value is stored
		answer.push_back(element_n);
	}

	return 0;
}

int Add_Bottom_Two_Rows(std::vector<int> &maximized_row, std::vector <std::vector<int>> pyramid, int row_counter,
	std::vector<int> &answer)
{
	/*add the elements of the bottom row of pyramid to the elements of the maximized_row
	pyramid row 3 = 2    4    6
	maximized_row = 8    9    9
	----------------------------
	answer        = 10   13   15  */

	int element_sum;

	if (maximized_row.size() == pyramid[row_counter].size())
	{
		//checks that the 2 vectors are of similar size

		for (int i = 0; i < maximized_row.size(); i++)
		{
			//add the ith elements together
			element_sum = (maximized_row[i] + pyramid[row_counter][i]);
			//store the result
			answer.push_back(element_sum);
		}
	}

	else
	{
		//there is a mismatch in size between the 2 vectors
		std::cout << "PROBLEM: The size of the two vector's rows is not equal!!!";
	}

	return 0;
}