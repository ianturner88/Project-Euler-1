#include <iostream>
#include <math.h>
using namespace std;

void Sequence(int &n, int &i, int &k);
void Answer(int collatz[], int &i, int &k, int &n, int &answer);

int main()
{
	int n = 0, i = 0, k, answer = 2;
	int collatz[100002] = { 0 };

	while (i < 100000)
	{
		i++;
		n = i;

		Sequence(n, i, k);
		Answer(collatz, i, k, n, answer);
	}

	cout << answer << " " << collatz[answer] + 1 << endl;

	/*Junk I write so the system pauses*/
	int test;
	cout << "Hey there!";
	cin >> test;
}

void Sequence(int &n, int &i, int &k)
{
	/*Calculates sequences for the given starting number
	& breaks if the sequences starts calculating an already
	determined route.*/

	k = 0;

	while (n >= i && n != 1)
	{
		if ((n % 2) == 0)
		{
			n = (n / 2);
		}

		else
		{
			n = 3 * n + 1;
		}

		k++;
	}
}

void Answer(int collatz[], int &i, int &k, int &n, int &answer)
{
	/*Every number's collatz sequence count is stored
	in the arry collatz[]*/

	collatz[i] = collatz[n] + k;

	if (collatz[i] > answer)
	{
		answer = i;
	}
}//test