#pragma once

#include "../../matrix_calculations_library/include/MatrixCalculations.h"
#include "../../matrix_calculations_library/include/MatrixChecks.h"

template<typename T>
class MatrixCalculationsAPI {
private:
	MatrixCalculations<T> mclc;
	MatrixChecks<T> mcks;
	std::vector<std::vector<T>> add_or_subtract_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2, bool add);
public:
	std::vector<std::vector<T>> add_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2);
	std::vector<std::vector<T>> subtract_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2);
	std::vector<std::vector<T>> multiply_matrix_by_scalar(const std::vector<std::vector<T>>& matrix, const T scalar);
	std::vector<std::vector<T>> multiply_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2);
	std::vector<std::vector<T>> transpose_matrix(const std::vector<std::vector<T>>& matrix);
};

#include "../../matrix_calculations_library/src/MatrixCalculationsAPI.cpp"
