#include "pch.h"
#include "CppUnitTest.h"
#include "../../matrix_calculations_library/include/MatrixCalculations.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace matrixcalculationslibrarytests
{
	TEST_CLASS(matrixcalculationslibrarytests)
	{
        // Class with tests of methods from MatrixChecks class.

	public:
        TEST_METHOD(TestSetInputMatrix1Double)
        {
            // Test for checking if the double type vectors can be set to input_matrix_1 in correct way.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> expected_output = {
                {1.1, 2.2, 3.3},
                {4.4, 5.5, 6.6},
                {7.7, 8.8, 9.9}
            };

            mx.set_input_matrix_1(expected_output);

            std::vector<std::vector<double>> actual_output = mx.get_input_matrix_1();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetInputMatrix1Float)
        {
            // Test for checking if the float type vectors can be set to input_matrix_1 in correct way.
            MatrixCalculations<float> mx;
            std::vector<std::vector<float>> expected_output = {
                {1.1f, 2.2f, 3.3f},
                {4.4f, 5.5f, 6.6f},
                {7.7f, 8.8f, 9.9f}
            };

            mx.set_input_matrix_1(expected_output);

            std::vector<std::vector<float>> actual_output = mx.get_input_matrix_1();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetInputMatrix1Int)
        {
            // Test for checking if the integer type vectors can be set to input_matrix_1 in correct way.
            MatrixCalculations<int> mx;
            std::vector<std::vector<int>> expected_output = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            mx.set_input_matrix_1(expected_output);

            std::vector<std::vector<int>> actual_output = mx.get_input_matrix_1();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetInputMatrix2Double)
        {
            // Test for checking if the double type vectors can be set to input_matrix_2 in correct way.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> expected_output = {
                {1.1, 2.2, 3.3},
                {4.4, 5.5, 6.6},
                {7.7, 8.8, 9.9}
            };

            mx.set_input_matrix_2(expected_output);

            std::vector<std::vector<double>> actual_output = mx.get_input_matrix_2();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetInputMatrix2Float)
        {
            // Test for checking if the float type vectors can be set to input_matrix_2 in correct way.
            MatrixCalculations<float> mx;
            std::vector<std::vector<float>> expected_output = {
                {1.1f, 2.2f, 3.3f},
                {4.4f, 5.5f, 6.6f},
                {7.7f, 8.8f, 9.9f}
            };

            mx.set_input_matrix_2(expected_output);

            std::vector<std::vector<float>> actual_output = mx.get_input_matrix_2();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetInputMatrix2Int)
        {
            // Test for checking if the integer type vectors can be set to input_matrix_2 in correct way.
            MatrixCalculations<int> mx;
            std::vector<std::vector<int>> expected_output = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            mx.set_input_matrix_2(expected_output);

            std::vector<std::vector<int>> actual_output = mx.get_input_matrix_2();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

		TEST_METHOD(TestSetOutputMatrixDouble)
		{
            // Test for checking if the double type vectors can be set to output_matrix in correct way.
            MatrixCalculations<double> mx; 
            std::vector<std::vector<double>> expected_output = {
                {1.1, 2.2, 3.3},
                {4.4, 5.5, 6.6},
                {7.7, 8.8, 9.9}
            };

            mx.set_output_matrix(expected_output);

            std::vector<std::vector<double>> actual_output = mx.get_output_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
		}
        
        TEST_METHOD(TestSetOutputMatrixFloat)
        {
            // Test for checking if the float type vectors can be set to output_matrix in correct way.
            MatrixCalculations<float> mx;
            std::vector<std::vector<float>> expected_output = {
                {1.1f, 2.2f, 3.3f},
                {4.4f, 5.5f, 6.6f},
                {7.7f, 8.8f, 9.9f}
            };

            mx.set_output_matrix(expected_output);

            std::vector<std::vector<float>> actual_output = mx.get_output_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetOutputMatrixInt)
        {
            // Test for checking if the integer type vectors can be set to output_matrix in correct way.
            MatrixCalculations<int> mx;
            std::vector<std::vector<int>> expected_output = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            mx.set_output_matrix(expected_output);

            std::vector<std::vector<int>> actual_output = mx.get_output_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetScalarDouble) 
        {
            // Test for checking if the double type number can be set to scalar in correct way.
            MatrixCalculations<double> mx;
            double expected_output = 2.2;

            mx.set_scalar(expected_output);
            
            double actual_output = mx.get_scalar();

            Assert::AreEqual(expected_output, actual_output);

        }

        TEST_METHOD(TestSetScalarFloat)
        {
            // Test for checking if the float type number can be set to scalar in correct way.
            MatrixCalculations<float> mx;
            float expected_output = 2.3f;

            mx.set_scalar(expected_output);

            float actual_output = mx.get_scalar();

            Assert::AreEqual(expected_output, actual_output);

        }

        TEST_METHOD(TestSetScalarInt)
        {
            // Test for checking if the integer type number can be set to scalar in correct way.
            MatrixCalculations<int> mx;
            int expected_output = 2;

            mx.set_scalar(expected_output);

            int actual_output = mx.get_scalar();

            Assert::AreEqual(expected_output, actual_output);

        }

        TEST_METHOD(TestMultiplyByScalarDouble)
        {
            // Test for checking if the method for multiplying matrix by scalar works correctly with double type.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                {1.1, 2.2, 3.3},
                {4.4, 5.5, 6.6},
                {7.7, 8.8, 9.9}
            };
            std::vector<std::vector<double>> expected_output = {
                {2.75, 5.5, 8.25},
                {11.0, 13.75, 16.5},
                {19.25, 22.0, 24.75}
            };
            double scalar = 2.5;

            mx.set_scalar(scalar);
            mx.set_input_matrix_1(input_matrix);

            mx.multiply_by_scalar();

            std::vector<std::vector<double>> actual_output = mx.get_output_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestMultiplyByScalarFloat)
        {
            // Test for checking if the method for multiplying matrix by scalar works correctly with float type.
            MatrixCalculations<float> mx;
            std::vector<std::vector<float>> input_matrix = {
                {1.1, 2.2, 3.3},
                {4.4, 5.5, 6.6},
                {7.7, 8.8, 9.9}
            };
            std::vector<std::vector<float>> expected_output = {
                {2.75, 5.5, 8.25},
                {11.0, 13.75, 16.5},
                {19.25, 22.0, 24.75}
            };
            float scalar = 2.5;

            mx.set_scalar(scalar);
            mx.set_input_matrix_1(input_matrix);

            mx.multiply_by_scalar();

            std::vector<std::vector<float>> actual_output = mx.get_output_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestMultiplyByScalarInt)
        {
            // Test for checking if the method for multiplying matrix by scalar works correctly with integer type.
            MatrixCalculations<int> mx;
            std::vector<std::vector<int>> input_matrix = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            std::vector<std::vector<int>> expected_output = {
                {2, 4, 6},
                {8, 10, 12},
                {14, 16, 18}
            };
            int scalar = 2;

            mx.set_scalar(scalar);
            mx.set_input_matrix_1(input_matrix);

            mx.multiply_by_scalar();

            std::vector<std::vector<int>> actual_output = mx.get_output_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }
	};
}
