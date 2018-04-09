#include<iostream>
using namespace std;

void gather(int prime[], int size);
void output(int prime[], int size);

int main (void)
{
	int i;
	int prime[5];
	int size;
	
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime[4] = 11;
	
	void gather(int prime[], int size);
	void output(int prime[], int size);
}

void gather(int prime[], int size)
{
	int i = 0;
	
	for (prime[i]; i <= size; i++)
	{
		cout << "Please enter the next prime" << endl;
		cin >> prime[i];
	}
}

void output(int prime[], int size)
{
	int i = 0;
	
	for (prime[i]; i <= size; i++)
	{
		cout << "The next prime is: " << prime[i] << endl;
	}
}
