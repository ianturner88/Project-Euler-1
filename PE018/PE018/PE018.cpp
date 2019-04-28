#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <iostream>

#include "Functions_Input.h"
#include "PE018.h"
#include "ProjectEulerLibrary/ProjectEulerLibrary.h"

int main(void)
{
	std::ifstream file("PE018.txt");
	std::string input_line_x;
	std::vector <std::vector<int>> pyramid;
	int row_counter = 1, final_answer;
	clock_t time_total;
	double duration;

	//start clock
	time_total = clock();

	while (std::getline(file, input_line_x))
	{
		/*reads file in & converts to integer*/
		Clean_Input(pyramid, row_counter, input_line_x);
	}

	//ensures every row n has one fewer elements than (n + 1)
	bool is_valid_vector = Is_Valid_Vector(pyramid, row_counter);

	if (is_valid_vector == true)
	{
		//identifies the maximal sum 
		final_answer = Algorithm(pyramid, row_counter);
	}

	std::cout << "The answer is: " << final_answer << std::endl;

	//output time
	Euler::Time(time_total);

	getchar();
}