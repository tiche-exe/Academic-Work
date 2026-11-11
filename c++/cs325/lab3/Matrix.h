//we include string for question 4.13
#include <string>
using namespace std;//use std namespace to save doing std:: for question 4.13

//stores a matrix of integers of size [m×n] using dynamic memory on the heap
class Matrix{

    private://only methods of this class can access these

    /**
    *assignment operator is private and not defined (following the slides) so a matrix
    *can't be shallow copied by accident, which would free the same memory twice
    *@param mat (matrix to assign from, passed by const reference [read-only])
    *@return reference to current matrix (never used since it is not defined)
    */
    Matrix& operator=(const Matrix & mat);

    public://any code can call these methods

    /**
    *initialises a matrix of size [m×n], every element in this matrix is 0
    *@param m (number of rows passed by value [read-only])
    *@param n (number of columns passed by value [read-only])
    *@return none (NO return values for constructors)
    */
    Matrix(unsigned int m , unsigned int n);

    /**
    *copies every element from matrix mat (has memory separate from mat)
    *@param mat (matrix to copy passed by const reference [read-only])
    *@return none (NO return values for constructors)
    */
    Matrix(const Matrix &mat);

    /**
    *initialises the matrix using a 2D array with size of m x n
    *@param array is a 2D array of size m x n to copy values from (read-only, not changed)
    *@param m number of rows, passed by value (read-only)
    *@param n number of columns, passed by value (read-only)
    *@return none (NO return values for constructors)
    */
    Matrix(int ** array, unsigned int m, unsigned int n);
    
    /**
    *returns the number of rows in the matrix
    *@param none
    *@return (number of rows (m_))
    */
    unsigned int rows() const;

    /**
    *returns the number of columns in the matrix
    *@param none
    *@return (number of columns (n_))
    */
    unsigned int columns() const;

    /**
    *returns the element at the ith row and jth column (i and j begin at 0)
    *returns 0 if i or j is outside the matrix size
    *@param i (row index, passed by value [read-only])
    *@param j (column index, passed by value [read-only])
    *@return (element at position (i,j))
    */
    int get(unsigned i, unsigned j) const;

    /**
    *update value at ith row and jth column. (i and j here begin at 0)
    *return if i or j is outside the matrix size
    *@param i (row index, passed by value [read-only])
    *@param j (column index, passed by value [read-only])
    *@param value (value to switch to position [read-only])
    *@return none (it is a void method so nothing is returned)
    */
    void set(unsigned i, unsigned j, int value);

    /**
    *returns a matrix that contains the results of addition of two matrices
    *@param mat (matrix to add, passed by const reference [read-only])
    *@return new matrix containing sum or an empty [0x0] matrix if different sizes
    */
    Matrix operator+(const Matrix & mat);

    /**
    *returns a matrix that contains the results of subtraction of two matrices
    *@param mat (matrix to subtract, passed by const reference [read-only])
    *@return matrix containing difference or an empty [0x0] matrix if different sizes
    */
    Matrix operator-(const Matrix & mat);

    /**
    *returns a matrix that contains the results of multiplication of two matrices.
    *@param mat (matrix to multiply by, passed by const reference [read-only])
    *@return a new matrix containing the product, or an empty 0x0 matrix if
    *current matrix columns != rows of mat
    */
    Matrix operator*(const Matrix & mat);

    /**
    *returns the transpose of current matrix (rows <-become-> columns)
    *@param none
    *@return transpose matrix of current matrix
    */
    Matrix operator~() const;

    /**
    *returns true(1) if two matrices are the same, otherwise false(0). 
    *Two matrices are the same iff they both contain the same element at exact location
    *in each matrix
    *@param mat (matrix to compare with, passed by const reference [read-only])
    *@return true (1) if both are the same, otherwise false (0)
    */
    bool operator==(const Matrix & mat);

    /**
    *returns a string representation (showing every element in the matrix) of
    *the matrix
    *@param none
    *@return string representation of matrix
    */
    string toStr();

    /**
    *uses destructor to free heap memory used by the matrix. 
    *@param none
    *@return none (NO return values for destructors)
    */
    ~Matrix();

    protected://only methods of this class and its subclasses can access these

    unsigned int m_, n_; //number of rows (m) and columns (n)
    int* arr_; //pointer to array of size [m_*n_]
};