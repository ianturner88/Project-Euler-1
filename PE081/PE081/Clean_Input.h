#pragma once

#include <vector>

#include "enum.h"

std::vector<int> Tokenize_String(std::string input);
int String_to_Int(std::string input);
void Is_Valid_Digit(char digit);
void PE081_Matrix(int pe081_array[][NUMBER_OF_COLUMNS], std::vector<std::vector<int>> pe081_matrix);