#include <iostream>
#include <vector>
#include "../../matrix_calculations_library/include/MatrixCalculations.h"
#include "../../matrix_calculations_library/include/MatrixChecks.h"
#include "../../matrix_calculations_library/include/MatrixIO.h"

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
    
    MatrixIO<double> mio;
    vect = mio.load_matrix("C:/src/data.dat");
    std::cout << std::endl;
    mx_double.view(vect);
    std::vector<double> size = mx_double.get_matrix_size(vect);
    std::cout << size[0] << std::endl << size[1] << std::endl;
    return 0;
}
