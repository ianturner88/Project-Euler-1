#include<iostream>
#include<string>
using namespace std;

void Generate_Second_String(string &pe0, string &pe1);
void Reverse_Strings(string &pe0);
void Add_LSB(string &pe0, string &pe1, string &answer, int &counter, int &carry);
void Carry(string &answer, int &carry);

int main(void)
{
	string pe0 = "1234", pe1, answer;
	int exponent = 0, counter, carry = 0;

	//reverses the numerical string
	Reverse_Strings(pe0);

	while (exponent < 15)
	{
		/*the algorithm driving the program & 
		the counter acts as the exponent*/
		
		//reset counter to start at new digit's LSB 
		counter = 0;

		//sets second variable pe1 equal to first
		Generate_Second_String(pe0, pe1);
		//add the least significant digits of the string
		Add_LSB(pe0, pe1, answer, counter, carry);
		//adds the carry if the MSB of LSB sum to greater than 9
		Carry(answer, carry);

		//the next power's sum will be determined
		exponent++;
	}

	//reverses the number passed in
	Reverse_Strings(pe0);

	cout << pe0 << endl;
	cout << pe1 << endl;
	cout << answer << endl;

	int pause;
	cin >> pause;
}

void Generate_Second_String(string &pe0, string &pe1)
{
	/*Generates the second string, so that pe0 &
	pe1 can be added together*/

	//set 0 pe0 equal to pe1
	pe1 = pe0;
}

void Reverse_Strings(string &pe0)
{
	/*Reverses the number passed in*/

	//reverses pe0
	reverse(pe0.begin(), pe0.end());
}

void Add_LSB(string &pe0, string &pe1, string &answer, int &counter, int &carry)
{
	//used to store the result of pe0 & pe1
	int sum;

	//test
	int test = (pe0[counter] - '0');
	int test1 = (pe1[counter] - '0');
	//

	//adds to the 'counter' digit of the two strings 
	sum = (pe0[counter] - '0') + (pe1[counter] - '0');

	//adds the LSB to the answer
	answer.push_back(sum % 10 + '0');

	//if the sum exceeds 9, there is a carry
	carry = sum / 10;
}

void Carry(string &answer, int &carry)
{
	/*if the last digits summed from the LSB function
	sum to greater than 9, this function is called*/
	
	if (carry == 1)
	{
		/*last digits summed of LSB greater than 9*/
		
		//the carry is added to answer
		answer.push_back(carry + '0');
	}
}