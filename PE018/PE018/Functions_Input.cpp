#include <iostream>
#include <vector>
#include <string>

#include "Functions_Input.h"

std::string Remove_Whitespace(std::string input_line_x)
{
	/*removes the whitespace found between the numbers */

	int i = 0;
	char Delimiter = ' ';

	while (input_line_x[i] == Delimiter)
	{
		//erases the white space from the string
		input_line_x.erase(0, 1);
		//continues until whitespace is gone
		i++;
	}

	/*the line has been truncated --> everything before and
	including the whitespace is deleted*/
	return input_line_x;
}

bool Is_Valid_Vector(std::vector <std::vector<int>> pyramid, int row_counter)
{
	/*ensures every row has one more element than the previous row*/

	bool is_valid_array = true;
	//accounts for 1st row being Row 0 & the comparision between n and (n+1)
	int pyramid_n_row_size = pyramid[0].size(), pyramid_nnext_row_size = pyramid[1].size();

	for (int i = 2; (i < row_counter) && (is_valid_array == true); i++)
	{
		if (pyramid_n_row_size == (pyramid_nnext_row_size + 1))
		{
			//the array does not have every row having exactly one more element than the previous row
			is_valid_array = false;
		}

		if (pyramid_nnext_row_size != (row_counter - 1))
		{
			//update --> new n & (n + 1) 
			pyramid_n_row_size = pyramid_nnext_row_size;
			pyramid_nnext_row_size = pyramid[i].size();
		}
	}

	return is_valid_array;
}