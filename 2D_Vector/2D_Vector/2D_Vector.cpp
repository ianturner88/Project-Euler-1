#include <vector>
#include <iostream>
#include <algorithm>

void Insert_Numbers(std::vector<int>& temp, int starting_number);
void Print_All_Contents(std::vector <std::vector <int>> example);

int main()
{
	//define a vector of vectors
	std::vector <std::vector <int>> example;
	std::vector<int> temp;

	Insert_Numbers(temp, 6);
	example.push_back(temp);

	Insert_Numbers(temp, 3);
	example.push_back(temp);
	
	Insert_Numbers(temp, 0);
	example.push_back(temp);

	//Print_All_Contents(example);

	std::sort(example.begin(), example.end());
	Print_All_Contents(example);
}

void Print_All_Contents(std::vector <std::vector <int>> example)
{
	for (int i = 0; i < example.size(); i++)
	{
		for (int j = 0; j < example[i].size(); j++)
		{
			std::cout << example[i][j];
		}

		std::cout << std::endl;
	}
}

void Insert_Numbers(std::vector<int>& temp, int starting_number)
{
	temp.clear();

	//store numbers in the vector
	for (int j = 0; j < 3; j++)
	{
		temp.push_back(starting_number);
		starting_number++;
	}
}