#include<string>
#include<fstream>
#include<streambuf>
#include<iostream>
using namespace std;

void Compare_Size(string &number_x, string &current_sum);
void Calculate_Length_Two_Strings(string &number_x, string &current_sum, int &number_x_length,
	int &current_sum_length);

int main(void)
{
	ifstream PE013_Input_File("PE013.txt");
	string number_x, current_sum = "", PE013_answer = "";
	int number_x_length = 0, current_sum_length = 0;

	while (getline(PE013_Input_File, number_x))
	{
		/*programs driving algorithm...
		numbers are fed in one at a time*/
		
		//ensures current sum is the larger variable
		Compare_Size(number_x, current_sum);
		//calculate the length of the 2 strings
		Calculate_Length_Two_Strings(number_x, current_sum, number_x_length, current_sum_length);
	}

	//system pause
	getchar();
}

void Reverse_2_Strings(string &number_x, string &current_sum)
{
	/*reverse the 2 strings*/
	reverse(number_x.begin(), number_x.end());
	reverse(current_sum.begin(), current_sum.end());
}

void Calculate_Length_Two_Strings(string &number_x, string &current_sum, int &number_x_length, 
	int &current_sum_length)
{
	/*Calculate the length of the 2 strings*/
	
	number_x_length = number_x.length();
	current_sum_length = current_sum.length();
}

void Compare_Size(string &number_x, string &current_sum)
{
	/*compares the size of the two strings*/

	if (number_x.length() > current_sum.length())
	{
		//need to ensure the second variable is always the larger number
		swap(current_sum, number_x);
	}
}