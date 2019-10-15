#include <vector>
#include <iostream>
#include <algorithm>

void Print(std::vector<int> example);
void Add_Contents(std::vector<int>& example, int multiplier);
void Add_Numbers(std::vector<int>& example, int starting_point);

int main(void)
{
	std::vector<int> example;
	/*
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

	std::cout << "Round 4: " << std::endl;

	example.clear();
	Print(example);
	*/

	Add_Numbers(example, 0);
	//Print(example);

	Add_Numbers(example, 1);
	//Print(example);

	std::sort(example.begin(), example.end());
	Print(example);
}

void Add_Numbers(std::vector<int>& example, int starting_point)
{
	//add numbers to the vector
	for (int i = 0; i < 1000000; (i+=2))
	{
		example.push_back(starting_point + i);
	}
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