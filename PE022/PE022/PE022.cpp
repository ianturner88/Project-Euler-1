#include <fstream>
#include <string>
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

void Initialize_Alphabet_Array(string Alphabet[]);
void Determine_String_Length(string &pe022_names, long long int &pe022_names_length);
void Determine_Number_of_Names(string &pe022_names, long long int &pe022_names_counter,
	long long int &pe022_names_length, char &name_end, vector<string> &Cleaned_Name_List);
void Sort_Vector(vector<string> &Cleaned_Name_List);
void Determine_Nth_Name(vector<string> &Cleaned_Name_List, string &current_name, 
	int &current_word_index);
void Length_Nth_Name(string &current_name, int &current_name_length);
void Identify_Letters_of_Nth_Name(string &current_name, int &i, string &current_letter);
void Numerical_Value_of_Letter(string Alphabet[], string &current_letter, int &current_letter_value);
void Total_Numerical_Value_of_Word(int &current_letter_value, int &current_word_value,
	int &current_word_index, vector<int> &Numerical_Name_Value);
void Final_Answer(long long int &pe022_names_counter, vector<int> &Numerical_Name_Value);
void Reset_Varibales(int &current_letter_value);

int main(void)
{
	//read input file into fin
	ifstream fin("PE022.txt");
	//set string variable equal to fin, file contents
	string pe022_names((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	//numerical value of the alphabet; 'cleaned' name
	string Alphabet[26], current_name, current_letter;
	//counter for input file string
	long long int pe022_names_counter = 0, pe022_names_length = 0;
	//what separates names in the input file
	char name_end = '"';
	//where the polished names will be stored
	vector<string> Cleaned_Name_List;
	//stores numerical value of every name
	vector<int> Numerical_Name_Value;
	//used to cycle through the list of names
	int current_word_index = 0, current_name_length = 0, current_word_value, 
		current_letter_value = 0, pe022_answer = 0;
	
	//stores the numerical value of every letter in the alphabet
	Initialize_Alphabet_Array(Alphabet);
	//determines the length of the string
	Determine_String_Length(pe022_names, pe022_names_length);
	//separates the names in the list into a vector
	Determine_Number_of_Names(pe022_names,pe022_names_counter, pe022_names_length, 
		name_end, Cleaned_Name_List);
	//sorts the content of the vector
	Sort_Vector(Cleaned_Name_List);

	while (current_word_index < pe022_names_counter)
	{
		/*loop to determine the numerical value of every name*/
		
		//set current_name equal to a nth name in vector
		Determine_Nth_Name(Cleaned_Name_List, current_name, current_word_index);
		//find the length of current_name 
		Length_Nth_Name(current_name, current_name_length);

		for (int i = 0; i < current_name_length; i++)
		{
			//identify the individual letters of each word
			Identify_Letters_of_Nth_Name(current_name, i, current_letter);
			//identify the values of the letters compromising every word
			Numerical_Value_of_Letter(Alphabet, current_letter, current_letter_value);
		}
		
		//store in a vector a given name's total numerical value (= letter sum * spot in vector) 
		Total_Numerical_Value_of_Word(current_letter_value, current_word_value,
			current_word_index, Numerical_Name_Value);
		//clear out previous word's value
		Reset_Varibales(current_letter_value);
	}

	//calculates the final answer to the problem
	Final_Answer(pe022_names_counter, Numerical_Name_Value);
	
	//system pause
	getchar();
}

void Reset_Varibales(int &current_letter_value)
{
	current_letter_value = 0;
}

void Final_Answer(long long int &pe022_names_counter, vector<int> &Numerical_Name_Value)
{
	/*The answer to the problem, #22*/
	
	int pe022_answer = 0;
	
	for (int i = 0; i < pe022_names_counter; i++)
	{
		/*sprint through all the vector's values*/
		pe022_answer += Numerical_Name_Value[i];
	}

	cout << pe022_answer << endl;
}

void Total_Numerical_Value_of_Word(int &current_letter_value, int &current_word_value, 
	int &current_word_index, vector<int> &Numerical_Name_Value)
{
	/*determine each word's numerical value (= (sum of letters) * (name's spot on list))*/

	//current_word_value is the sum of the letters' values
	current_word_value = current_letter_value;

	//the word's final value
	current_word_value *= current_word_index;

	//store the word's final numerical value 
	Numerical_Name_Value.push_back(current_word_value);
}

void Numerical_Value_of_Letter(string Alphabet[], string &current_letter, int &current_letter_value)
{
	/*Determines the numerical value of every given letter in every given name*/
	
	//set to true when the current_letter is matched with an element in the Alphabet
	bool match = false;

	for (int i = 0; (i < 25) && (match != true); i++)
	{
		/*cycle through the array Alphabet to find the letter's numerical value*/
		if (current_letter == Alphabet[i])
		{
			//add 1 because Alphabet as A starting at 0
			current_letter_value += (i + 1);
			//indicates the letter's numerical value is determined
			match = true;
		}
	}
}

void Identify_Letters_of_Nth_Name(string &current_name, int &i, string &current_letter)
{
	//identify the individual letters of the current_name
	current_letter = current_name[i];
}

void Length_Nth_Name(string &current_name, int &current_name_length)
{
	/*Establish upper boundary when determining numerical value of each word*/
	current_name_length = current_name.length();
}

void Determine_Nth_Name(vector<string> &Cleaned_Name_List, string &current_name, 
	int &current_word_index)
{
	/*Identify the current name to manipulate*/
	current_name = Cleaned_Name_List[current_word_index];
	current_word_index++;
}

void Sort_Vector(vector<string> &Cleaned_Name_List)
{
	/*Sorts the content of the vector into alphabetical order*/
	sort(Cleaned_Name_List.begin(), Cleaned_Name_List.end());
}

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