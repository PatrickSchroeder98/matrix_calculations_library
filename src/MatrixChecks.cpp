#include "../../matrix_calculations_library/include/MatrixChecks.h"

template<typename T>
bool MatrixChecks<T>::sizes_check(std::vector<std::vector<T>> vect1, std::vector<std::vector<T>> vect2) {
    // Returns true if two matrixes are equal in sizes.
    if (vect1.size() != vect2.size()) { return false; }

    for (int i = 0; i < vect1.size(); i++)
    {
        if (vect1[i].size() != vect2[i].size()) { return false; }
    }

    return true;
}

template<typename T>
bool MatrixChecks<T>::column_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a column matrix.
    for (std::vector<T> i : vect) {
        if (i.size() != 1) { return false; }
    }
    return true;
}

template<typename T>
bool MatrixChecks<T>::row_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a row matrix.
    if (vect.size() != 1) { return false; }
    return true;
}

template<typename T>
bool MatrixChecks<T>::rectangular_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a rectangular matrix.
    if (vect.size() == vect[0].size()) { return false; }
    return true;
}

template<typename T>
bool MatrixChecks<T>::square_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a square matrix. Assumes that all rows are equal in sizes.
    if (vect.size() != vect[0].size()) { return false; }
    return true;
}
