#pragma once

#include <vector>
#include <iostream>

template<typename T>
class MatrixCalculations {
private:
    std::vector<std::vector<T>> input_matrix_1;
    std::vector<std::vector<T>> input_matrix_2;
    std::vector<std::vector<T>> output_matrix;
    T scalar;
    T det;
    std::vector<T> sizes;
    std::vector<std::vector<T>> minor_matrix;
    std::vector<std::vector<T>> transposed_matrix;
    std::vector<std::vector<std::vector<T>>> all_minors;

public:
    MatrixCalculations();

    void view(const std::vector<std::vector<T>>& vect);

    void set_input_matrix_1(const std::vector<std::vector<T>>& input_data);
    std::vector<std::vector<T>>& get_input_matrix_1();

    void set_input_matrix_2(const std::vector<std::vector<T>>& input_data);
    std::vector<std::vector<T>>& get_input_matrix_2();

    void set_output_matrix(const std::vector<std::vector<T>>& output_data);
    std::vector<std::vector<T>> get_output_matrix();

    void set_scalar(T scalar_value);
    T get_scalar();

    void set_det(T det_value);
    T get_det();

    void set_sizes(std::vector<T> sizes_value);
    std::vector<T> get_sizes();

    void set_minor_matrix(const std::vector<std::vector<T>>& minor_data);
    std::vector<std::vector<T>> get_minor_matrix();

    void set_transposed_matrix(const std::vector<std::vector<T>>& transposed_data);
    std::vector<std::vector<T>> get_transposed_matrix();

    void set_all_minors(const std::vector<std::vector<std::vector<T>>>& all_minors_data);
    std::vector<std::vector<std::vector<T>>> get_all_minors();

    void multiply_by_scalar();
    void add_subtract(bool add);
    void multiply_matrices();
    void check_matrix_det();
    void check_matrix_size();
    void cut_minor_matrix(int n, int m);
    void transpose_matrix();
    void cut_all_minor_matrices();
    void count_det_large_matrix();
    void invert_matrix();

};

#include "../../matrix_calculations_library/src/MatrixCalculations.cpp"
