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

	};


}
