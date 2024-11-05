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

        TEST_METHOD(TestSetGetDetDouble)
        {
            // Test for checking if the double type number can be set and retrieved for determinant.
            MatrixCalculations<double> mx;
            double expected_output = 3.14;

            mx.set_det(expected_output);
            double actual_output = mx.get_det();

            Assert::AreEqual(expected_output, actual_output);
        }

        TEST_METHOD(TestSetGetDetFloat)
        {
            // Test for checking if the float type number can be set and retrieved for determinant.
            MatrixCalculations<float> mx;
            float expected_output = 2.71f;

            mx.set_det(expected_output);
            float actual_output = mx.get_det();

            Assert::AreEqual(expected_output, actual_output);
        }

        TEST_METHOD(TestSetGetDetInt)
        {
            // Test for checking if the integer type number can be set and retrieved for determinant.
            MatrixCalculations<int> mx;
            int expected_output = 42;

            mx.set_det(expected_output);
            int actual_output = mx.get_det();

            Assert::AreEqual(expected_output, actual_output);
        }

        TEST_METHOD(TestSetGetSizesDouble)
        {
            // Test for checking if the vector of double type can be set and retrieved for sizes.
            MatrixCalculations<double> mx;
            std::vector<double> expected_output = { 3.0, 4.0 };

            mx.set_sizes(expected_output);
            std::vector<double> actual_output = mx.get_sizes();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i], actual_output[i]);
            }
        }

        TEST_METHOD(TestSetGetSizesFloat)
        {
            // Test for checking if the vector of float type can be set and retrieved for sizes.
            MatrixCalculations<float> mx;
            std::vector<float> expected_output = { 5.0f, 6.0f };

            mx.set_sizes(expected_output);
            std::vector<float> actual_output = mx.get_sizes();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i], actual_output[i]);
            }
        }

        TEST_METHOD(TestSetGetSizesInt)
        {
            // Test for checking if the vector of integer type can be set and retrieved for sizes.
            MatrixCalculations<int> mx;
            std::vector<int> expected_output = { 7, 8 };

            mx.set_sizes(expected_output);
            std::vector<int> actual_output = mx.get_sizes();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i], actual_output[i]);
            }
        }

        TEST_METHOD(TestSetGetMinorMatrixDouble)
        {
            // Test for checking if the 2D vector of double type can be set and retrieved for minor_matrix.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> expected_output = {
                {1.1, 2.2},
                {3.3, 4.4}
            };

            mx.set_minor_matrix(expected_output);
            std::vector<std::vector<double>> actual_output = mx.get_minor_matrix();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());
                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetGetMinorMatrixFloat)
        {
            // Test for checking if the 2D vector of float type can be set and retrieved for minor_matrix.
            MatrixCalculations<float> mx;
            std::vector<std::vector<float>> expected_output = {
                {5.5f, 6.6f},
                {7.7f, 8.8f}
            };

            mx.set_minor_matrix(expected_output);
            std::vector<std::vector<float>> actual_output = mx.get_minor_matrix();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());
                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetGetMinorMatrixInt)
        {
            // Test for checking if the 2D vector of integer type can be set and retrieved for minor_matrix.
            MatrixCalculations<int> mx;
            std::vector<std::vector<int>> expected_output = {
                {9, 10},
                {11, 12}
            };

            mx.set_minor_matrix(expected_output);
            std::vector<std::vector<int>> actual_output = mx.get_minor_matrix();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());
                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetGetTransposedMatrixDouble)
        {
            // Test for checking if the 2D vector of double type can be set and retrieved for transposed_matrix.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> expected_output = {
                {1.1, 4.4, 7.7},
                {2.2, 5.5, 8.8},
                {3.3, 6.6, 9.9}
            };

            mx.set_transposed_matrix(expected_output);
            std::vector<std::vector<double>> actual_output = mx.get_transposed_matrix();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());
                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetGetTransposedMatrixFloat)
        {
            // Test for checking if the 2D vector of float type can be set and retrieved for transposed_matrix.
            MatrixCalculations<float> mx;
            std::vector<std::vector<float>> expected_output = {
                {1.1f, 4.4f, 7.7f},
                {2.2f, 5.5f, 8.8f},
                {3.3f, 6.6f, 9.9f}
            };

            mx.set_transposed_matrix(expected_output);
            std::vector<std::vector<float>> actual_output = mx.get_transposed_matrix();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());
                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetGetTransposedMatrixInt)
        {
            // Test for checking if the 2D vector of integer type can be set and retrieved for transposed_matrix.
            MatrixCalculations<int> mx;
            std::vector<std::vector<int>> expected_output = {
                {1, 4, 7},
                {2, 5, 8},
                {3, 6, 9}
            };

            mx.set_transposed_matrix(expected_output);
            std::vector<std::vector<int>> actual_output = mx.get_transposed_matrix();

            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());
                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSetGetAllMinorsDouble)
        {
            // Test for checking if the 3D vector of double type can be set and retrieved for all_minors.
            MatrixCalculations<double> mx;
            std::vector<std::vector<std::vector<double>>> expected_output = {
                {
                    {5.5, 6.6},
                    {8.8, 9.9}
                },
                {
                    {4.4, 6.6},
                    {7.7, 9.9}
                }
            };

            mx.set_all_minors(expected_output);
            std::vector<std::vector<std::vector<double>>> actual_output = mx.get_all_minors();

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

        TEST_METHOD(TestSetGetAllMinorsFloat)
        {
            // Test for checking if the 3D vector of float type can be set and retrieved for all_minors.
            MatrixCalculations<float> mx;
            std::vector<std::vector<std::vector<float>>> expected_output = {
                {
                    {1.1f, 2.2f},
                    {3.3f, 4.4f}
                },
                {
                    {5.5f, 6.6f},
                    {7.7f, 8.8f}
                }
            };

            mx.set_all_minors(expected_output);
            std::vector<std::vector<std::vector<float>>> actual_output = mx.get_all_minors();

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

        TEST_METHOD(TestSetGetAllMinorsInt)
        {
            // Test for checking if the 3D vector of integer type can be set and retrieved for all_minors.
            MatrixCalculations<int> mx;
            std::vector<std::vector<std::vector<int>>> expected_output = {
                {
                    {1, 2},
                    {3, 4}
                },
                {
                    {5, 6},
                    {7, 8}
                }
            };

            mx.set_all_minors(expected_output);
            std::vector<std::vector<std::vector<int>>> actual_output = mx.get_all_minors();

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

        TEST_METHOD(TestGetMatrixSize)
        {
            // Test for checking if the method returning given matrix sizes.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                {2, 4, 6},
                {8, 10, 12},
                {14, 16, 18},
                {24, 26, 28}
            };
            mx.set_input_matrix_1(input_matrix);
            mx.check_matrix_size();
            std::vector<double> expected_output = { 4.0, 3.0 };
            std::vector<double> actual_output = mx.get_sizes();
            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i], actual_output[i]);
            }
        }

        TEST_METHOD(TestGetMatrixDeterminant1x1)
        {
            // Test for checking if the method returning determinat of given 1x1 matrix returns correct value.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                { 5.0 }
            };
            mx.set_input_matrix_1(input_matrix);
            mx.check_matrix_det();
            double expected_output = 5.0;
            double actual_output = mx.get_det();
            Assert::AreEqual(expected_output, actual_output);
            
        }

        TEST_METHOD(TestGetMatrixDeterminant2x2)
        {
            // Test for checking if the method returning determinat of given 2x2 matrix returns correct value.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                { 3.0, 7.0 },
                { 1.0, -4.0 }
            };
            mx.set_input_matrix_1(input_matrix);
            mx.check_matrix_det();
            double expected_output = -19.0;
            double actual_output = mx.get_det();
            Assert::AreEqual(expected_output, actual_output);

        }

        TEST_METHOD(TestGetMatrixDeterminant3x3)
        {
            // Test for checking if the method returning determinat of given 3x3 matrix returns correct value.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                { 2.0, 1.0, 3.0 },
                { 4.0, -2.0, -1.0 },
                { -5.0, 2.0, 6.0 }
            };
            mx.set_input_matrix_1(input_matrix);
            mx.check_matrix_det();
            double expected_output = -45.0;
            double actual_output = mx.get_det();
            Assert::AreEqual(expected_output, actual_output);

        }

        TEST_METHOD(TestGetMatrixMinorValid)
        {
            // Test for checking if method that cuts matrix minor works correctly.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                {1.1, 2.2, 3.3},
                {4.4, 5.5, 6.6},
                {7.7, 8.8, 9.9}
            };
            std::vector<std::vector<double>> expected_output = {
                {5.5, 6.6},
                {8.8, 9.9}
            };
            mx.set_input_matrix_1(input_matrix);
            mx.cut_minor_matrix(0, 0);
            std::vector<std::vector<double>> actual_output = mx.get_minor_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestGetMatrixMinorExceptionThrown)
        {
            // Test to check if the method throws an exception when invalid indices are used.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                {1.1, 2.2, 3.3},
                {4.4, 5.5, 6.6},
                {7.7, 8.8, 9.9}
            };
            mx.set_input_matrix_1(input_matrix);

            Assert::ExpectException<std::out_of_range>([&mx, &input_matrix] {
                mx.cut_minor_matrix(-1, 0);
                }, L"Expected std::out_of_range exception for invalid row index");

            Assert::ExpectException<std::out_of_range>([&mx, &input_matrix] {
                mx.cut_minor_matrix(0, 3);
                }, L"Expected std::out_of_range exception for invalid column index");
        }

        TEST_METHOD(TestGetTransposedMatrixValid2x2)
        {
            // Test for checking if method that sets transposed matrix works correctly.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                {1.1, 2.2},
                {4.4, 5.5},
            };
            std::vector<std::vector<double>> expected_output = {
                {1.1, 4.4},
                {2.2, 5.5},
            };
            mx.set_input_matrix_1(input_matrix);
            mx.transpose_matrix();
            std::vector<std::vector<double>> actual_output = mx.get_transposed_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestGetTransposedMatrixValid3x2)
        {
            // Test for checking if method that sets transposed matrix works correctly.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                {1.1, 2.2},
                {4.4, 5.5},
                {6.6, 7.7}
            };
            std::vector<std::vector<double>> expected_output = {
                {1.1, 4.4, 6.6},
                {2.2, 5.5, 7.7},
            };
            mx.set_input_matrix_1(input_matrix);
            mx.transpose_matrix();
            std::vector<std::vector<double>> actual_output = mx.get_transposed_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());
            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestCutAllMinors)
        {
            // Test for checking if the method cutting all minors from matrix works correctly.
            MatrixCalculations<double> mx;
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
            mx.set_input_matrix_1(input_matrix);
            mx.cut_all_minor_matrices();
            std::vector<std::vector<std::vector<double>>> actual_output = mx.get_all_minors();

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

        TEST_METHOD(TestAddMatrix)
        {
            // Test for checking if the method for adding two matrices works correctly.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                {1.0, 2.0, 3.0},
                {4.0, 5.0, 6.0},
                {7.0, 8.0, 9.0}
            };
            std::vector<std::vector<double>> expected_output = {
                {2.0, 4.0, 6.0},
                {8.0, 10.0, 12.0},
                {14.0, 16.0, 18.0}
            };

            mx.set_input_matrix_1(input_matrix);
            mx.set_input_matrix_2(input_matrix);

            mx.add_subtract(true);

            std::vector<std::vector<double>> actual_output = mx.get_output_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestSubtractMatrix)
        {
            // Test for checking if the method for subtracting two matrices works correctly.
            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> input_matrix = {
                {1.0, 2.0, 3.0},
                {4.0, 5.0, 6.0},
                {7.0, 8.0, 9.0}
            };
            std::vector<std::vector<double>> expected_output = {
                {0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0}
            };

            mx.set_input_matrix_1(input_matrix);
            mx.set_input_matrix_2(input_matrix);

            mx.add_subtract(false);

            std::vector<std::vector<double>> actual_output = mx.get_output_matrix();
            Assert::AreEqual(expected_output.size(), actual_output.size());

            for (size_t i = 0; i < expected_output.size(); ++i) {
                Assert::AreEqual(expected_output[i].size(), actual_output[i].size());

                for (size_t j = 0; j < expected_output[i].size(); ++j) {
                    Assert::AreEqual(expected_output[i][j], actual_output[i][j]);
                }
            }
        }

        TEST_METHOD(TestMultiplyMatrices_2x3_3x2)
        {
            // Test for multiplying a 2x3 matrix with a 3x2 matrix.
            MatrixCalculations<double> mx;

            // Input matrices
            std::vector<std::vector<double>> matrix_a{
                {1, 2, 3},
                {4, 5, 6}
            };

            std::vector<std::vector<double>> matrix_b{
                {7, 8},
                {9, 10},
                {11, 12}
            };
            mx.set_input_matrix_1(matrix_a);
            mx.set_input_matrix_2(matrix_b);

            // Expected result matrix (2x2)
            std::vector<std::vector<double>> expected_output{
                {58, 64},
                {139, 154}
            };

            // Perform multiplication
            mx.multiply_matrices();
            std::vector<std::vector<double>> actual_output = mx.get_output_matrix();

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

        TEST_METHOD(TestMultiplyMatrices_3x3_3x3)
        {
            // Test for multiplying two 3x3 matrices.
            MatrixCalculations<double> mx;

            // Input matrices
            std::vector<std::vector<double>> matrix_a{
                {1.0, 2.0, 3.0},
                {4.0, 5.0, 6.0},
                {7.0, 8.0, 9.0}
            };

            std::vector<std::vector<double>> matrix_b{
                {9.0, 8.0, 7.0},
                {6.0, 5.0, 4.0},
                {3.0, 2.0, 1.0}
            };
            mx.set_input_matrix_1(matrix_a);
            mx.set_input_matrix_2(matrix_b);

            // Expected result matrix (3x3)
            std::vector<std::vector<double>> expected_output{
                {30.0, 24.0, 18.0},
                {84.0, 69.0, 54.0},
                {138.0, 114.0, 90.0}
            };

            // Perform multiplication
            mx.multiply_matrices();
            std::vector<std::vector<double>> actual_output = mx.get_output_matrix();

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

        TEST_METHOD(TestCountDet1x1)
        {
            // Test for counting determinant of 1x1 matrix.

            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> matrix {
                {1}
            };

            mx.set_input_matrix_1(matrix);
            mx.count_det_large_matrix();

            double expected_output = 1.0;
            double actual_output = mx.get_det();

            Assert::AreEqual(expected_output, actual_output);
        }

        TEST_METHOD(TestCountDet2x2)
        {
            // Test for counting determinant of 2x2 matrix.

            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> matrix{
                {3.0, -4.0},
                {7.0, -6.0}
            };

            mx.set_input_matrix_1(matrix);
            mx.count_det_large_matrix();

            double expected_output = 10.0;
            double actual_output = mx.get_det();

            Assert::AreEqual(expected_output, actual_output);
        }

        TEST_METHOD(TestCountDet3x3)
        {
            // Test for counting determinant of 3x3 matrix.

            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> matrix{
                {2.0, 5.0, 3.0},
                {-1.0, 2.0, 5.0},
                {2.0, 1.0, 3.0}
            };

            mx.set_input_matrix_1(matrix);
            mx.count_det_large_matrix();

            double expected_output = 52.0;
            double actual_output = mx.get_det();

            Assert::AreEqual(expected_output, actual_output);
        }

        TEST_METHOD(TestCountDet4x4)
        {
            // Test for counting determinant of 4x4 matrix.

            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> matrix{
                {1.0, 0.0, 4.0, -6.0},
                {2.0, 5.0, 0.0, 3.0},
                {-1.0, 2.0, 3.0, 5.0},
                {2.0, 1.0, -2.0, 3.0}
            };

            mx.set_input_matrix_1(matrix);
            mx.count_det_large_matrix();

            double expected_output = 318.0;
            double actual_output = mx.get_det();

            Assert::AreEqual(expected_output, actual_output);
        }

        TEST_METHOD(TestCountDet5x5)
        {
            // Test for counting determinant of 5x5 matrix.

            MatrixCalculations<double> mx;
            std::vector<std::vector<double>> matrix{
                {-2, 7,	0, 6, -2 },
                { 1, -1, 3, 2, 2 },
                { 3, 4,	0, 5, 3 },
                { 2, 5, -4, -2,	2 },
                { 0, 3, -1,	1, -4 },
            };

            mx.set_input_matrix_1(matrix);
            mx.count_det_large_matrix();

            double expected_output = 1440.0;
            double actual_output = mx.get_det();

            Assert::AreEqual(expected_output, actual_output);
        }
	};
}
