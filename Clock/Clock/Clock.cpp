#include<iostream>
#include <time.h>
using namespace std;

void Time(clock_t &total_time);

int main(void)
{
	clock_t total_time;
	int n = 100;

	//start clock
	total_time = clock();

	//waste time
	for (int i = 0; i < n; i++)
	{
		cout << i << endl;
	}

	//output time
	Time(total_time);

	total_time = clock() - total_time;

	cout << "time2: " << total_time;

	//system pause
	getchar();
}

void Time(clock_t &total_time)
{
	//total execution time
	total_time = clock() - total_time;
	cout << "time1: " << total_time << endl;
}