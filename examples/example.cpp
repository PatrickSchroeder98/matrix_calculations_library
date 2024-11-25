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
    std::vector<std::vector<std::vector<double>>> all_minors;
    
    MatrixCalculationsAPI<double> API;
    MatrixCalculations<double> MC;

    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    std::cout << std::endl;
    std::cout << "Input matrix 2:" << std::endl;
    API.view(vect_double2);
    std::cout << std::endl;

    vect_output = API.add_matrices(vect_double, vect_double2);
    std::cout << "Output matrix after adding matrix 1 and matrix 2:" << std::endl;
    API.view(vect_output);
    std::cout << std::endl;

    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    std::cout << std::endl;
    std::cout << "Input matrix 2:" << std::endl;
    API.view(vect_double2);
    std::cout << std::endl;

    vect_output = API.subtract_matrices(vect_double, vect_double2);
    std::cout << "Output matrix after subtraction matrix 2 from matrix 1:" << std::endl;
    API.view(vect_output);
    std::cout << std::endl;

    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    std::cout << std::endl;
    std::cout << "Output matrix after multiplying input matrix 1 by scalar equal to 2.0:" << std::endl;
    vect_output = API.multiply_matrix_by_scalar(vect_double, 2.0);
    API.view(vect_output);
    std::cout << std::endl;

    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    std::cout << std::endl;
    std::cout << "Output matrix being transposed input matrix 1:" << std::endl;
    vect_output = API.transpose_matrix(vect_double);
    API.view(vect_output);
    std::cout << std::endl;

    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    std::cout << std::endl;
    std::cout << "Input matrix 2:" << std::endl;
    API.view(vect_double2);
    std::cout << std::endl;
    vect_output = API.multiply_matrices(vect_double, vect_double2);
    std::cout << "Output matrix after multiplying matrix 1 by matrix 2:" << std::endl;
    API.view(vect_output);
    std::cout << std::endl;

    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    std::cout << std::endl;
    vect_output = API.cut_minor(vect_double, 0, 0);
    std::cout << "Output minor matrix after cutting row 0 and column 0:" << std::endl;
    API.view(vect_output);
    std::cout << std::endl;

    vect_output = API.load_matrix("C:/src/data.dat");
    std::cout << "Matrix loaded from file:" << std::endl;
    API.view(vect_output);
    API.save_matrix("C:/src/data_saved.dat", vect_output);
    std::cout << std::endl;

    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    std::cout << std::endl;
    all_minors = API.cut_all_minors(vect_double);
    std::cout << "All minors cut from matrix 1:" << std::endl;
    for (size_t i = 0; i < all_minors.size(); i++)
    {
        API.view(all_minors[i]);
        std::cout << std::endl;
    }
    

    vect_double = {
        {-2, 7,	0, 6, -2 },
        { 1, -1, 3, 2, 2 },
        { 3, 4,	0, 5, 3 },
        { 2, 5, -4, -2,	2 },
        { 0, 3, -1,	1, -4 },
    };
    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    double result = API.count_det(vect_double);
    std::cout << "Result of determinant: " << result << std::endl;
    std::cout << std::endl;

    vect_double = {
       {2.0, 1.0, 0.0},
       {1.0, -1.0, 1.0},
       {3.0, 2.0, 1.0}
    };
    std::cout << "Input matrix 1:" << std::endl;
    API.view(vect_double);
    std::cout << std::endl;
    vect_output = API.invert_matrix(vect_double);
    std::cout << "Output matrix after inverting matrix 1:" << std::endl;
    API.view(vect_output);
    std::cout << std::endl;

    return 0;
}
