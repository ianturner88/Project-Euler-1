#include<iostream>
#include<string>
using namespace std;

void Generate_Second_String(string &project_euler_0, string &project_euler_1);
void Reverse_Strings(string &project_euler_0);

int main(void)
{
	string project_euler_0 = "0", project_euler_1;
	int counter = 0;

	//sets second variable equal to first
	Generate_Second_String(project_euler_0, project_euler_1);

	while (counter < 1000)
	{

	}

	//reverses the number passed in
	void Reverse_Strings(string &project_euler_0);

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
}

void Reverse_Strings(string &project_euler_0, string &project_euler_1)
{
	/*Reverses the number passed in*/

	//reverses project_euler_0
	reverse(project_euler_0.begin(), project_euler_0.end());
}