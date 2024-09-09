#include <exception>
#include <string>

class MatrixDimensionMismatchException : public std::runtime_error {
private:
    int error_code;

public:
    MatrixDimensionMismatchException(const std::string& message, int code)
        : std::runtime_error(message), error_code(code) {}

    int getErrorCode() const noexcept {
        return error_code;
    }

    virtual const char* what() const noexcept override {
        return ("Matrix Dimension Mismatch Error: " + std::string(std::runtime_error::what()) +
            ", Error Code: " + std::to_string(error_code)).c_str();
    }
};


class MatrixFileOperationException : public std::runtime_error {
private:
    int error_code;

public:
    MatrixFileOperationException(const std::string& message, int code)
        : std::runtime_error(message), error_code(code) {}

    int getErrorCode() const noexcept {
        return error_code;
    }

    virtual const char* what() const noexcept override {
        return ("Matrix File Operation Error: " + std::string(std::runtime_error::what()) +
            ", Error Code: " + std::to_string(error_code)).c_str();
    }
};
