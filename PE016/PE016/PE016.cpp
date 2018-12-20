#include<string>
#include<iostream>
using namespace std;

void Compare_Size(string &number_2, string &current_sum);
void Calculate_Length_Both_Strings(string &number_2, int &number_2_length, string &current_sum,
	int &current_sum_length);
void Reverse_2_Strings(string &number_2, string &current_sum);
void LSB(string &number_2, string &current_sum, string &PE016_answer, int &carry, int &number_2_length);
void MSB(string &current_sum, int number_2_length, int current_sum_length,
	string &PE016_answer, int &carry);
void Carry(string &PE016_anwer, int &carry);
void Reset_Current_Sum_AND_PE016_answer(string &PE016_answer, string &current_sum, string &number_2);
void Answer(string &PE016_answer, string &current_sum);

int main(void)
{
	string number_2 = "2", current_sum = "", PE016_answer = "";
	int number_2_length = 0, carry = 0, current_sum_length = 0, exponent = 1;

	while (exponent < 1000)
	{
		/*programs driving algorithm...
		numbers are fed in one at a time*/

		//ensures current sum is the larger variable
		Compare_Size(number_2, current_sum);
		//calculate the length of the 2 strings
		Calculate_Length_Both_Strings(number_2, number_2_length, current_sum, current_sum_length);
		//reverse the 2 strings
		Reverse_2_Strings(number_2, current_sum);

		for (int multiplication = 1; multiplication < exponent; multiplication++)
		{
			/*simulates multiplication by having the 2 numbers added multiple times*/
			
			//add the LSB of the 2 strings
			LSB(number_2, current_sum, PE016_answer, carry, number_2_length);
			//add the not summed digits of the longer string
			MSB(current_sum, number_2_length, current_sum_length, PE016_answer, carry);
			//add carry
			Carry(PE016_answer, carry);
		}

		//update and clear the two variables
		Reset_Current_Sum_AND_PE016_answer(PE016_answer, current_sum, number_2);

		//upperbound
		exponent++;
	}

	//outut the first 10 digits of the final sum
	Answer(PE016_answer, current_sum);

	//system pause
	getchar();
}

void Answer(string &PE016_answer, string &current_sum)
{
	/*the final answer requires only the first 10 digits of the final sum*/

	PE016_answer = current_sum;

	cout << PE016_answer;
}

void Reset_Current_Sum_AND_PE016_answer(string &PE016_answer, string &current_sum, string &number_2)
{
	/*at the end of one cycle, these two variables are reset*/

	//PE013_answer is used to store the sum of current_sum & number_x
	current_sum = PE016_answer;
	//current_sum needs to be reset since it'll be reversed at the start of the cycle again
	reverse(current_sum.begin(), current_sum.end());
	//clear this variable so a new cycle may begin
	PE016_answer = "";
	//reset number_2
	number_2 = "2";
}

void Carry(string &PE016_anwer, int &carry)
{
	/*add the final hierarchical digit, if the digit exists*/

	if (carry == 1)
	{
		PE016_anwer.push_back(carry + '0');
	}
}

void MSB(string &current_sum, int number_2_length, int current_sum_length,
	string &PE016_answer, int &carry)
{
	/*add MSB of the larger string to PE013_answer*/

	//the MSB digits that need to be added to PE013_answer
	for (int i = number_2_length; i < current_sum_length; i++)
	{
		//test
		i;
		int check = (current_sum[i] - '0');
		carry;

		//sum remaining digits
		int sum = (current_sum[i] - '0') + carry;
		//store sum in answer
		PE016_answer.push_back((sum % 10) + '0');

		//check if sum exceeds 9
		carry = sum / 10;
	}
}

void LSB(string &number_2, string &current_sum, string &PE016_answer, int &carry, int &number_2_length)
{
	/*add the LSB of the 2 strings*/

	//reset carry variable
	carry = 0;

	for (int i = 0; i < number_2_length; i++)
	{
		/*loop cycle through the full length of the smaller string*/

		//sum of the index i value of the 2 strings
		int sum = ((number_2[i] - '0') + (current_sum[i] - '0') + carry);
		//store the resulting sum in the variable PE013_answer
		PE016_answer.push_back((sum % 10) + '0');
		//if the sum exceeds 9, there's a carry
		carry = sum / 10;
	}
}

void Reverse_2_Strings(string &number_2, string &current_sum)
{
	/*reverse the 2 strings*/
	reverse(number_2.begin(), number_2.end());
	reverse(current_sum.begin(), current_sum.end());
}

void Calculate_Length_Both_Strings(string &number_2, int &number_2_length, string &current_sum,
	int &current_sum_length)
{
	/*Calculate the length of the smaller string.
	Used as the upperlimit when adding the LSB of the 2 numbers*/

	current_sum_length = current_sum.length();
	number_2_length = number_2.length();
}

void Compare_Size(string &number_2, string &current_sum)
{
	/*compares the size of the two strings*/

	if (number_2.length() > current_sum.length())
	{
		//need to ensure the second variable is always the larger number
		swap(current_sum, number_2);
	}
}