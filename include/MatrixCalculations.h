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

public:
    MatrixCalculations();

    void view(const std::vector<std::vector<T>>& vect);

    void set_input_matrix_1(const std::vector<std::vector<T>>& input_data);
    std::vector<std::vector<T>> get_input_matrix_1();

    void set_input_matrix_2(const std::vector<std::vector<T>>& input_data);
    std::vector<std::vector<T>> get_input_matrix_2();

    void set_output_matrix(const std::vector<std::vector<T>>& output_data);
    std::vector<std::vector<T>> get_output_matrix();

    void set_scalar(T scalar_value);
    T get_scalar();

    void multiply_by_scalar();
    std::vector<T> get_matrix_size(std::vector<std::vector<T>> vect);
};

#include "../../matrix_calculations_library/src/MatrixCalculations.cpp"
