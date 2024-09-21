#include <iostream>
#include <vector>
#include "../../matrix_calculations_library/include/MatrixCalculationsAPI.h"
#include "../../matrix_calculations_library/include/MatrixCalculations.h"
#include "../../matrix_calculations_library/include/MatrixChecks.h"
#include "../../matrix_calculations_library/include/MatrixIO.h"

int main() {
    // Example with double type
    
    std::vector<std::vector<double>> vect_double{
       {1.1, 2.2, 3.3},
       {4.4, 5.5, 6.6},
       {7.7, 8.8, 9.9}
    };
    std::vector<std::vector<double>> vect_double2{
       {10.1, 20.2, 30.3},
       {40.4, 50.5, 60.6},
       {70.7, 80.8, 90.9}
    };
    std::vector<std::vector<double>> vect_output;
    MatrixIO<double> mio;
    MatrixCalculations<double> mclc;
    MatrixChecks<double> mxc;
    MatrixCalculationsAPI<double> API;

    //vect_double = mio.load_matrix("C:/src/data.dat");
    std::cout << "Intput matrix 1:" << std::endl;
    mclc.view(vect_double);
    std::cout << std::endl;
    std::cout << "Intput matrix 2:" << std::endl;
    mclc.view(vect_double2);
    std::cout << std::endl;

    vect_output = API.add_matrices(vect_double, vect_double2);
    std::cout << "Output matrix after adding matrix 1 and matrix 2:" << std::endl;
    mclc.view(vect_output);
    std::cout << std::endl;

    std::cout << "Intput matrix 1:" << std::endl;
    mclc.view(vect_double);
    std::cout << std::endl;
    std::cout << "Intput matrix 2:" << std::endl;
    mclc.view(vect_double2);
    std::cout << std::endl;

    vect_output = API.subtract_matrices(vect_double, vect_double2);
    std::cout << "Output matrix after subtraction matrix 2 from matrix 1:" << std::endl;
    mclc.view(vect_output);
    std::cout << std::endl;

    std::cout << "Intput matrix 1:" << std::endl;
    mclc.view(vect_double);
    std::cout << std::endl;
    std::cout << "Output matrix after multiplying input matrix 1 by scalar equal to 2.0:" << std::endl;
    vect_output = API.multiply_matrix_by_scalar(vect_double, 2.0);
    mclc.view(vect_output);
    std::cout << std::endl;

    std::cout << "Intput matrix 1:" << std::endl;
    mclc.view(vect_double);
    std::cout << std::endl;
    std::cout << "Output matrix being transposed input matrix 1:" << std::endl;
    vect_output = API.transpose_matrix(vect_double);
    mclc.view(vect_output);
    std::cout << std::endl;

    std::cout << "Intput matrix 1:" << std::endl;
    mclc.view(vect_double);
    std::cout << std::endl;
    std::cout << "Intput matrix 2:" << std::endl;
    mclc.view(vect_double2);
    std::cout << std::endl;
    vect_output = API.multiply_matrices(vect_double, vect_double2);
    std::cout << "Output matrix after multiplying matrix 1 by matrix 2:" << std::endl;
    mclc.view(vect_output);
    std::cout << std::endl;

    //mio.save_matrix("C:/src/data_saved.dat", vect_double);
    return 0;
}
