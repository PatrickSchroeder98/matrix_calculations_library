#include <thread>
#include <future>
#include <mutex>
#include "../../matrix_calculations_library/include/MatrixCalculations.h"

template<typename Func>
void run_parallel(int total_rows, Func process_rows) {
    // Method that handles multithreading for calculations.

    // Determine number of threads
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if undetected

    num_threads = std::min(static_cast<unsigned int>(total_rows), num_threads); // Adjust if rows < threads

    // Rows per thread and remainder for even distribution
    int rows_per_thread = total_rows / num_threads;
    int remainder = total_rows % num_threads;

    // Vector to hold futures for each thread
    std::vector<std::future<void>> futures;

    // Divide work and launch threads
    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, process_rows, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }
}

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
std::vector<std::vector<T>>& MatrixCalculations<T>::get_input_matrix_1() {
    // Method that allows to get the value of input_matrix_1.
    return input_matrix_1;
}

template<typename T>
void MatrixCalculations<T>::set_input_matrix_2(const std::vector<std::vector<T>>& input_data) {
    // Method that allows to set the value of input_matrix_2.
    input_matrix_2 = input_data;
}

template<typename T>
std::vector<std::vector<T>>& MatrixCalculations<T>::get_input_matrix_2() {
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
    std::vector<std::vector<T>> output(input_matrix_1.size());

    auto multiply_row = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row; ++i) {
            output[i].resize(input_matrix_1[i].size());
            for (size_t j = 0; j < input_matrix_1[i].size(); ++j) {
                output[i][j] = input_matrix_1[i][j] * scalar;
            }
        }
        };

    run_parallel(input_matrix_1.size(), multiply_row);
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
    std::mutex mutex_;
    std::vector<std::vector<T>> v(input_matrix_1[0].size(), std::vector<T>(input_matrix_1.size()));

    auto transpose = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row; ++i) {
            for (size_t j = 0; j < input_matrix_1[i].size(); ++j) {
                std::lock_guard<std::mutex> lock(mutex_);
                v[j][i] = input_matrix_1[i][j];
            }
        }
        };

    run_parallel(input_matrix_1.size(), transpose);
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
    std::vector<std::vector<T>>& vect1 = get_input_matrix_1();
    std::vector<std::vector<T>>& vect2 = get_input_matrix_2();

    // Define lambda for row-wise addition/subtraction
    auto add_subtract_row = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row; ++i) {
            for (size_t j = 0; j < vect1[i].size(); ++j) {
                vect1[i][j] = add ? vect1[i][j] + vect2[i][j] : vect1[i][j] - vect2[i][j];
            }
        }
        };

    // Run parallel addition/subtraction
    run_parallel(vect1.size(), add_subtract_row);

    // Save result
    set_output_matrix(vect1);
}

template<typename T>
void MatrixCalculations<T>::multiply_matrices() {
    size_t rows_a = input_matrix_1.size();
    size_t cols_a = input_matrix_1[0].size();
    size_t cols_b = input_matrix_2[0].size();

    std::vector<std::vector<T>> result(rows_a, std::vector<T>(cols_b, 0));

    // Define lambda for row-wise multiplication
    auto multiply = [&](int start_row, int end_row) {
        for (size_t i = start_row; i < end_row; ++i) {
            for (size_t j = 0; j < cols_b; ++j) {
                for (size_t k = 0; k < cols_a; ++k) {
                    result[i][j] += input_matrix_1[i][k] * input_matrix_2[k][j];
                }
            }
        }
        };

    // Run parallel multiplication
    run_parallel(rows_a, multiply);

    // Save result
    set_output_matrix(result);
}

template<typename T>
void MatrixCalculations<T>::count_det_large_matrix() {
    // Method to calculate determinant of large matrices.
    if (input_matrix_1.size() <= 3) {
        check_matrix_det();
    }
    else {
        std::vector<std::vector<T>> tmp = input_matrix_1;
        int sum = 0;

        std::vector<T> row = input_matrix_1[0];

        for (int k = 1; k < row.size(); k = k + 2) {
            row[k] = row[k] * -1;
        }

        for (int i = 0; i < input_matrix_1[0].size(); i++) {
            cut_minor_matrix(0, i);
            set_input_matrix_1(get_minor_matrix());
            count_det_large_matrix();
            row[i] = row[i] * get_det();
            set_input_matrix_1(tmp);
        }
        for (auto& n : row) {
            sum += n;
        }
        set_det(sum);
    }
}
