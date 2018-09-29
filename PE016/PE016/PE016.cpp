#include<iostream>
#include<string>
using namespace std;

void Generate_Second_String(string &project_euler_0, string &project_euler_1);

int main(void)
{
	string project_euler_0 = "0", project_euler_1 = "";

	//sets second variable equal to first
	Generate_Second_String(project_euler_0, project_euler_1);

	cout << project_euler_0 << endl;
	cout << project_euler_1;

	int pause;
	cin >> pause;
}

void Generate_Second_String(string &project_euler_0, string &project_euler_1)
{
	/*Generates the second string, so that project_euler_0 &
	project_euler_1 can be added together*/

	//set 0 pe0 equal to pe1
	project_euler_1 = project_euler_0;
}g