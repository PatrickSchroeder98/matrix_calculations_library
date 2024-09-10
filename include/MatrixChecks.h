#pragma once

#include <vector>
#include <iostream>


template<typename T>
class MatrixChecks {

public:
    bool integrity_check(std::vector<std::vector<T>> vect);
    bool sizes_check(std::vector<std::vector<T>> vect1, std::vector<std::vector<T>> vect2);
    bool column_matrix_check(std::vector<std::vector<T>> vect);
    bool row_matrix_check(std::vector<std::vector<T>> vect);
    bool rectangular_matrix_check(std::vector<std::vector<T>> vect);
    bool square_matrix_check(std::vector<std::vector<T>> vect);
    bool identity_matrix_check(std::vector<std::vector<T>> vect);
    bool diagonal_matrix_check(std::vector<std::vector<T>> vect);
    bool scalar_matrix_check(std::vector<std::vector<T>> vect);
    bool null_matrix_check(std::vector<std::vector<T>> vect);
    bool upper_lower_triangular_matrix_check(std::vector<std::vector<T>> vect, bool lower);
    bool equality_check(std::vector<std::vector<T>> vect1, std::vector<std::vector<T>> vect2);
    bool binary_matrix_check(std::vector<std::vector<T>> vect);
};

#include "../../matrix_calculations_library/src/MatrixChecks.cpp"