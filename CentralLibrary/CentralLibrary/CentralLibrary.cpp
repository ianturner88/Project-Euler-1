#include <vector>
#include <algorithm>

#include "CentralLibrary.h"

bool Is_Pandigital(int input_number);

namespace Euler
{
	////////////////////////////////////////////////////////////////////////////////
	// DETERMINES IF A NUMBER IS PANDIGITAL OR NOT

	bool Is_Pandigital(int input_number)
	{
		/*determines if a number is pandigital*/

		std::vector<int> temp;
		int single_digit;
		bool is_pandigital = true;

		while (input_number > 0)
		{
			//identify the last digit 
			single_digit = input_number % 10;
			//store the last digit
			temp.push_back(single_digit);
			//shrink the input number so that the next 'last' digit may be found
			input_number /= 10;
		}

		//sort the numbers from descending to increasing
		std::sort(temp.begin(), temp.end());

		for (int i = 0; (i < temp.size()) && (is_pandigital == true); i++)
		{
			//check if the i-th vector element equals i
			//example slot 3 should have a value of 3
			if ((i + 1) != temp[i])
			{
				//the number is not pandigital
				is_pandigital = false;
			}
		}

		return is_pandigital;
	}
}