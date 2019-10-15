#include <iostream>
#include <vector>

int Binary_Search(std::vector<int> example, int target);

int main(void)
{
	std::vector<int> example { 2,3,4,10,40 };
	int target = 5;
	
	int result = Binary_Search(example, target);
	std::cout << result << std::endl;
}

int Binary_Search(std::vector<int> example, int target)
{
	/*return the location of the target*/

	int upper_bound = (example.size() - 1), midpoint, lower_bound = 0;

	while (lower_bound <= upper_bound)
	{
		//the binary search algorithm
		
		//update midpoint
		midpoint = (lower_bound + upper_bound) / 2;

		if (example[midpoint] == target)
			//the target is located in the middle
			return midpoint;

		else if (example[midpoint] < target)
			//the target is to the right of the middle
			lower_bound = midpoint + 1;

		else
			//the target is to the left of the middle
			upper_bound = midpoint - 1;
	}

	//the element is not present in the array
	return -1;
}