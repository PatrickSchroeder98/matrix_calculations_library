#include "../../matrix_calculations_library/include/MatrixCalculationsAPI.h"
#include "../../matrix_calculations_library/src/MatrixExceptions.cpp"

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::add_or_subtract_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2, bool add) {
	try {
		if (!mcks.sizes_check(matrix1, matrix2)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}

		mclc.set_input_matrix_1(matrix1);
		mclc.set_input_matrix_2(matrix2);
		mclc.add_subtract(add);  // True for addition, False for subtraction
		return mclc.get_output_matrix();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return { {} };
	}
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::add_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2) {
	return add_or_subtract_matrices(matrix1, matrix2, true);  
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::subtract_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2) {
	return add_or_subtract_matrices(matrix1, matrix2, false);  
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::multiply_matrix_by_scalar(const std::vector<std::vector<T>>& matrix, const T scalar)
{
	return std::vector<std::vector<T>>();
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::multiply_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2)
{
	return std::vector<std::vector<T>>();
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::transpose_matrix(const std::vector<std::vector<T>>& matrix)
{
	return std::vector<std::vector<T>>();
}
