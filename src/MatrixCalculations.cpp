#include <vector>
#include "../../matrix_calculations_library/include/MatrixCalculations.h"

MatrixCalculations::MatrixCalculations() {
    scalar = 0.0;
    set_output_matrix({ {} });
}

void MatrixCalculations::view(std::vector<std::vector<double>> vect) {
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            std::cout << vect[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void MatrixCalculations::set_input_matrix_1(std::vector<std::vector<double>> input_data) {
    input_matrix_1 = input_data;
}

std::vector<std::vector<double>> MatrixCalculations::get_input_matrix_1() {
    return input_matrix_1;
}

void MatrixCalculations::set_output_matrix(std::vector<std::vector<double>> output_data) {
    output_matrix = output_data;
}

std::vector<std::vector<double>> MatrixCalculations::get_output_matrix() {
    return output_matrix;
}

std::vector<std::vector<double>> MatrixCalculations::multiply_by_scalar() {
    std::vector<std::vector<double>> output;
    std::vector<double> row;
    double m = 0;
    for (int i = 0; i < input_matrix_1.size(); i++)
    {
        for (int j = 0; j < input_matrix_1[i].size(); j++)
        {
            row.push_back(input_matrix_1[i][j] * scalar);
        }
        output.emplace_back(row);
        row = {};
    }
    set_output_matrix(output);
    return output;
}
