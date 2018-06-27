#include<iostream>
#include<cmath> 
using namespace std;

void Sum_Squares(int &x, int &sum1);
void Square_Sum(int &x, int &sum2);
void Answer(long long int &answer, int &sum1, int &sum2);

int main()
{
	int x = 0, sum1 = 0, sum2 = 0; 
	long long int answer = 0;
	Sum_Squares(x, sum1);
	x = 0;
	Square_Sum(x, sum2);
	Answer(answer, sum1, sum2);

	cout << answer << endl;

	system("pause");
}

void Sum_Squares(int &x, int &sum1)
{
	while (x < 101)
	{
		sum1 += pow(x, 2);
		x++;
	}
}

void Square_Sum(int &x, int &sum2)
{
	while (x < 101)
	{
		sum2 += x;
		x++;
	}

	sum2 = pow(sum2, 2);
}

void Answer(long long int &answer, int &sum1, int &sum2)
{
	answer = sum2 - sum1;
}
