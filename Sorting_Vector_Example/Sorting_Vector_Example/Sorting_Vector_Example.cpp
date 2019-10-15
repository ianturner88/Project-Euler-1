#include <vector>
#include <iostream>
#include <algorithm>

void Print(std::vector<int> example);
void Add_Contents(std::vector<int>& example, int multiplier);

int main(void)
{
	std::vector<int> example;

	std::cout << "Round 1: " << std::endl;

	//round 1
	Add_Contents(example, 4);
	Print(example);

	std::cout << "Round 2: " << std::endl;

	//round 2
	Add_Contents(example, 1);
	Print(example);

	std::cout << "Round 3: " << std::endl;

	std::sort(example.begin(), example.end());
	Print(example);
}

void Print(std::vector<int> example)
{
	//print vector contents
	
	for (int i = 0; i < example.size(); i++)
	{
		std::cout << example[i] << std::endl;
	}
}

void Add_Contents(std::vector<int>& example, int multiplier)
{
	//add numbers to the vector
	for (int i = 0; i < 5; i++)
	{
		//store large numbers
		example.push_back(i * multiplier);
	}
}