#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

#include "PE081.h"
#include "Clean_Input.h"
#include "Minimal_Path.h"

int main()
{
	std::string input_line;
	std::ifstream input_file("PE081.txt");
	std::vector<std::string> pe081_matrix_string;
	PE081_Matrix pe081_matrix[NxN][NxN];
	clock_t timeStamp = clock();

	if (input_file.is_open())
	{
		//read in the file
		while (getline(input_file, input_line))
		{
			pe081_matrix_string.push_back(input_line);
		}
		input_file.close();
	}
	// the file did not exist
	else std::cout << "Unable to open file";

	Construct_Object_Array(pe081_matrix_string, pe081_matrix);

	//initialize the first element's minimal path
	pe081_matrix[0][0].cheapest_sum = pe081_matrix[0][0].element_value;
	//initialize the first element's cheapest path
	pe081_matrix[0][0].cheapest_path.push_back(pe081_matrix[0][0].element_value);

	std::cout << "Total executon time: " << (float)timeStamp / CLOCKS_PER_SEC << " seconds." << std::endl;

	std::cout << "The minimal path across the " << NxN << " x " << NxN << " matrix is: " 
		<< Minimal_Path_Sum(pe081_matrix) << std::endl;

	Print_Shortest_Path(pe081_matrix);

	getchar();

	return 0;
}

void Print_Shortest_Path(PE081_Matrix pe081_matrix[NxN][NxN])
{
	/*Prints the shortest path across the matrix*/

	int test = pe081_matrix[(NxN - 1)][(NxN - 1)].cheapest_path.size();
	int test0 = pe081_matrix[(NxN - 1)][(NxN - 1)].element_value;

	for (int i = 1; i < pe081_matrix[(NxN - 1)][(NxN - 1)].cheapest_path.size(); i++)
	{
		std::cout << pe081_matrix[(NxN - 1)][(NxN - 1)].cheapest_path[i] << " -> ";
	}

	std::cout << pe081_matrix[(NxN - 1)][(NxN - 1)].element_value;
}