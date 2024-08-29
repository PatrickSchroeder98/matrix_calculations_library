#include "../../matrix_calculations_library/include/MatrixChecks.h"

template<typename T>
bool MatrixChecks<T>::integrity_check(std::vector<std::vector<T>> vect) {
    // Returns true if all rows of given matrix have equal size.
    double temp = vect[0].size();
    for (std::vector<T> i : vect) {
        if (i.size() != temp) { return false; }
    }
    return true;
}

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

template<typename T>
bool MatrixChecks<T>::identity_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is an identity matrix.
    if (!square_matrix_check(vect)) { return false; }
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if (vect[i][i] != 1) {
                return false;
            }
            else if (i != j && vect[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool MatrixChecks<T>::diagonal_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is an diagonal matrix.
    if (!square_matrix_check(vect)) { return false; }
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if (vect[i][i] == 0) {
                return false;
            }
            else if (i != j && vect[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool MatrixChecks<T>::scalar_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is an scalar matrix.
    if (!square_matrix_check(vect)) { return false; }
    T temp = vect[0][0];
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if (vect[i][i] != temp) {
                return false;
            }
            else if (i != j && vect[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool MatrixChecks<T>::null_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a null matrix.
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if (vect[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool MatrixChecks<T>::upper_lower_triangular_matrix_check(std::vector<std::vector<T>> vect, bool lower) {
    // Returns true if given matrix is an upper or lower triangular matrix - depending on boolean argument.

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            if (lower) {
                if (i < j) { // lower triangular matrix check

                    if (vect[i][j] != 0) {
                        return false;
                    }
                }
            }
            else {
                if (i > j) { // upper triangular matrix check

                    if (vect[i][j] != 0) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

template<typename T>
bool MatrixChecks<T>::equality_check(std::vector<std::vector<T>> vect1, std::vector<std::vector<T>> vect2) {
    // Returns true if two matrixes are equal.
    if (vect1.size() != vect2.size()) { return false; }

    for (int i = 0; i < vect1.size(); i++)
    {
        if (vect1[i].size() != vect2[i].size()) { return false; }
        for (int j = 0; j < vect1[i].size(); j++)
        {
            if (vect1[i][j] != vect2[i][j]) { return false; }
        }
    }

    return true;
}
