#include<string>
#include<fstream>
#include<streambuf>
#include<iostream>
using namespace std;

void Length_Calculator(string &project_euler, int &project_euler_number_length);
void Retrieve_Digit(string &project_euler, int &digit_to_be_added, int &project_euler_number_length);
void Add_LSB(int &digit_to_be_added, string &digit_sum, int &carry, string &answer);
void Add_MSB(string &answer, int &carry, string &digit_sum);
void Equivalence(string &digit_sum, string &answer);
void Carry(string &answer, int &carry);
void Reverse(string &digit_sum, string &answer);
void ReadInFile(string &project_euler);

int main(void)
{
	//declaration of most variables needed
	string project_euler, digit_sum = "0", answer;
	int project_euler_number_length, n = 0, digit_sum_number_length;
	int digit_to_be_added, carry;

	//read required numbers into string
	ReadInFile(project_euler);
	//determines the number of iterations the code will run for
	Length_Calculator(project_euler, project_euler_number_length);
	//sets a hard cap on the central algorithm's number of cycles
	int limit = project_euler_number_length;

	//the algorithm driving the function
	while (n <= limit)
	{
		//retrieves the least significant digit of the string project_euler
		Retrieve_Digit(project_euler, digit_to_be_added, project_euler_number_length);
		//adds the least significant bits of the two strings
		Add_LSB(digit_to_be_added, digit_sum, carry, answer);
		//adds the most significant bits of the two strings
		Add_MSB(answer, carry, digit_sum);
		//adds the carry, if there is one
		Carry(answer, carry);
		//set the value of digit_sum equal to answer
		Equivalence(digit_sum, answer);
		n++;

		int Ian;

	}

	Reverse(digit_sum, answer);

	//forces pause
	int Ian;
	cout << answer;
	cin >> Ian;
	//
}

void Length_Calculator(string &project_euler, int &project_euler_number_length)
{
	/*This function calculates the length of the number who's digits
	are to be calculated. That information is needed to determine how
	long the code is to run for.*/

	project_euler_number_length = project_euler.length();

	//decrement the counter by 1 to account for the starting point 0 of the string array variable project_euler
	project_euler_number_length--;
}

void Retrieve_Digit(string &project_euler, int &digit_to_be_added, int &project_euler_number_length)
{
	/*This function retrieves the next digit from the variable project_euler
	to be added to the string digit_sum*/

	//retrieve the number to be added
	digit_to_be_added = (project_euler[project_euler_number_length] - '0');

	//decrement the counter by one so that next digit is retrieved next time
	project_euler_number_length--;
}

void Add_LSB(int &digit_to_be_added, string &digit_sum, int &carry, string &answer)
{
	/*Here, we add the least significant numbers of the strings. The counter
	is used to ensure that next digit to be added to the sum is added to the
	least sigificant digit*/

	//
	int test = (digit_sum[0] - '0');
	int test1 = digit_to_be_added;
	//

	//the sum of the 'next' digit & the digit_sum
	int sum = digit_to_be_added + (digit_sum[0] - '0');

	//the sum's first digit is added to the digit_sum
	answer.push_back(sum % 10 + '0');

	//if the number is greater than 9, there is a carry
	carry = sum / 10;
}

void Add_MSB(string &answer, int &carry, string &digit_sum)
{
	/*This code adds the most siginficant digits of the string digit_sum.
	The counter is used to retrieve the next number from the variable
	digit_sum */

	//sets a limit for the alogirthm to run
	int upperlimit = digit_sum.length();

	int MSBcounter = 1;

	while (MSBcounter < upperlimit)
	{
		//test
		int test = (digit_sum[MSBcounter] - '0');
		//

		//add the most significant digits to the string digit_sum
		int remainder = (digit_sum[MSBcounter] - '0') + carry;
		//add the MSB to the variable answer
		answer.push_back(remainder % 10 + '0');
		//if remainder is greater than 9, there's a need for a carry
		carry = remainder / 10;
		//to retrieve the next digit in the string digit_sum
		MSBcounter++;
	}
}

void Carry(string &answer, int &carry)
{
	/*If there's a carry left over from adding the most significant bits,
	we add the carry in this function*/

	if (carry == 1)
	{
		answer.push_back(carry + '0');
	}
}

void Equivalence(string &digit_sum, string &answer)
{
	/*We set digit sum equal to the value of answer
	and reset the string answer to zero.*/

	digit_sum = answer;
	answer = "";
}

void Reverse(string &digit_sum, string &answer)
{
	answer = digit_sum;

	reverse(answer.begin(), answer.end());
}

void ReadInFile(string &project_euler)
{
	/*reads in the numbers to be added into one string, project_euler*/

	//the required numbers are stored in text file PE013.txt
	ifstream fin("PE013.txt");

	//read file into string
	string Frisco((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

	project_euler = Frisco;
}