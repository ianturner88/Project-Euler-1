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