#pragma once

#include <vector>
#include <string>

#include "PE082.h"

void Construct_Object_Array(std::vector<std::string> pe081_matrix_string, PE082_Matrix PE081Object_array[NxN][NxN]);
int String_to_Int(std::string input_number);