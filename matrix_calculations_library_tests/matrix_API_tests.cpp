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
			//Test of additon method called from API.
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

	};
}
