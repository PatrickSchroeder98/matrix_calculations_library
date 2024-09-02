#include <thread>
#include <future>
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
void MatrixCalculations<T>::check_matrix_size(std::vector<std::vector<T>> vect) {
    // Sets the attribute 'sizes' with the value of sizes of given matrix.
    set_sizes( { T(vect.size()), T(vect[0].size()) } );
}

template<typename T>
void MatrixCalculations<T>::check_matrix_det(std::vector<std::vector<T>> vect) {
    // Returns the detrminent of 1x1, 2x2 or 3x3 matrix. Returns 0 if given matrix is different from these options.
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
void MatrixCalculations<T>::cut_minor_matrix(const std::vector<std::vector<T>>& vect, int n, int m) {
    // Validate inputs: Check if n and m are within the matrix bounds
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