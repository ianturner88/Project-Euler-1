// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Clean_Input.h"

int main() {
    std::string input_line;
    std::ifstream input_file("PE081.txt");

    std::vector<int> test;

    if (input_file.is_open())
    {
        //read in the file
        while (getline(input_file, input_line))
        {
            Tokenize_String(input_line);
        }
        input_file.close();
    }
    // the file did not exist
    else std::cout << "Unable to open file";
    

    return 0;
}