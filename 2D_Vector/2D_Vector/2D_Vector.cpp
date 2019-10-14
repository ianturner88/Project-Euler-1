#include <vector>
#include <iostream>

int main()
{
	//define a vector of vectors
	std::vector <std::vector <int>> sample;

	for (int i = 0; i < 3; i++)
	{
		std::vector <int> temp;

		for (int j = 0; j < 3; j++)
		{
			temp.push_back(i);
		}

		sample.push_back(temp);
	}

	for (int i = 0; i < sample.size(); i++)
	{
		for (int j = 0; j < sample[i].size(); j++)
		{
			std::cout << sample[i][j];
		}

		std::cout<< std::endl;
	}

}