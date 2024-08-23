#include "../../matrix_calculations_library/include/MatrixChecks.h"

template<typename T>
bool MatrixChecks<T>::sizes_check(std::vector<std::vector<T>>& vect1, std::vector<std::vector<T>>& vect2) {
    // returns true if two matrixes are equal in sizes
    if (vect1.size() != vect2.size()) { return false; }

    for (int i = 0; i < vect1.size(); i++)
    {
        if (vect1[i].size() != vect2[i].size()) { return false; }

    }

    return true;
}
