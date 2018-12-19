#include<string>
#include<fstream>
#include<streambuf>
#include<iostream>
using namespace std;

void Compare_Size(string &number_x, string &current_sum);
void Calculate_Length_Smaller_String(string &number_x, int &number_x_length);
void Reverse_2_Strings(string &number_x, string &current_sum);
void LSB(string &number_x, string &current_sum, string &PE013_answer, int &carry, int &number_x_length);

int main(void)
{
	ifstream PE013_Input_File("PE013.txt");
	string number_x, current_sum = "", PE013_answer = "";
	int number_x_length = 0, carry = 0;

	while (getline(PE013_Input_File, number_x))
	{
		/*programs driving algorithm...
		numbers are fed in one at a time*/
		
		//ensures current sum is the larger variable
		Compare_Size(number_x, current_sum);
		//calculate the length of the 2 strings
		Calculate_Length_Smaller_String(number_x, number_x_length);
		//reverse the 2 strings
		Reverse_2_Strings(number_x, current_sum);
		//add the LSB of the 2 strings
		LSB(number_x, current_sum, PE013_answer, carry, number_x_length);
	}

	//system pause
	getchar();
}

void MSB(string &current_sum, int &number_x_length, int current_sum_length, 
	string &PE013_answer, int &carry)
{
	/*add MSB of the larger string to PE013_answer*/

	//the MSB digits that need to be added to PE013_answer
	for (int i = 0; ; );


}

void LSB(string &number_x, string &current_sum, string &PE013_answer, int &carry, int &number_x_length)
{
	/*add the LSB of the 2 strings*/
	
	//reset carry variable
	carry = 0;

	for (int i = 0; i < number_x_length; i++)
	{
		/*loop cycle through the full length of the smaller string*/
		
		//sum of the index i value of the 2 strings
		int sum = ((number_x[i] - '0') + (current_sum[i] - '0') + carry);
		//store the resulting sum in the variable PE013_answer
		PE013_answer.push_back((sum % 10) + '0');
		//if the sum exceeds 9, there's a carry
		carry = sum / 10;
	}
}

void Reverse_2_Strings(string &number_x, string &current_sum)
{
	/*reverse the 2 strings*/
	reverse(number_x.begin(), number_x.end());
	reverse(current_sum.begin(), current_sum.end());
}

void Calculate_Length_Smaller_String(string &number_x, int &number_x_length)
{
	/*Calculate the length of the smaller string.
	Used as the upperlimit when adding the LSB of the 2 numbers*/
	
	number_x_length = number_x.length();
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