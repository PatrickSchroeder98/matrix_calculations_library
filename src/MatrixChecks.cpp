#include <thread>
#include <future>
#include <atomic>
#include "../../matrix_calculations_library/include/MatrixChecks.h"

template<typename T>
bool MatrixChecks<T>::integrity_check(std::vector<std::vector<T>> vect) {
    // Returns true if all rows of given matrix have equal size.
    double temp = vect[0].size();
    for (std::vector<T> i : vect) {
        if (i.size() != temp) { return false; }
    }
    return true;
}

template<typename T>
bool MatrixChecks<T>::sizes_check(std::vector<std::vector<T>> vect1, std::vector<std::vector<T>> vect2) {
    // Returns true if two matrixes are equal in sizes.
    if (vect1.size() != vect2.size()) { return false; }

    for (int i = 0; i < vect1.size(); i++)
    {
        if (vect1[i].size() != vect2[i].size()) { return false; }
    }

    return true;
}

template<typename T>
bool MatrixChecks<T>::column_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a column matrix.
    for (std::vector<T> i : vect) {
        if (i.size() != 1) { return false; }
    }
    return true;
}

template<typename T>
bool MatrixChecks<T>::row_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a row matrix.
    if (vect.size() != 1) { return false; }
    return true;
}

template<typename T>
bool MatrixChecks<T>::rectangular_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a rectangular matrix.
    if (vect.size() == vect[0].size()) { return false; }
    return true;
}

template<typename T>
bool MatrixChecks<T>::square_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a square matrix. Assumes that all rows are equal in sizes.
    if (vect.size() != vect[0].size()) { return false; }
    return true;
}

template<typename T>
bool MatrixChecks<T>::identity_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is an identity matrix.
    if (!square_matrix_check(vect)) {
        return false;
    }

    // Shared atomic flag to signal if any thread detects an anomaly
    std::atomic<bool> is_true{ true };

    auto check = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row && is_true; i++) {  // Exit if flag is false
            for (int j = 0; j < vect[i].size(); j++) {
                if ((i == j && vect[i][i] != 1) || (i != j && vect[i][j] != 0)) {
                    is_true = false;  // Detected anomaly, stop further checks
                    return;
                }
            }
        }
        };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create futures and divide work across threads
    std::vector<std::future<void>> futures;
    int rows_per_thread = vect.size() / num_threads;
    int remainder = vect.size() % num_threads;

    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, check, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Return the final result
    return is_true;
}

template<typename T>
bool MatrixChecks<T>::diagonal_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is an diagonal matrix.
    
    if (!square_matrix_check(vect)) {
        return false;
    }

    // Shared atomic flag to signal if any thread detects an anomaly
    std::atomic<bool> is_true{ true };

    auto check = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row && is_true; i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                if (vect[i][i] == 0) {
                    is_true = false;
                    return;
                }
                else if (i != j && vect[i][j] != 0) {
                    is_true = false;
                    return;
                }
            }
        }
        };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create futures and divide work across threads
    std::vector<std::future<void>> futures;
    int rows_per_thread = vect.size() / num_threads;
    int remainder = vect.size() % num_threads;

    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, check, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Return the final result
    return is_true;
}

template<typename T>
bool MatrixChecks<T>::scalar_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is an scalar matrix.
    
    if (!square_matrix_check(vect)) {
        return false;
    }
    T temp = vect[0][0];
    // Shared atomic flag to signal if any thread detects an anomaly
    std::atomic<bool> is_true { true };

    auto check = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row && is_true; i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                if (vect[i][i] != temp) {
                    is_true = false;
                    return;
                }
                else if (i != j && vect[i][j] != 0) {
                    is_true = false;
                    return;
                }
            }
        }
    };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create futures and divide work across threads
    std::vector<std::future<void>> futures;
    int rows_per_thread = vect.size() / num_threads;
    int remainder = vect.size() % num_threads;

    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, check, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Return the final result
    return is_true;
}

template<typename T>
bool MatrixChecks<T>::null_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a null matrix.
    
    // Shared atomic flag to signal if any thread detects an anomaly
    std::atomic<bool> is_true{ true };

    auto check = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row && is_true; i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                if (vect[i][j] != 0) {
                    is_true = false;
                    return;
                }
            }
        }
        };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create futures and divide work across threads
    std::vector<std::future<void>> futures;
    int rows_per_thread = vect.size() / num_threads;
    int remainder = vect.size() % num_threads;

    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, check, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Return the final result
    return is_true;
}

template<typename T>
bool MatrixChecks<T>::upper_lower_triangular_matrix_check(std::vector<std::vector<T>> vect, bool lower) {
    // Returns true if given matrix is an upper or lower triangular matrix - depending on boolean argument.

    if (!square_matrix_check(vect)) {
        return false;
    }

    // Shared atomic flag to signal if any thread detects an anomaly
    std::atomic<bool> is_true{ true };

    auto check = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row && is_true; i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                if (lower) {
                    if (i < j) { // lower triangular matrix check

                        if (vect[i][j] != 0) {
                            is_true = false;
                            return;
                        }
                    }
                }
                else {
                    if (i > j) { // upper triangular matrix check

                        if (vect[i][j] != 0) {
                            is_true = false;
                            return;
                        }
                    }
                }
            }
        }
    };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create futures and divide work across threads
    std::vector<std::future<void>> futures;
    int rows_per_thread = vect.size() / num_threads;
    int remainder = vect.size() % num_threads;

    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, check, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Return the final result
    return is_true;
}

template<typename T>
bool MatrixChecks<T>::equality_check(std::vector<std::vector<T>> vect1, std::vector<std::vector<T>> vect2) {
    // Returns true if two matrixes are equal.
    if (vect1.size() != vect2.size()) { return false; }

    // Shared atomic flag to signal if any thread detects an anomaly
    std::atomic<bool> is_true{ true };

    auto check = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row && is_true; i++)
        {
            if (vect1[i].size() != vect2[i].size()) { 
                is_true = false;
                return;
            }
            for (int j = 0; j < vect1[i].size(); j++)
            {
                if (vect1[i][j] != vect2[i][j]) { 
                    is_true = false;
                    return;
                }
            }
        }
    };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create futures and divide work across threads
    std::vector<std::future<void>> futures;
    int rows_per_thread = vect1.size() / num_threads;
    int remainder = vect1.size() % num_threads;

    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, check, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Return the final result
    return is_true;
}

template<typename T>
bool MatrixChecks<T>::binary_matrix_check(std::vector<std::vector<T>> vect) {
    // Returns true if given matrix is a binary matrix.

    // Shared atomic flag to signal if any thread detects an anomaly
    std::atomic<bool> is_true{ true };

    auto check = [&](int start_row, int end_row) {
        for (int i = start_row; i < end_row && is_true; i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                if (vect[i][j] != 0 && vect[i][j] != 1) {
                    is_true = false;
                    return;
                }
            }
        }
    };

    // Determine the number of threads to use
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;  // Fallback to 2 if unable to detect

    // Create futures and divide work across threads
    std::vector<std::future<void>> futures;
    int rows_per_thread = vect.size() / num_threads;
    int remainder = vect.size() % num_threads;

    int start_row = 0;
    for (unsigned int i = 0; i < num_threads; ++i) {
        int end_row = start_row + rows_per_thread + (i < remainder ? 1 : 0);
        futures.emplace_back(std::async(std::launch::async, check, start_row, end_row));
        start_row = end_row;
    }

    // Wait for all threads to complete
    for (auto& fut : futures) {
        fut.get();
    }

    // Return the final result
    return is_true;
}