#include <iostream>
#include <string>
using namespace std;

int main (void)
{
	int test;
	
	// determine how often the while loop needs to run
	cout << "Please enter the number of tests" << endl;
	cin >> test;
	
	int span;
	string digits;
	int long long best = 5;
	int long long current = 0;
	int start = 0;
	int i;
	int length;

	while (test--)
	{
		i = 1;
		
		// the number of digits to be read in
		cout << "Please enter the string's length: " << endl;
		cin >> length;
		
		//the number of consecutive digits to check
		cout << "Please enter the span of digits to be tested: " << endl;
		cin >> span;
		
		//the digits themselves... they can not be entered in line by line but must be read in as a single line
		cout << "Please enter the digits to be investigated: " << endl;
		cin >> digits;
		
		// start at slot 0 and go until we've come to the last 13 digits.
		for (start = 0; (start + span) < length; start++)
		{
			current = 1;
			
			//convert the digits from ASCII to numbers
			for (i = 0; i < span; i++)
			{
				current *=	digits[start + i] - '0';
			}
			
			// update the best 
			if (current > best)
			{
				best = current;
			}
		}
	}
	
	cout << best;
}
