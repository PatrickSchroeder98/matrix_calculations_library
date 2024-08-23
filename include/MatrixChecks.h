#pragma once

#include <vector>
#include <iostream>

template<typename T>
class MatrixChecks {

public:
    bool sizes_check(std::vector<std::vector<T>>& vect1, std::vector<std::vector<T>>& vect2);

};

#include "../../matrix_calculations_library/src/MatrixChecks.cpp"