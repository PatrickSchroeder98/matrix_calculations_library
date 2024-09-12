#include <iostream>
#include <vector>
#include "../../matrix_calculations_library/include/MatrixCalculationsAPI.h"
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
    std::vector<std::vector<double>> vect_double2{
       {1.1, 2.2, 3.3},
       {4.4, 5.5, 6.6},
       {7.7, 8.8, 9.9}
    };
    MatrixIO<double> mio;
    MatrixCalculations<double> mclc;
    MatrixChecks<double> mxc;
    MatrixCalculationsAPI<double> API;

    //vect_double = mio.load_matrix("C:/src/data.dat");
    mclc.view(vect_double);
    std::cout << std::endl;

    vect_double = API.add_matrices(vect_double, vect_double2);
    mclc.view(vect_double);

    mio.save_matrix("C:/src/data_saved.dat", vect_double);
    return 0;
}
