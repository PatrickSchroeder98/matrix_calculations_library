#include "pch.h"
#include "CppUnitTest.h"
#include "../../matrix_calculations_library/include/MatrixChecks.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace matrixcheckstests
{
	TEST_CLASS(matrixcheckstests)
	{
		// Class with tests of methods from MatrixChecks class.

	public:
		TEST_METHOD(TestCheckMatrixIntegrityTrue)
		{
			// Test to check if integrity matrix check returns true if matrix have correct form. 
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.integrity_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixIntegrityFalse)
		{
			// Test to check if integrity matrix check returns false if matrix does not have correct form.  
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8}
			};
			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.integrity_check(vect1));
		}

        TEST_METHOD(TestCheckMatrixSizesTrue)
        {
			// Test to check method that compares two equal matrixes sizes. 
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.sizes_check(vect1, vect1));
        }

		TEST_METHOD(TestCheckMatrixSizesFalse1)
		{
			// Test to check method that compares two differnt matrixes sizes.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};

			std::vector<std::vector<double>> vect2{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
			};

			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.sizes_check(vect1, vect2));
		}

		TEST_METHOD(TestCheckMatrixSizesFalse2)
		{
			// Alternative test to check method that compares two differnt matrixes sizes.
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

			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.sizes_check(vect1, vect2));
		}

		TEST_METHOD(TestCheckMatrixColumnTrue)
		{
			// Test to check if column_matrix_check() method returns true if given matrix is a column matrix.
			std::vector<std::vector<double>> vect1{
				{1.1},
				{4.4},
				{7.7}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.column_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixColumnFalse)
		{
			// Test to check if column_matrix_check() method returns false if given matrix is not a column matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2},
				{4.4, 3.3},
				{7.7, 4.4}
			};
			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.column_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixRowTrue)
		{
			// Test to check if row_matrix_check() method returns true if given matrix is a row matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.row_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixRowFalse)
		{
			// Test to check if row_matrix_check() method returns false if given matrix is not a row matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2},
				{4.4, 3.3},
				{7.7, 4.4}
			};
			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.row_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixRectangularTrue)
		{
			// Test to check if rectangular_matrix_check() method returns true if given matrix is a rectangular matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{1.1, 2.2, 3.3}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.rectangular_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixRectangularFalse)
		{
			// Test to check if rectangular_matrix_check() method returns false if given matrix is not a rectangular matrix.
			std::vector<std::vector<double>> vect1{
				{1.1}
			};
			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.rectangular_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixSquareTrue)
		{
			// Test to check if square_matrix_check() method returns true if given matrix is a square matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2},
				{1.1, 2.2}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.square_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixSquareFalse)
		{
			// Test to check if square_matrix_check() method returns false if given matrix is a not a square matrix.
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2}
			};
			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.square_matrix_check(vect1));
		}
	};
}
