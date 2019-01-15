#include<ProjectEulerLibrary.h>

void Program_Execution_Time(clock_t total_time)
{
	//calculate total execution time
	total_time = clock() - total_time;
	//output program's execution time
	cout << "program's execution took: " << total_time << endl;
}