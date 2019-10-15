#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> example;

	for (int i = 0; i < 5; i++)
	{
		//store large numbers
		example.push_back(i*4);
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << example[i] << std::endl;
	}

	for (int i = 0; i < 5; i++)
	{
		//store small numbers
		example.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << example[i] << std::endl;
	}
}