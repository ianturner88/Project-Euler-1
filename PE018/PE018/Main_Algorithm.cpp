#include <vector>
#include <iostream>

#include "Functions_Algorithm.h"

void Initialization(std::vector <std::vector<int>> pyramid, int row_counter, std::vector<int> &maximized_row);

int Algorithm(std::vector <std::vector<int>> pyramid, int row_counter)
{
	std::vector<int> maximized_row, answer;
	//accounts for 1st row being row 0
	row_counter -= 2;
	int starting_point = row_counter;

	Initialization(pyramid, row_counter, maximized_row);

	for (int i = starting_point; i > 0; i--)
	{
		//determine & store which number of all adjacent pairs is greater in vector maximized_row
		Compare_Elements_of_Row_N(maximized_row, pyramid, row_counter, answer);
		
		maximized_row = answer;
		answer.clear();
		//move counter towards Row 0
		row_counter--;

		//add maximized_row with the row of equivalent size in pyramid
		Add_Bottom_Two_Rows(maximized_row, pyramid, row_counter, answer);
		
		//update
		maximized_row = answer;
		//reset
		answer.clear();
	}

	//answer to question 18 of Project Euler
	return maximized_row[0];
}

void Initialization(std::vector <std::vector<int>> pyramid, int row_counter, std::vector<int> &maximized_row)
{
	/*retrieve the first row from pyramid */
	for (int i = 0; i < pyramid[row_counter].size(); i++)
	{
		//make copy in maximized_row
		maximized_row.push_back(pyramid[row_counter][i]);
	}
}