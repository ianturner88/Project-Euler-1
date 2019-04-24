#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string Create_Tokens(std::string input_line_x);

int main(void)
{
	std::ifstream file("PE018.txt");
	std::string input_line_x;
	std::vector<int> pyramid;

	while (std::getline(file, input_line_x))
	{
		std::cout << input_line_x << std::endl;
	}

	getchar();
}

std::string Create_Tokens(std::string input_line_x)
{
	/*parse the individual numbers*/
	
	char character;
	std::string pyramid_number;
	
	for (int i = 0; i < input_line_x.length(); i++)
	{
		//identify each element of the line
		character = input_line_x[i];

		while (character != ' ')
		{
			//reconstructs the number
			pyramid_number += character;
		}
	}
}