#include <fstream>
#include <string>
#include <iostream>
#include <vector> 
using namespace std;

void Initialize_Alphabet_Array(string Alphabet[]);
void Determine_String_Length(string &pe022_names, long long int &pe022_names_length);
void Determine_Number_of_Names(string &pe022_names, long long int &pe022_names_counter,
	long long int &pe022_names_length, char &name_end, vector<string> &Cleaned_Name_List);

int main(void)
{
	//read input file into fin
	ifstream fin("PE022.txt");
	//set string variable equal to fin, file contents
	string pe022_names((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	//numerical value of the alphabet; 'cleaned' name
	string Alphabet[26], current_name, Names;
	//counter for input file string
	long long int pe022_names_counter = 0, pe022_names_length = 0;
	//what separates names in the input file
	char name_end = '"';
	//where the polished names will be stored
	vector<string> Cleaned_Name_List;

	//stores the numerical value of every letter in the alphabet
	Initialize_Alphabet_Array(Alphabet);
	//determines the length of the string
	Determine_String_Length(pe022_names, pe022_names_length);
	//separates the names in the list into a vector
	Determine_Number_of_Names(pe022_names,pe022_names_counter, pe022_names_length, 
		name_end, Cleaned_Name_List);

	//system pause
	getchar();
}

/*

	//print contents of vector
	for (int i = 0; i < Cleaned_Name_List.size(); i++) {
		cout << Cleaned_Name_List[i] << " ";
	}

*/

void Determine_Number_of_Names(string &pe022_names, long long int &pe022_names_counter, 
	long long int &pe022_names_length, char &name_end, vector<string> &Cleaned_Name_List)
{
	/*Determies the number of names in the file/string*/
	
	//skips the first char of the string which is an apostrophe
	long long int counter = 1;
	//the current name being constructed
	string current_name;

	while (counter < pe022_names_length)
	{
		/*parse the string into individual words*/
		if (pe022_names[counter] == name_end)
		{
			//one more name is identified
			pe022_names_counter += 1;
			//store the cleaned names in a vector
			Cleaned_Name_List.push_back(current_name);
			//reset new name
			current_name = "";
			//skip the "," in the string that separates names
			counter += 3;
		}

		else
		{
			//construct names as a summation of individual chars
			current_name += pe022_names[counter];
			//move along the name index
			counter++;
		}
	}
}

void Determine_String_Length(string &pe022_names, long long int &pe022_names_length)
{
	/*Determine the total number of char in the string*/
	pe022_names_length = pe022_names.length();
}

void Initialize_Alphabet_Array(string Alphabet[])
{
	/*index the letters of the alphabet*/
	Alphabet[0] = "A";
	Alphabet[1] = "B";
	Alphabet[2] = "C";
	Alphabet[3] = "D";
	Alphabet[4] = "E";
	Alphabet[5] = "F";
	Alphabet[6] = "G";
	Alphabet[7] = "H";
	Alphabet[8] = "I";
	Alphabet[9] = "J";
	Alphabet[10] = "K";
	Alphabet[11] = "L";
	Alphabet[12] = "M";
	Alphabet[13] = "N";
	Alphabet[14] = "O";
	Alphabet[15] = "P";
	Alphabet[16] = "Q";
	Alphabet[17] = "R";
	Alphabet[18] = "S";
	Alphabet[19] = "T";
	Alphabet[20] = "U";
	Alphabet[21] = "V";
	Alphabet[22] = "W";
	Alphabet[23] = "X";
	Alphabet[24] = "Y";
	Alphabet[25] = "Z";
}