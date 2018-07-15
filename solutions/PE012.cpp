#include <iostream>
#include <math.h>
using namespace std;

void Triangle_Number_Generator(int &i, int &triangle_number);
void Number_Divisor_Check(int &triangle_number, int &number_divisors, bool &condition);
void Answer(int &triangle_number, bool &condition);

int main()
{
	int i = 0, triangle_number = 0, number_divisors = 0, x; 
	bool condition = true;

	while (condition == true)
	{
		Triangle_Number_Generator(i, triangle_number);
		Number_Divisor_Check(triangle_number, number_divisors, condition);
		//Answer(triangle_number, condition);
	}

	cout << "Please enter input";
	cin >> x;
}

void Triangle_Number_Generator(int &i, int &triangle_number)
{
	/*Generates triangle numbers*/
	
	i++;
	triangle_number += i;
}

void Number_Divisor_Check(int &triangle_number, int &number_divisors, bool &condition)
{
	/*Counts the number of divisors of a given triangle number*/
	
	int upperlimit = pow(triangle_number, 0.5), divisor = 2;
	number_divisors = 2;

	if (triangle_number == 76576500)
	{
		int x = 0;
	}

	while (divisor < upperlimit)
	{
		if (triangle_number % divisor == 0)
		{
			number_divisors += 2;
		}

		divisor++;
	}

	/*We output the answer is there are more than 500 divisors.
	Otherwise, we reset the number of divisors to zero.*/

	if (number_divisors > 500)
	{
		Answer(triangle_number, condition);
	}

	else
	{
		number_divisors = 0;
	}
}

void Answer(int &triangle_number, bool &condition)
{
	/*Prints the answer*/

	cout << triangle_number << endl << endl;

	condition = false;
}
