#include <iostream>
#include <vector>
#include "../../matrix_calculations_library/include/MatrixCalculations.h"
#include "../../matrix_calculations_library/include/MatrixChecks.h"

int main() {
    // Example with double type
    std::cout << "Intput matrix:" << std::endl;
    std::vector<std::vector<double>> vect_double{
       {1.1, 2.2, 3.3},
       {4.4, 5.5, 6.6},
       {7.7, 8.8, 9.9}
    };

    MatrixCalculations<double> mx_double;
    mx_double.view(vect_double);

    std::cout << std::endl << "Output matrix after multiplying by scalar = 2.2" << std::endl;
    mx_double.set_input_matrix_1(vect_double);
    mx_double.set_scalar(double(2.2));
    mx_double.multiply_by_scalar();
    mx_double.view(mx_double.get_output_matrix());

    MatrixChecks<double> mxc;
    mxc.column_matrix_check(vect_double);

    std::vector<std::vector<double>> vect{
       {2, 0, 0},
       {0, 2, 0},
       {0, 0, 2}
    };

    std::cout << mxc.scalar_matrix_check(vect);
    

    /*// Example with int type
    std::vector<std::vector<int>> vect_int{
       {1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}
    };

    MatrixCalculations<int> mx_int;
    mx_int.set_input_matrix_1(vect_int);
    mx_int.set_scalar(2); // Example scalar
    mx_int.multiply_by_scalar();
    mx_int.view(mx_int.get_output_matrix());

    // Example with float type
    std::vector<std::vector<float>> vect_float{
       {1.1f, 2.2f, 3.3f},
       {4.4f, 5.5f, 6.6f},
       {7.7f, 8.8f, 9.9f}
    };

    MatrixCalculations<float> mx_float;
    mx_float.set_input_matrix_1(vect_float);
    mx_float.set_scalar(2.0f); // Example scalar
    mx_float.multiply_by_scalar();
    mx_float.view(mx_float.get_output_matrix());*/

    return 0;
}
