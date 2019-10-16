#include <iostream>
#include <vector>

void Insert_Numbers(std::vector<int>& temp, int starting_number);
void Print_All_Contents(std::vector <std::vector <int>> example);
int TwoD_Vector_BinarySearch(std::vector <std::vector <int>> example, int column_to_search, int target);

int main(void)
{
	std::vector <std::vector <int>> example;
	std::vector <int> temp;

	Insert_Numbers(temp, 0);
	example.push_back(temp);
	Insert_Numbers(temp, 3);
	example.push_back(temp);
	Insert_Numbers(temp, 6);
	example.push_back(temp);

	Print_All_Contents(example);

	int index = TwoD_Vector_BinarySearch(example, 0, 2);

	std::cout << "Index: " << index << std::endl;
}

int TwoD_Vector_BinarySearch(std::vector <std::vector <int>> example, int column_to_search, int target)
{
	//a[MAX_ROWS][MAX_COLS]

	/*return the location of the target*/

	int upper_bound = (example.size() - 1), midpoint, lower_bound = 0;

	while (lower_bound <= upper_bound)
	{
		//the binary search algorithm

		//update midpoint
		midpoint = (lower_bound + upper_bound) / 2;

		if (example[midpoint][0] == target)
			//the target is located in the middle
			return midpoint;

		else if (example[midpoint][0] < target)
			//the target is to the right of the middle
			lower_bound = midpoint + 1;

		else
			//the target is to the left of the middle
			upper_bound = midpoint - 1;
	}

	//the element is not present in the array
	return -1;
}

void Print_All_Contents(std::vector <std::vector <int>> example)
{
	//print all the contents of the vector
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
	//reset temporary vector
	temp.clear();

	//store numbers in the vector
	for (int j = 0; j < 3; j++)
	{
		temp.push_back(starting_number);
		starting_number++;
	}
}