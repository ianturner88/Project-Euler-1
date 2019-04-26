#include <iostream>
#include <vector>
#include <string>

std::string Remove_Whitespace(std::string input_line_x)
{
	/*removes the whitespace found between the numbers */

	int i = 0;
	char Delimiter = ' ';

	while (input_line_x[i] == Delimiter)
	{
		//continues until whitespace is gone
		i++;
	}

	/*the line has been truncated --> everything before and
	including the whitespace is deleted*/
	return input_line_x;
}