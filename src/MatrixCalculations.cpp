#include <thread>
#include <future>
#include <mutex>
#include "../../matrix_calculations_library/include/MatrixCalculations.h"

template<typename T>
MatrixCalculations<T>::MatrixCalculations() {
    // Constructor sets up the default values of attributes.
    scalar = T();
    set_input_matrix_1({ {} });
    set_input_matrix_2({ {} });
    set_output_matrix({ {} });
}

template<typename T>
void MatrixCalculations<T>::view(const std::vector<std::vector<T>>& vect) {
    // Method that allows user to view the matrix given as argument in the console.
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            std::cout << vect[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void MatrixCalculations<T>::set_input_matrix_1(const std::vector<std::vector<T>>& input_data) {
    // Method that allows to set the value of input_matrix_1.
    input_matrix_1 = input_data;
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculations<T>::get_input_matrix_1() {
    // Method that allows to get the value of input_matrix_1.
    return input_matrix_1;
}

template<typename T>
void MatrixCalculations<T>::set_input_matrix_2(const std::vector<std::vector<T>>& input_data) {
    // Method that allows to set the value of input_matrix_2.
    input_matrix_2 = input_data;
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculations<T>::get_input_matrix_2() {
    // Method that allows to get the value of input_matrix_2.
    return input_matrix_2;
}

template<typename T>
void MatrixCalculations<T>::set_output_matrix(const std::vector<std::vector<T>>& output_data) {
    // Method that allows to set the value of output_matrix.
    output_matrix = output_data;
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculations<T>::get_output_matrix() {
    // Method that allows to get the value of output_matrix.
    return output_matrix;
}

template<typename T>
void MatrixCalculations<T>::set_scalar(T scalar_value) {
    // Method that allows to set the value of scalar.
    scalar = scalar_value;
}

template<typename T>
T MatrixCalculations<T>::get_scalar() {
    // Method that allows to get the value of scalar.
    return scalar;
}

template<typename T>
void MatrixCalculations<T>::set_det(T det_value) {
    // Method that allows to set the value of determinant.
    det = det_value;
}

template<typename T>
T MatrixCalculations<T>::get_det() {
    // Method that allows to get the value of determinant.
    return det;
}

template<typename T>
void MatrixCalculations<T>::set_sizes(std::vector<T> sizes_value) {
    // Method that allows to set the value of sizes.
    sizes = sizes_value;
}

template<typename T>
std::vector<T> MatrixCalculations<T>::get_sizes() {
    // Method that allows to get the value of sizes.
    return sizes;
}

template<typename T>
void MatrixCalculations<T>::set_minor_matrix(const std::vector<std::vector<T>>& minor_data) {
    // Method that allows to set the value of minor_matrix.
    minor_matrix = minor_data;
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculations<T>::get_minor_matrix() {
    // Method that allows to get the value of minor_matrix.
    return minor_matrix;
}

template<typename T>
void MatrixCalculations<T>::set_transposed_matrix(const std::vector<std::vector<T>>& transposed_data) {
    // Method that allows to set the value of transposed_matrix.
    transposed_matrix = transposed_data;
}

template<typename T>
std::vector<std::vector<T>> MatrixCalculations<T>::get_transposed_matrix() {
    // Method that allows to get the value of transposed_matrix.
    return transposed_matrix;
}

template<typename T>
void MatrixCalculations<T>::set_all_minors(const std::vector<std::vector<std::vector<T>>>& all_minors_data) {
    // Method that allows to set the value of all_minors.
    all_minors = all_minors_data;
}

template<typename T>
std::vector<std::vector<std::vector<T>>> MatrixCalculations<T>::get_all_minors() {
    // Method that allows to get the value of all_minors.
    return all_minors;
}

template<typename T>
void MatrixCalculations<T>::multiply_by_scalar() {
    // Method that allows to multiply a matrix by the scalar.

    std::vector<std::vector<T>> output(input_matrix_1.size());

    // Function thats multiplies the chosen rows of matrix by the scalar
    auto multiply_row = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row; ++i) {
            std::vector<T> row;
            for (int j = 0; j < input_matrix_1[i].size(); ++j) {
                row.push_back(input_matrix_1[i][j] * scalar);
            }
            output[i] = row;
        }
        };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create the future vector and variables for rows per threads and remainder
    std::vector<std::future<void>> futures;
    int rows_per_thread = input_matrix_1.size() / num_threads;
    int remainder = input_matrix_1.size() % num_threads;

    // Start the threads with the method and rows
    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, multiply_row, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Save the output to attribute
    set_output_matrix(output);
}

template<typename T>
void MatrixCalculations<T>::check_matrix_size() {
    // Sets the attribute 'sizes' with the value of sizes of given matrix.
    std::vector<std::vector<T>> vect = get_input_matrix_1();
    set_sizes( { T(vect.size()), T(vect[0].size()) } );
}

template<typename T>
void MatrixCalculations<T>::check_matrix_det() {
    // Sets the detrminent of 1x1, 2x2 or 3x3 matrix. Returns 0 if given matrix is different from these options.
    std::vector<std::vector<T>>& vect = get_input_matrix_1();
    if (vect.size() == 1 && vect[0].size() == 1) {
        set_det(vect[0][0]);
    }
    else if (vect.size() == 2 && vect[0].size() == 2) {
        set_det((vect[0][0] * vect[1][1]) - (vect[1][0] * vect[0][1]));
    }
    else if (vect.size() == 3 && vect[0].size() == 3) {
        set_det(
            (vect[0][0] * vect[1][1] * vect[2][2])
            + (vect[0][1] * vect[1][2] * vect[2][0])
            + (vect[0][2] * vect[1][0] * vect[2][1])
            - (vect[0][2] * vect[1][1] * vect[2][0])
            - (vect[0][0] * vect[1][2] * vect[2][1])
            - (vect[0][1] * vect[1][0] * vect[2][2])
            );
    }
    else {
        set_det(0);
    }
}

template<typename T>
void MatrixCalculations<T>::cut_minor_matrix(int n, int m) {
    // Sets the minor marix of given matrix with specified row and column to cut.
    std::vector<std::vector<T>>& vect = get_input_matrix_1();
    
    if (n < 0 || n >= vect.size() || m < 0 || m >= vect[0].size()) {
        throw std::out_of_range("Index out of bounds for minor matrix.");
    }

    std::vector<std::vector<T>> minor;

    for (size_t i = 0; i < vect.size(); ++i) {
        if (i == n) continue;  // Skip the row 'n'

        std::vector<T> row;
        for (size_t j = 0; j < vect[i].size(); ++j) {
            if (j == m) continue;  // Skip the column 'm'
            row.push_back(vect[i][j]);
        }
        minor.push_back(row);
    }

    set_minor_matrix(minor);
}

template<typename T>
void MatrixCalculations<T>::transpose_matrix() {
    // Sets a transposed matrix.

    std::mutex mutex_;  // Mutex to protect shared data
    std::vector<std::vector<T>> v(input_matrix_1[0].size(), std::vector<T>(input_matrix_1.size()));  // Prepare transposed matrix
    

    auto transpose = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row; ++i) {
            for (size_t j = 0; j < input_matrix_1[i].size(); ++j) {
                std::lock_guard<std::mutex> lock(mutex_);
                v[j][i] = input_matrix_1[i][j];  // Transpose elements
            }
        }
    };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create the future vector and variables for rows per threads and remainder
    std::vector<std::future<void>> futures;
    int rows_per_thread = input_matrix_1.size() / num_threads;
    int remainder = input_matrix_1.size() % num_threads;

    // Start the threads with the method and rows
    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, transpose, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Save the output to attribute
    set_transposed_matrix(v);
}

template<typename T>
void MatrixCalculations<T>::cut_all_minor_matrices() {
    // Sets vector with all minor matrixes cut from given marix.
    std::vector<std::vector<std::vector<T>>> all_minors_vect;
    std::vector<std::vector<T>>& vect = get_input_matrix_1();
    for (int n = 0; n < vect.size(); n++)
    {
        for (int m = 0; m < vect[0].size(); m++)
        {
            cut_minor_matrix(n, m);
            all_minors_vect.push_back(get_minor_matrix());
        }
    }
    set_all_minors(all_minors_vect);
}

template<typename T>
void MatrixCalculations<T>::add_subtract(bool add) {
    // Sets the output matrix as sum or diference of two input matrices.

    std::vector<std::vector<T>>& vect1 = get_input_matrix_1();
    std::vector<std::vector<T>>& vect2 = get_input_matrix_2();


    // Function thats multiplies the chosen rows of matrix by the scalar
    auto multiply_row = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row; i++)
        {
            for (int j = 0; j < vect1[i].size(); j++)
            {
                if (add) {
                    vect1[i][j] = vect1[i][j] + vect2[i][j];
                }
                else {
                    vect1[i][j] = vect1[i][j] - vect2[i][j];
                }
            }
        }
    };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create the future vector and variables for rows per threads and remainder
    std::vector<std::future<void>> futures;
    int rows_per_thread = input_matrix_1.size() / num_threads;
    int remainder = input_matrix_1.size() % num_threads;

    // Start the threads with the method and rows
    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, multiply_row, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Save the output to attribute
    set_output_matrix(vect1);
}

template<typename T>
void MatrixCalculations<T>::multiply_matrices() {
    // Method to multiple two matrices.

    // Get the dimensions of the result matrix
    size_t rows_a = input_matrix_1.size();
    size_t cols_a = input_matrix_1[0].size();  // Number of columns in A is also number of rows in B
    size_t cols_b = input_matrix_2[0].size();  // Number of columns in B

    // Initialize the result matrix C with dimensions rows_a x cols_b
    std::vector<std::vector<T>> result(rows_a, std::vector<T>(cols_b, 0));


    // Function thats multiplies the chosen rows of matrix by the scalar
    auto multiply = [&](int start_row, int end_row) {
        for (size_t i = start_row; i < end_row; ++i) {
            for (size_t j = 0; j < cols_b; ++j) {
                // Compute the dot product for result[i][j]
                for (size_t k = 0; k < cols_a; ++k) {
                    result[i][j] += input_matrix_1[i][k] * input_matrix_2[k][j];
                }
            }
        }
    };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (rows_a < num_threads || cols_b < num_threads) {
        num_threads = std::min(rows_a, cols_b); // Avoid creating more threads than needed
    }

    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create the future vector and variables for rows per threads and remainder
    std::vector<std::future<void>> futures;
    int rows_per_thread = input_matrix_1.size() / num_threads;
    int remainder = input_matrix_1.size() % num_threads;

    // Start the threads with the method and rows
    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, multiply, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Save the output to attribute
    set_output_matrix(result);
}