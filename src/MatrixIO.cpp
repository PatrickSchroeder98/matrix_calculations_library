#include "../../matrix_calculations_library/include/MatrixIO.h"
#include "../../matrix_calculations_library/src/MatrixExceptions.cpp"


template<typename T>
std::vector<std::vector<T>> MatrixIO<T>::load_matrix(std::string path) {
    std::ifstream file{ path };

    std::vector<std::vector<T>> vect;
    try {
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
            throw MatrixFileOperationException("Invalid file with matrix.", 2);
        }
    } catch (const MatrixFileOperationException& e) {
        std::cout << e.what() << " (Error code: " << e.getErrorCode() << ")\n";
    }

    MatrixChecks<double> mxc;
    try {
        if (!mxc.integrity_check(vect)) {
            throw MatrixDimensionMismatchException("Invalid dimensions of matrix.", 1);
        }
    }
    catch (const MatrixDimensionMismatchException& e) {
        std::cout << " (Error code: " << e.getErrorCode() << ")\n";
        return { {} };
    }
    return vect;
}

template<typename T>
bool MatrixIO<T>::save_matrix(const std::string& path, const std::vector<std::vector<T>>& vect) {
    std::ofstream file{ path };

    try {
        if (file.good()) {
            for (size_t i = 0; i < vect.size(); i++) {
                for (size_t j = 0; j < vect[i].size(); j++) {
                    file << vect[i][j] << " ";
                }
                file << "\n";
            }
            return true;
        }
        else {
            throw MatrixFileOperationException("Invalid file with matrix.", 2);
            std::cout << "Error!" << std::endl;
            return false;
        }
    } catch (const MatrixFileOperationException& e) {
        std::cout << e.what() << " (Error code: " << e.getErrorCode() << ")\n";
    }
}

