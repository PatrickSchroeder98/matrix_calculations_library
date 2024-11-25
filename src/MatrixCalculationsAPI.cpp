#include "../../matrix_calculations_library/include/MatrixCalculationsAPI.h"
#include "../../matrix_calculations_library/src/MatrixExceptions.cpp"

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::add_or_subtract_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2, bool add) {
	// API private method for handling the add or subtract request.
	try {
		if (!mcks.sizes_check(matrix1, matrix2) || !mcks.integrity_check(matrix1) || !mcks.integrity_check(matrix2)) {
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
	// API method for matrix addition.
	return add_or_subtract_matrices(matrix1, matrix2, true);  
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::subtract_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2) {
	// API method for matrix subtraction.
	return add_or_subtract_matrices(matrix1, matrix2, false);  
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::multiply_matrix_by_scalar(const std::vector<std::vector<T>>& matrix, const T scalar)
{
	// API method for matrix multiplication by a scalar.
	try {
		if (!mcks.integrity_check(matrix)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		mclc.set_input_matrix_1(matrix);
		mclc.set_scalar(scalar);
		mclc.multiply_by_scalar();
		return mclc.get_output_matrix();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return { {} };
	}
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::multiply_matrices(const std::vector<std::vector<T>>& matrix1, const std::vector<std::vector<T>>& matrix2)
{
	// API method for matrices multiplication.
	try {
		mclc.set_input_matrix_1(matrix2);
		mclc.check_matrix_size();
		std::vector<T> size2 = mclc.get_sizes();
		mclc.set_input_matrix_2(matrix2);
		mclc.set_input_matrix_1(matrix1);
		mclc.check_matrix_size();
		std::vector<T> size1 = mclc.get_sizes();
		if (size1[1] != size2[0] || !mcks.integrity_check(matrix1) || !mcks.integrity_check(matrix2)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		mclc.multiply_matrices();
		return mclc.get_output_matrix();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return { {} };
	}

	return std::vector<std::vector<T>>();
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::transpose_matrix(const std::vector<std::vector<T>>& matrix)
{
	// API method for matrix transposition.
	try {
		if (!mcks.integrity_check(matrix)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		mclc.set_input_matrix_1(matrix);
		mclc.transpose_matrix();
		return mclc.get_transposed_matrix();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return { {} };
	}
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::cut_minor(const std::vector<std::vector<T>>& matrix, int row, int column)
{
	// API method for cutting a minor from matrix.
	try {
		if (!mcks.integrity_check(matrix)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		mclc.set_input_matrix_1(matrix);
		mclc.cut_minor_matrix(row, column);
		return mclc.get_minor_matrix();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return { {} };
	}
}

template<typename T>
std::vector<std::vector<std::vector<T>>> MatrixCalculationsAPI<T>::cut_all_minors(const std::vector<std::vector<T>>& matrix)
{
	// API method for cutting all minors from given matrix.
	try {
		if (!mcks.integrity_check(matrix)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		mclc.set_input_matrix_1(matrix);
		mclc.cut_all_minor_matrices();
		return mclc.get_all_minors();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return { { {} } };
	}
	
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::load_matrix(std::string path)
{
	// API method for loading a matrix from a file.
	std::vector<std::vector<T>> temp = mio.load_matrix(path);
	try {
		if (!mcks.integrity_check(temp)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		return temp;
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return { {} };
	}
}

template<typename T>
bool MatrixCalculationsAPI<T>::save_matrix(std::string path, const std::vector<std::vector<T>>& vect)
{
	// API method for saving a matrix to a file.
	try {
		if (!mcks.integrity_check(vect)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		return mio.save_matrix(path, vect);
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return false;
	}
}

template<typename T>
void MatrixCalculationsAPI<T>::view(const std::vector<std::vector<T>>& matrix)
{
	// API method for displaying a matrix.
	try {
		if (!mcks.integrity_check(matrix)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		mclc.view(matrix);
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
	}
	
}

template<typename T>
T MatrixCalculationsAPI<T>::count_det(const std::vector<std::vector<T>>& matrix) {
	// API method for counting determinant of matrix.
	try {
		if (!mcks.square_matrix_check(matrix) || !mcks.integrity_check(matrix)) {
			// Additional check for 0x0 matrix that should not throw an exception
			if (!(matrix.size() == 1 && matrix[0].size() == 0) ) { 
				throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
			}
		}
		mclc.set_input_matrix_1(matrix);
		mclc.count_det_large_matrix();
		return mclc.get_det();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return 0;
	}
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculationsAPI<T>::invert_matrix(const std::vector<std::vector<T>>& matrix)
{
	// API method for matrix inversion.
	try {
		if (!mcks.square_matrix_check(matrix) || !mcks.integrity_check(matrix)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		mclc.set_input_matrix_1(matrix);
		mclc.invert_matrix();
		return mclc.get_output_matrix();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return { {} };
	}
}

template<typename T>
std::vector<T> MatrixCalculationsAPI<T>::get_matrix_sizes(const std::vector<std::vector<T>>& matrix) {
	// API method for getting matrix sizes.
	try {
		if (!mcks.integrity_check(matrix)) {
			throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
		}
		mclc.set_input_matrix_1(matrix);
		mclc.check_matrix_size();
		return mclc.get_sizes();
	}
	catch (const MatrixDimensionMismatchException& e) {
		std::cout << " (Error code: " << e.getErrorCode() << ")\n";
		return {};
	}
}