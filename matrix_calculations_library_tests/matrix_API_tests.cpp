#include "pch.h"
#include "CppUnitTest.h"
#include "../../matrix_calculations_library/include/MatrixCalculationsAPI.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace matrixcapitests
{
	TEST_CLASS(matrixcapitests)
	{
		// Class with tests of methods from MatrixChecks class.

	public:

		TEST_METHOD(TestMatrixAdditionAPI)
		{
			// Test of additon method called from API.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> input_matrix = {
				{2.0, 2.0, 3.0},
				{4.0, 5.0, 6.0},
				{7.0, 8.0, 0.0}
			};
			std::vector<std::vector<double>> expected_output = {
				{4.0, 4.0, 6.0},
				{8.0, 10.0, 12.0},
				{14.0, 16.0, 0.0}
			};
			std::vector<std::vector<double>> actual_output = API.add_matrices(input_matrix, input_matrix);

			Assert::AreEqual(expected_output.size(), actual_output.size());

			for (size_t i = 0; i < expected_output.size(); ++i) {
				Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
				}
			}
		}

		TEST_METHOD(TestMatrixAdditionExceptionAPI)
		{
			// Test for matrix addition with mismatched sizes, expecting an exception.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix1 = {
				{1.0, 2.0},
				{3.0, 4.0}
			};
			std::vector<std::vector<double>> matrix2 = {
				{1.0, 2.0, 3.0},  // Mismatched size
				{4.0, 5.0, 6.0}
			};

			// Expect an empty result due to dimension mismatch exception
			std::vector<std::vector<double>> actual_output = API.add_matrices(matrix1, matrix2);
			Assert::AreEqual((size_t)1, actual_output.size());
		}


		TEST_METHOD(TestMatrixSubtractionAPI)
		{
			// Test for matrix subtraction method in API.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix1 = {
				{5.0, 6.0, 7.0},
				{8.0, 9.0, 10.0},
				{11.0, 12.0, 13.0}
			};
			std::vector<std::vector<double>> expected_output = {
				{0.0, 0.0, 0.0},
				{0.0, 0.0, 0.0},
				{0.0, 0.0, 0.0}
			};

			std::vector<std::vector<double>> actual_output = API.subtract_matrices(matrix1, matrix1);
			Assert::AreEqual(expected_output.size(), actual_output.size());

			for (size_t i = 0; i < expected_output.size(); ++i) {
				Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
				}
			}
		}

		TEST_METHOD(TestMatrixSubtractionExceptionAPI)
		{
			// Test for matrix subtraction with mismatched sizes, expecting an exception.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix1 = {
				{1.0, 2.0},
				{3.0, 4.0}
			};
			std::vector<std::vector<double>> matrix2 = {
				{1.0, 2.0, 3.0},  // Mismatched size
				{4.0, 5.0, 6.0}
			};

			// Expect an empty result due to dimension mismatch exception
			std::vector<std::vector<double>> actual_output = API.subtract_matrices(matrix1, matrix2);
			Assert::AreEqual((size_t)1, actual_output.size());
		}

		TEST_METHOD(TestMatrixMultiplyByScalarAPI)
		{
			// Test for matrix multiplication by a scalar.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> input_matrix = {
				{1.0, 2.0, 3.0},
				{4.0, 5.0, 6.0},
				{7.0, 8.0, 9.0}
			};
			double scalar = 2.0;
			std::vector<std::vector<double>> expected_output = {
				{2.0, 4.0, 6.0},
				{8.0, 10.0, 12.0},
				{14.0, 16.0, 18.0}
			};

			std::vector<std::vector<double>> actual_output = API.multiply_matrix_by_scalar(input_matrix, scalar);

			Assert::AreEqual(expected_output.size(), actual_output.size());

			for (size_t i = 0; i < expected_output.size(); ++i) {
				Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
				}
			}
		}


		TEST_METHOD(TestMatrixTranspositionAPI)
		{
			// Test for matrix transposition.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> input_matrix = {
				{1.0, 2.0, 3.0},
				{4.0, 5.0, 6.0}
			};
			std::vector<std::vector<double>> expected_output = {
				{1.0, 4.0},
				{2.0, 5.0},
				{3.0, 6.0}
			};

			std::vector<std::vector<double>> actual_output = API.transpose_matrix(input_matrix);

			Assert::AreEqual(expected_output.size(), actual_output.size());

			for (size_t i = 0; i < expected_output.size(); ++i) {
				Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
				}
			}
		}


		TEST_METHOD(TestMatrixMultiplicationAPI)
		{
			// Test for matrix multiplication.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix1 = {
				{1.0, 2.0},
				{3.0, 4.0}
			};
			std::vector<std::vector<double>> matrix2 = {
				{5.0, 6.0},
				{7.0, 8.0}
			};
			std::vector<std::vector<double>> expected_output = {
				{19.0, 22.0},
				{43.0, 50.0}
			};

			std::vector<std::vector<double>> actual_output = API.multiply_matrices(matrix1, matrix2);

			Assert::AreEqual(expected_output.size(), actual_output.size());

			for (size_t i = 0; i < expected_output.size(); ++i) {
				Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
				}
			}
		}


		TEST_METHOD(TestMatrixMultiplicationExceptionAPI)
		{
			// Test for matrix multiplication with invalid dimensions.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix1 = {
				{1.0, 2.0}
			};
			std::vector<std::vector<double>> matrix2 = {
				{5.0, 6.0},
				{7.0, 8.0},
				{9.0, 10.0}  // Invalid size for multiplication
			};

			// Expect an empty result due to dimension mismatch exception
			std::vector<std::vector<double>> actual_output = API.multiply_matrices(matrix1, matrix2);
			Assert::AreEqual((size_t)1, actual_output.size());
		}

		TEST_METHOD(TestGetMatrixMinorValid)
		{
			// Test for checking if method that cuts matrix minor works correctly from API.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> input_matrix = {
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};
			std::vector<std::vector<double>> expected_output = {
				{5.5, 6.6},
				{8.8, 9.9}
			};
			
			std::vector<std::vector<double>> actual_output = API.cut_minor(input_matrix, 0, 0);
			Assert::AreEqual(expected_output.size(), actual_output.size());
			for (size_t i = 0; i < expected_output.size(); ++i) {
				Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
				}
			}
		}
		TEST_METHOD(TestCutAllMinorsAPI)
		{
			// Test for checking if the method cutting all minors from matrix works correctly from API.
			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> input_matrix = {
				{1.1, 2.2},
				{3.3, 4.4},
			};
			std::vector<std::vector<std::vector<double>>> expected_output = {
				{
					{ 4.4 }
				},
				{
					{ 3.3 }
				},
				{
					{ 2.2 }
				},
				{
					{ 1.1 }
				}
			};
			std::vector<std::vector<std::vector<double>>> actual_output = API.cut_all_minors(input_matrix);

			Assert::AreEqual(expected_output.size(), actual_output.size());
			for (size_t i = 0; i < expected_output.size(); ++i) {
				Assert::AreEqual(expected_output[i].size(), actual_output[i].size());
				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j].size(), actual_output[i][j].size());
					for (size_t k = 0; k < expected_output[i][j].size(); ++k) {
						Assert::AreEqual(expected_output[i][j][k], actual_output[i][j][k]);
					}
				}
			}
		}

		TEST_METHOD(TestAPICountDet0x0)
		{
			// Test for counting determinant of 0x0 matrix from API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{}
			};

			double expected_output = 1;
			double actual_output = API.count_det(matrix);

			Assert::AreEqual(expected_output, actual_output);
		}

		TEST_METHOD(TestAPICountDet1x1)
		{
			// Test for counting determinant of 1x1 matrix from API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{1}
			};

			double expected_output = 1.0;
			double actual_output = API.count_det(matrix);

			Assert::AreEqual(expected_output, actual_output);
		}

		TEST_METHOD(TestAPICountDet2x2)
		{
			// Test for counting determinant of 2x2 matrix from API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{3.0, -4.0},
				{7.0, -6.0}
			};


			double expected_output = 10.0;
			double actual_output = API.count_det(matrix);

			Assert::AreEqual(expected_output, actual_output);
		}

		TEST_METHOD(TestAPICountDet3x3)
		{
			// Test for counting determinant of 3x3 matrix from API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{2.0, 5.0, 3.0},
				{-1.0, 2.0, 5.0},
				{2.0, 1.0, 3.0}
			};

			double expected_output = 52.0;
			double actual_output = API.count_det(matrix);

			Assert::AreEqual(expected_output, actual_output);
		}

		TEST_METHOD(TestAPICountDet4x4)
		{
			// Test for counting determinant of 4x4 matrix from API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{1.0, 0.0, 4.0, -6.0},
				{2.0, 5.0, 0.0, 3.0},
				{-1.0, 2.0, 3.0, 5.0},
				{2.0, 1.0, -2.0, 3.0}
			};

			double expected_output = 318.0;
			double actual_output = API.count_det(matrix);

			Assert::AreEqual(expected_output, actual_output);
		}

		TEST_METHOD(TestAPICountDet5x5)
		{
			// Test for counting determinant of 5x5 matrix from API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{-2, 7,	0, 6, -2 },
				{ 1, -1, 3, 2, 2 },
				{ 3, 4,	0, 5, 3 },
				{ 2, 5, -4, -2,	2 },
				{ 0, 3, -1,	1, -4 },
			};

			double expected_output = 1440.0;
			double actual_output = API.count_det(matrix);

			Assert::AreEqual(expected_output, actual_output);
		}

		TEST_METHOD(TestAPICountDetException)
		{
			// Test for counting determinant function if exception is raised.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{1.0, 2.0}
			};

			double expected_output = 0.0;
			double actual_output = API.count_det(matrix);

			Assert::AreEqual(expected_output, actual_output);
		}

		TEST_METHOD(TestAPICheckMatrixIntegrityTrue)
		{
			// Test to check if integrity matrix check from API returns true if matrix have correct form. 
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.integrity_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixIntegrityFalse)
		{
			// Test to check if integrity matrix check from API returns false if matrix does not have correct form.  
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.integrity_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixSizesTrue)
		{
			// Test to check method called from API that compares two equal matrixes sizes. 
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.sizes_check(vect1, vect1));
		}

		TEST_METHOD(TestAPICheckMatrixSizesFalse1)
		{
			// Test to check method called from API that compares two differnt matrixes sizes.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};

			std::vector<std::vector<double>> vect2{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
			};

			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.sizes_check(vect1, vect2));
		}

		TEST_METHOD(TestAPICheckMatrixSizesFalse2)
		{
			// Alternative test to check method called from API that compares two differnt matrixes sizes.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};

			std::vector<std::vector<double>> vect2{
				{1.1, 2.2},
				{4.4, 5.5},
				{7.7, 8.8}
			};

			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.sizes_check(vect1, vect2));
		}

		TEST_METHOD(TestAPICheckMatrixColumnTrue)
		{
			// Test to check if column_matrix_check() method called from API returns true if given matrix is a column matrix.
			std::vector<std::vector<double>> vect1{
				{1.1},
				{4.4},
				{7.7}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.column_matrix_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixColumnFalse)
		{
			// Test to check if column_matrix_check() method called from API returns false if given matrix is not a column matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2},
				{4.4, 3.3},
				{7.7, 4.4}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.column_matrix_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixRowTrue)
		{
			// Test to check if row_matrix_check() method called from API returns true if given matrix is a row matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.row_matrix_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixRowFalse)
		{
			// Test to check if row_matrix_check() method called from API returns false if given matrix is not a row matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2},
				{4.4, 3.3},
				{7.7, 4.4}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.row_matrix_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixRectangularTrue)
		{
			// Test to check if rectangular_matrix_check() method called from API returns true if given matrix is a rectangular matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{1.1, 2.2, 3.3}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.rectangular_matrix_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixRectangularFalse)
		{
			// Test to check if rectangular_matrix_check() method called from API returns false if given matrix is not a rectangular matrix.
			std::vector<std::vector<double>> vect1{
				{1.1}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.rectangular_matrix_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixSquareTrue)
		{
			// Test to check if square_matrix_check() method called from API returns true if given matrix is a square matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2},
				{1.1, 2.2}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.square_matrix_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixSquareFalse)
		{
			// Test to check if square_matrix_check() method called from API returns false if given matrix is a not a square matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.square_matrix_check(vect1));
		}

		TEST_METHOD(TestAPICheckMatrixIdentityTrue)
		{
			// Test to check if identity_matrix_check() method called from API returns true if given matrix is an identity matrix.
			std::vector<std::vector<double>> vect{
				{1, 0, 0},
				{0, 1, 0},
				{0, 0, 1}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.identity_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixIdentityFalse)
		{
			// Test to check if identity_matrix_check() method called from API returns false if given matrix is not an identity matrix.
			std::vector<std::vector<double>> vect{
				{1, 0, 0},
				{0, 0, 0},
				{0, 0, 1}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.identity_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixDiagonalTrue)
		{
			// Test to check if diagonal_matrix_check() method called from API returns true if given matrix is a diagonal matrix.
			std::vector<std::vector<double>> vect{
				{1, 0, 0},
				{0, 2, 0},
				{0, 0, 3}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.diagonal_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixDiagonalFalse)
		{
			// Test to check if diagonal_matrix_check() method called from API returns false if given matrix is not a diagonal matrix.
			std::vector<std::vector<double>> vect{
				{1, 0, 5},
				{0, 2, 0},
				{0, 0, 3}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.diagonal_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixScalarTrue)
		{
			// Test to check if scalar_matrix_check() method called from API returns true if given matrix is a scalar matrix.
			std::vector<std::vector<double>> vect{
				{3, 0, 0},
				{0, 3, 0},
				{0, 0, 3}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.scalar_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixScalarFalse)
		{
			// Test to check if scalar_matrix_check() method called from API returns false if given matrix is a not scalar matrix.
			std::vector<std::vector<double>> vect{
				{3, 0, 0},
				{0, 4, 0},
				{0, 0, 3}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.scalar_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixNullTrue)
		{
			// Test to check if null_matrix_check() method called from API returns true if given matrix is a null matrix.
			std::vector<std::vector<double>> vect{
				{0, 0, 0},
				{0, 0, 0},
				{0, 0, 0}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.null_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixNullFalse)
		{
			// Test to check if null_matrix_check() method called from API returns false if given matrix is not a null matrix.
			std::vector<std::vector<double>> vect{
				{0, 0, 0},
				{0, 0, 0},
				{0, 0, 1}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.null_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixUpperTriangularTrue)
		{
			// Test to check if upper triangular matrix check method called from API returns true if given matrix is an upper triangular matrix.
			std::vector<std::vector<double>> vect{
				{1, 2, 3},
				{0, 4, 5},
				{0, 0, 6}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.upper_lower_triangular_matrix_check(vect, false));
		}

		TEST_METHOD(TestAPICheckMatrixUpperTriangularFalse)
		{
			// Test to check if upper triangular matrix check method called from API returns false if given matrix is not an upper triangular matrix.
			std::vector<std::vector<double>> vect{
				{1, 2, 3},
				{0, 4, 5},
				{7, 0, 6}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.upper_lower_triangular_matrix_check(vect, false));
		}

		TEST_METHOD(TestAPICheckMatrixLowerTriangularTrue)
		{
			// Test to check if lower triangular matrix check method called from API returns true if given matrix is an lower triangular matrix.
			std::vector<std::vector<double>> vect{
				{1, 0, 0},
				{2, 3, 0},
				{4, 5, 6}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.upper_lower_triangular_matrix_check(vect, true));
		}

		TEST_METHOD(TestAPICheckMatrixLowerTriangularFalse)
		{
			// Test to check if lower triangular matrix check method called from API returns false if given matrix is not an lower triangular matrix.
			std::vector<std::vector<double>> vect{
				{1, 2, 3},
				{0, 4, 5},
				{7, 0, 6}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.upper_lower_triangular_matrix_check(vect, true));
		}

		TEST_METHOD(TestAPICheckMatrixEqualityTrue)
		{
			// Test to check if equality_check called from API  returns true if two matrixes are equal.
			std::vector<std::vector<double>> vect{
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.equality_check(vect, vect));
		}

		TEST_METHOD(TestAPICheckMatrixEqualityFalse)
		{
			// Test to check if equality_check called from API  returns false if two matrixes are not equal.
			std::vector<std::vector<double>> vect1{
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
			};
			std::vector<std::vector<double>> vect2{
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 10}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.equality_check(vect1, vect2));
		}

		TEST_METHOD(TestAPICheckMatrixBinaryTrue)
		{
			// Test to check if binary_matrix_check() method called from API returns true if given matrix is a binary matrix.
			std::vector<std::vector<double>> vect{
				{0, 0, 0},
				{0, 1, 0},
				{1, 1, 0}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsTrue(API.binary_matrix_check(vect));
		}

		TEST_METHOD(TestAPICheckMatrixBinaryFalse)
		{
			// Test to check if binary_matrix_check() method called from API returns false if given matrix is not a binary matrix.
			std::vector<std::vector<double>> vect{
				{0, 0, 0},
				{1, 0, 1},
				{0, 0, 3}
			};
			MatrixCalculationsAPI<double> API;
			Assert::IsFalse(API.binary_matrix_check(vect));
		}

		TEST_METHOD(TestAPICountInverse1x1)
		{
			// Test for method counting inverse of 1x1 matrix called in API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{4.0}
			};

			std::vector<std::vector<double>> expected_output = { { 0.25 } };
			std::vector<std::vector<double>> actual_output = API.invert_matrix(matrix);

			// Assert sizes of the output matrices
			Assert::AreEqual(expected_output.size(), actual_output.size());
			Assert::AreEqual(expected_output[0].size(), actual_output[0].size());

			// Assert the contents of the output matrix
			for (size_t i = 0; i < expected_output.size(); ++i) {
				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j], 0.001); // Allowing tolerance for floating-point comparison
				}
			}
		}

		TEST_METHOD(TestAPICountInverse2x2)
		{
			// Test for method counting inverse of 2x2 matrix called in API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{2.0, 2.0},
				{3.0, 4.0}
			};

			std::vector<std::vector<double>> expected_output = {
				{2.0, -1.0},
				{-1.5, 1.0}
			};
			std::vector<std::vector<double>> actual_output = API.invert_matrix(matrix);

			// Assert sizes of the output matrices
			Assert::AreEqual(expected_output.size(), actual_output.size());
			Assert::AreEqual(expected_output[0].size(), actual_output[0].size());

			// Assert the contents of the output matrix
			for (size_t i = 0; i < expected_output.size(); ++i) {
				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j], 0.001); // Allowing tolerance for floating-point comparison
				}
			}
		}

		TEST_METHOD(TestAPICountInverse3x3)
		{
			// Test for method counting inverse of 3x3 matrix called in API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{2.0, 1.0, 0.0},
				{1.0, -1.0, 1.0},
				{3.0, 2.0, 1.0}
			};

			std::vector<std::vector<double>> expected_output = {
				{0.75, 0.25, -0.25},
				{-0.5, -0.5, 0.5},
				{-1.25, 0.25, 0.75}
			};
			std::vector<std::vector<double>> actual_output = API.invert_matrix(matrix);

			// Assert sizes of the output matrices
			Assert::AreEqual(expected_output.size(), actual_output.size());
			Assert::AreEqual(expected_output[0].size(), actual_output[0].size());

			// Assert the contents of the output matrix
			for (size_t i = 0; i < expected_output.size(); ++i) {
				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j], 0.001); // Allowing tolerance for floating-point comparison
				}
			}
		}

		TEST_METHOD(TestAPICountInverse4x4)
		{
			// Test for method counting inverse of 4x4 matrix called in API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{0.0, 0.0, -1.0, 2.0},
				{0.0, 1.0, 0.0, 0.0},
				{9.0, 0.0, 0.0, 0.0},
				{0.0, 0.0, 0.0, 1.0}
			};

			std::vector<std::vector<double>> expected_output = {
				{0.0, 0.0, 1.0 / 9.0, 0.0},
				{0.0, 1.0, 0.0, 0.0},
				{-1.0, 0.0, 0.0, 2.0},
				{0.0, 0.0, 0.0, 1.0}
			};
			std::vector<std::vector<double>> actual_output = API.invert_matrix(matrix);

			// Assert sizes of the output matrices
			Assert::AreEqual(expected_output.size(), actual_output.size());
			Assert::AreEqual(expected_output[0].size(), actual_output[0].size());

			// Assert the contents of the output matrix
			for (size_t i = 0; i < expected_output.size(); ++i) {
				for (size_t j = 0; j < expected_output[i].size(); ++j) {
					Assert::AreEqual(expected_output[i][j], actual_output[i][j], 0.001); // Allowing tolerance for floating-point comparison
				}
			}
		}

		TEST_METHOD(TestAPICount2x2NoInverse)
		{
			// Test of inverese matrix method called in API for 2x2 matrix where matrix has no inverse.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{2.0, 3.0},
				{2.0, 3.0}
			};

			std::vector<std::vector<double>> expected_output = {
				{}
			};
			std::vector<std::vector<double>> actual_output = API.invert_matrix(matrix);

			// Assert sizes of the output matrices
			Assert::AreEqual(expected_output.size(), actual_output.size());
			Assert::AreEqual(expected_output[0].size(), actual_output[0].size());

		}

		TEST_METHOD(TestAPIInverseException)
		{
			// Test of inverese matrix method called in API where input data raises an exception.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{1.0, 2.0},
				{3.0, 4.0},
				{5.0, 6.0}
			};

			std::vector<std::vector<double>> expected_output = {
				{}
			};
			std::vector<std::vector<double>> actual_output = API.invert_matrix(matrix);

			// Assert sizes of the output matrices
			Assert::AreEqual(expected_output.size(), actual_output.size());
			Assert::AreEqual(expected_output[0].size(), actual_output[0].size());
		}

		TEST_METHOD(TestAPIReadMatrixSizes)
		{
			// Test of method to get matrix sizes called in API.

			MatrixCalculationsAPI<double> API;
			std::vector<std::vector<double>> matrix{
				{1.0, 2.0},
				{3.0, 4.0},
				{5.0, 6.0}
			};

			std::vector<double> expected_output = {3.0, 2.0};
			std::vector<double> actual_output = API.get_matrix_sizes(matrix);

			// Assert sizes of the output matrices
			Assert::AreEqual(expected_output.size(), actual_output.size());
			for (size_t j = 0; j < expected_output.size(); ++j) {
				Assert::AreEqual(expected_output[j], actual_output[j], 0.001); // Allowing tolerance for floating-point comparison
			}
		}
	};


}
