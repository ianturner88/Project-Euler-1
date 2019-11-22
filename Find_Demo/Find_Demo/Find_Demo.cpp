#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> testcase = { 3,4,5,6 };

	for (int i = 0; i < testcase.size(); i++)
	{
		std::cout << testcase[i] << std::endl;
	}
}