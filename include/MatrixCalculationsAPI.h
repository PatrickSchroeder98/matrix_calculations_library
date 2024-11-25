#pragma once

#include "../../matrix_calculations_library/include/MatrixCalculations.h"
#include "../../matrix_calculations_library/include/MatrixChecks.h"
#include "../../matrix_calculations_library/include/MatrixIO.h"

template<typename T>
class MatrixCalculationsAPI {
private:
	MatrixCalculations<T> mclc;
	MatrixChecks<T> mcks;
	MatrixIO<T> mio;
	std::vector<std::vector<T>> add_or_subtract_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2, bool add);
public:
	std::vector<std::vector<T>> add_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2);
	std::vector<std::vector<T>> subtract_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2);
	std::vector<std::vector<T>> multiply_matrix_by_scalar(const std::vector<std::vector<T>>& matrix, const T scalar);
	std::vector<std::vector<T>> multiply_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2);
	std::vector<std::vector<T>> transpose_matrix(const std::vector<std::vector<T>>& matrix);
	std::vector<std::vector<T>> invert_matrix(const std::vector<std::vector<T>>& matrix);
	std::vector<std::vector<T>> cut_minor(const std::vector<std::vector<T>>& matrix, int row, int column);
	std::vector<std::vector<std::vector<T>>> cut_all_minors(const std::vector<std::vector<T>>& matrix);
	T count_det(const std::vector<std::vector<T>>& matrix);
	std::vector<T> get_matrix_sizes(const std::vector<std::vector<T>>& matrix);

	std::vector<std::vector<T>> load_matrix(std::string path);
	bool save_matrix(std::string path, const std::vector<std::vector<T>>& vect);

	void view(const std::vector<std::vector<T>>& matrix);

	bool integrity_check(const std::vector<std::vector<T>>& vect) { return mcks.integrity_check(vect); }
	bool sizes_check(const std::vector<std::vector<T>>& vect1, const std::vector<std::vector<T>>& vect2) { return mcks.sizes_check(vect1, vect2); }
	bool column_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.column_matrix_check(vect); }
	bool row_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.row_matrix_check(vect); }
	bool rectangular_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.rectangular_matrix_check(vect); }
	bool square_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.square_matrix_check(vect); }
	bool identity_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.identity_matrix_check(vect); }
	bool diagonal_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.diagonal_matrix_check(vect); }
	bool scalar_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.scalar_matrix_check(vect); }
	bool null_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.null_matrix_check(vect); }
	bool upper_lower_triangular_matrix_check(const std::vector<std::vector<T>>& vect, bool lower) { return mcks.upper_lower_triangular_matrix_check(vect, lower); }
	bool equality_check(const std::vector<std::vector<T>>& vect1, const std::vector<std::vector<T>>& vect2) { return mcks.equality_check(vect1, vect2); }
	bool binary_matrix_check(const std::vector<std::vector<T>>& vect) { return mcks.binary_matrix_check(vect); }
};

#include "../../matrix_calculations_library/src/MatrixCalculationsAPI.cpp"
