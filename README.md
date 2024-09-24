# Matrix Calculations Library

The Matrix Calculations Library is a lightweight, header-only C++ library that provides an API for performing basic matrix operations. This project includes operations such as matrix addition, subtraction, multiplication (both by scalar and between matrices), and transposition. It is multithreaded for better performance in handling larger matrices. The library also supports exception handling for invalid operations like dimension mismatches.  


This project is designed with a clear and easy-to-use API, allowing you to perform matrix operations through simple method calls. The matrix operations are optimized for both correctness and performance, including threading support for larger matrix computations.  

## Features  
* Matrix addition
* Matrix subtraction
* Matrix multiplication (matrix by matrix and matrix by scalar)
* Matrix transposition
* Exception handling for dimension mismatches
* Multithreaded operations for faster computations on large matrices

## Project Structure  
* MatrixCalculationsAPI: The main public-facing API for interacting with matrix operations.
* MatrixCalculations: Internal matrix operations logic, including multithreaded execution for addition, subtraction, and multiplication.
* MatrixChecks: Helper class for checking matrix properties like dimensions.
* Custom Exceptions: Exception classes such as MatrixDimensionMismatchException for better error reporting.  

## Multithreading  
To optimize performance, the library uses multithreading features to divide operations like matrix addition and subtraction across multiple threads. The number of threads is determined by the hardware concurrency of the system. Each thread handles a portion of the matrix, speeding up operations significantly on large matrices.  

## Tests  
The project includes a comprehensive set of unit tests written using the CppUnitTestFramework to ensure that the all modules are working correctly and are handling edge cases properly.  

## Full Documentation  
The full documentation can be found on the [Software Documentation Website](https://patrickschroeder98.github.io/software_documentation/matrix_library_docs/index.html).  
Or in the websie [repository](https://github.com/PatrickSchroeder98/software_documentation/tree/main/matrix_library_docs).  

## Future Improvements  
* Extend matrix operations to support more advanced linear algebra functions (e.g., matrix inversion, determinants).
* Enhance multithreading support for these operations.