#include "../../matrix_calculations_library/include/MatrixIO.h"

template<typename T>
std::vector<std::vector<T>> MatrixIO<T>::load_matrix(std::string path) {
    std::ifstream file{ path };

    std::vector<std::vector<T>> vect;
    if (file.good()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string str_num;
            std::vector<T> temp;
            while (std::getline(ss, str_num, ' ')) {
                temp.emplace_back(std::stoi(str_num));
            }
            vect.emplace_back(temp);
        }
    }
    else {
        // TODO implementation of error mechanism
        std::cout << "Error!" << std::endl;
    }
    MatrixChecks<double> mxc;
    if (!mxc.integrity_check(vect)) {
        // TODO implementation of error mechanism
        std::cout << "Error!" << std::endl;
    }

    return vect;
}

