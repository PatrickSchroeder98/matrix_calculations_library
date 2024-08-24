#include "pch.h"
#include "CppUnitTest.h"
#include "../../matrix_calculations_library/include/MatrixChecks.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace matrixcheckstests
{
	TEST_CLASS(matrixcheckstests)
	{
		// Class with checks tests
	public:
        TEST_METHOD(TestCheckMatrixSizesTrue)
        {
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
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.row_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixRowFalse)
		{
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
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{1.1, 2.2, 3.3}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.rectangular_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixRectangularFalse)
		{
			std::vector<std::vector<double>> vect1{
				{1.1}
			};
			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.rectangular_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixSquareTrue)
		{
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2},
				{1.1, 2.2}
			};
			MatrixChecks<double> mxc;
			Assert::IsTrue(mxc.square_matrix_check(vect1));
		}

		TEST_METHOD(TestCheckMatrixSquareFalse)
		{
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2}
			};
			MatrixChecks<double> mxc;
			Assert::IsFalse(mxc.square_matrix_check(vect1));
		}
	};
}
