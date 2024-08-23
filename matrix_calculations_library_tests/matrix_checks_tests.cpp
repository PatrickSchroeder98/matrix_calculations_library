#include "pch.h"
#include "CppUnitTest.h"
#include "../../matrix_calculations_library/include/MatrixChecks.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace matrixcheckstests
{
	TEST_CLASS(matrixcheckstests)
	{
		// Class with library tests
	public:
        TEST_METHOD(TestSetMatrixSizes)
        {
			std::vector<std::vector<double>> vect1{
				{1.1, 2.2, 3.3},
				{4.4, 5.5, 6.6},
				{7.7, 8.8, 9.9}
			};
			MatrixChecks<double> mxc;
			mxc.sizes_check(vect1, vect1);
            //TODO finish tests
        }
	};
}
