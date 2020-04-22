#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

#include "PE082.h"
#include "Clean_Input.h"
#include "Minimal_Path.h"

int main()
{
	std::string input_line;
	std::ifstream input_file("PE081.txt");
	std::vector<std::string> pe082_matrix_string;
	PE082_Matrix pe082_matrix[NxN][NxN];
	clock_t timeStamp = clock();

	if (input_file.is_open())
	{
		//read in the file
		while (getline(input_file, input_line))
		{
			pe082_matrix_string.push_back(input_line);
		}
		input_file.close();
	}
	// the file did not exist
	else std::cout << "Unable to open file";

	Construct_Object_Array(pe082_matrix_string, pe082_matrix);

	//initialize the first element's minimal path
	pe082_matrix[0][0].cheapest_sum = pe082_matrix[0][0].element_value;
	//initialize the first element's cheapest path
	pe082_matrix[0][0].cheapest_path.push_back(pe082_matrix[0][0].element_value);

	std::cout << "Total executon time: " << (float)timeStamp / CLOCKS_PER_SEC << " seconds." << std::endl;

	std::cout << "The minimal path across the " << NxN << " x " << NxN << " matrix is: " 
		<< Minimal_Path_Sum(pe082_matrix) << std::endl;

	Print_Shortest_Path(pe082_matrix);

	getchar();

	return 0;
}

void Print_Shortest_Path(PE082_Matrix pe081_matrix[NxN][NxN])
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