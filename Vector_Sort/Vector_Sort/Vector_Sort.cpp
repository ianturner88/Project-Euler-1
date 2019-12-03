#include<iostream> 
#include<vector> 
#include<algorithm> 

bool sort_vectors(const std::vector<int>& v1, const std::vector<int>& v2);
void Print(std::vector<std::vector<int>> testcase);

int main(void)
{
	std::vector<std::vector<int>> testcase = { {3,4,5},{9,8,0},{4,3,2} };

	std::cout << "Sorted:" << std::endl;
	Print(testcase);
	sort(testcase.begin(), testcase.end(), sort_vectors);
	std::cout << "Unsorted:" << std::endl;
	Print(testcase);
}

bool sort_vectors(const std::vector<int>& v1, const std::vector<int>& v2)
{
	return v1[0] < v2[0];
}

void Print(std::vector<std::vector<int>> testcase)
{
	for (int i = 0; i < testcase.size(); i++)
	{
		for (int j = 0; j < testcase[0].size(); j++)
		{
			std::cout << testcase[i][j] << " ";
		}

		std::cout << std::endl;
	}
}