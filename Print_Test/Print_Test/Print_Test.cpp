#include <iostream>
#include <vector>

void Print(std::vector<std::vector<int>> testcase);

int main(void)
{
	std::vector<std::vector<int>> testcase = { {4,5},{6,4},{2,1} };

	Print(testcase);
}

void Print(std::vector<std::vector<int>> testcase)
{
	for (int i = 0; i < testcase.size(); i++)
	{
		for (int j = 0; j < testcase[i].size(); j++)
		{
			std::cout << testcase[i][j] << " ";
		}

		std::cout << std::endl;
	}
}