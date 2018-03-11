#include <iostream>
#include <string>
using namespace std;

int main (void)
{
	int test;
	cout << "Please enter the number of tests" << endl;
	cin >> test;
	
	int StringLength;
	int span;
	string digits;
	int long long best = 1;
	int long long current = 0;
	int start = 0;
	int i;
	int length;

	while (test--)
	{
		i = 1;
		
		cout << "Please enter the string's length: " << endl;
		cin >> StringLength;
		
		cout << "Please enter the span of digits to be tested: " << endl;
		cin >> span;
		
		cout << "Please enter the digits to be investigated: " << endl;
		cin >> digits;
		
		for (start = 0; (start + span) < length; start++)
		{
			for (i = 0; i < span; i++)
			{
				current *=	digits[start + i] - '0';
			}
			
			if (current > best)
			{
				best = current;
			}
		}
	}
	
	cout << best;
}
