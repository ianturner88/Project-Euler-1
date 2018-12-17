#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void Initialize_Alphabet_Array(string Names[]);
void Transfer_Names(string input_file, string pe022_names);
void Chop_First_Apostrophe_of_File(string pe022_names);

int main(void)
{
	//read input file into fin
	ifstream fin("PE022.txt");
	//set string variable equal to fin
	string input_file((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	//numerical value of the alphabet
	string Names[26], pe022_names;

	Initialize_Alphabet_Array(Names);
	Transfer_Names(input_file, pe022_names);
	Chop_First_Apostrophe_of_File(pe022_names);

	//system pause
	getchar();
}

void Chop_First_Apostrophe_of_File(string pe022_names)
{
	/*Erase the first apostrophe of the file*/
	
	cout << pe022_names;

	/*
	pe022_names.erase(0, 1);

	cout << pe022_names;
	*/
}

void Transfer_Names(string input_file, string pe022_names)
{
	pe022_names = input_file;
}

void Initialize_Alphabet_Array(string Names[])
{
	Names[0] = "A";
	Names[1] = "B";
	Names[2] = "C";
	Names[3] = "D";
	Names[4] = "E";
	Names[5] = "F";
	Names[6] = "G";
	Names[7] = "H";
	Names[8] = "I";
	Names[9] = "J";
	Names[10] = "K";
	Names[11] = "L";
	Names[12] = "M";
	Names[13] = "N";
	Names[14] = "O";
	Names[15] = "P";
	Names[16] = "Q";
	Names[17] = "R";
	Names[18] = "S";
	Names[19] = "T";
	Names[20] = "U";
	Names[21] = "V";
	Names[22] = "W";
	Names[23] = "X";
	Names[24] = "Y";
	Names[25] = "Z";
}