#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../../matrix_calculations_library/include/MatrixChecks.h"

template<typename T>
class MatrixIO {
public:
	std::vector<std::vector<T>> load_matrix(std::string path);
};

#include "../../matrix_calculations_library/src/MatrixIO.cpp"

