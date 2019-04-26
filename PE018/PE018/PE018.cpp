#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int Clean_Input(std::vector <std::vector<int>> pyramid, int& row_counter, std::string input_line_x);

int main(void)
{
	std::ifstream file("PE018.txt");
	std::string input_line_x;
	std::vector <std::vector<int>> pyramid;
	int row_counter = 1;

	while (std::getline(file, input_line_x))
	{
		Clean_Input(pyramid, row_counter, input_line_x);
	}

	std::cout << row_counter << std::endl;

	getchar();
}