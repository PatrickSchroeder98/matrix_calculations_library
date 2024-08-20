class MatrixCalculations {
private:
    std::vector<std::vector<double>> input_matrix_1;
    std::vector<std::vector<double>> input_matrix_2;
    std::vector<std::vector<double>> output_matrix;
    double scalar;

public:
    MatrixCalculations();
    void view(std::vector<std::vector<double>> vect);
    void set_input_matrix_1(std::vector<std::vector<double>> input_data);
    std::vector<std::vector<double>> get_input_matrix_1();
    void set_output_matrix(std::vector<std::vector<double>> output_data);
    std::vector<std::vector<double>> get_output_matrix();
    std::vector<std::vector<double>> multiply_by_scalar();

};