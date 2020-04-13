#pragma once

#include <vector>

#include "PE081_enum.h"

std::vector<int> Tokenize_String(std::string input);
int String_to_Int(std::string input);
void Is_Valid_Digit(char digit);
void PE081_Matrix(int pe081_array[][NxN], std::vector<std::vector<int>> pe081_matrix);