#include "Matrix.h" //we call the Matrix class from Matrix.h
#include <iostream> //include iostream library/header file for c++
using namespace std;//use std namespace to save doing std:: with standard methods

/**
 *initialises a matrix of size [m×n], every element in this matrix is 0
 *@param m (number of rows passed by value [read-only])
 *@param n (number of columns passed by value [read-only])
 *@return none (NO return values for constructors)
 */
Matrix::Matrix(unsigned int m , unsigned int n) : m_(m), n_(n){//initialiser list stores m, n in members m_, n_

    //set new array data with m_ & n_ values in memory
    arr_ = new int[m_ * n_];

    for (unsigned int i = 0; i < m_; i++) { //loop through rows
        for (unsigned int j = 0; j < n_; j++) { //loop through columns

            //assign values to the memory block
            //i*n_ skips earlier rows, j moves to column, sums to arr_ to find exact location in matrix
            //(makes it be used like a 2D array)
            *(arr_ + i * n_ + j) = 0; //sets Matrix(i, j) = 0
        }
    }
}

/**
 *copies every element from matrix mat (has memory separate from mat)
 *@param mat (matrix to copy passed by const reference [read-only])
 *@return none (NO return values for constructors)
 */
Matrix::Matrix(const Matrix &mat) : m_(mat.m_), n_(mat.n_){//initialiser list copies mat size (m_, n_)

    //set new array data with m_ & n_ values in separate memory
    arr_ = new int[m_ * n_];

    for (unsigned int i = 0; i < m_; i++) { //loop through rows
        for (unsigned int j = 0; j < n_; j++) { //loop through columns
            //copy values from mat into new matrix
            *(arr_ + i * n_ + j) = *(mat.arr_ + i * mat.n_ + j);//copies mat(i, j) to Matrix(i, j)
        }
    }
}

/**
*initialises the matrix using a 2D array with size of [mxn] (takes a 2D array input and copies it into the matrix)
*@param array (2D array of size [mxn] to copy values [read-only, unchanged])
*@param m (number of rows passed by value [read-only])
*@param n (number of columns passed by value [read-only])
*@return none (NO return values for constructors)
*/
Matrix::Matrix(int** array, unsigned int m, unsigned int n) : m_(m), n_(n){//initialiser list stores m, n in members m_, n_

    //set new array data with m_ & n_ values in memory
    arr_ = new int[m_ * n_];

    for (unsigned int i = 0; i < m_; i++) { //loop through rows
        for (unsigned int j = 0; j < n_; j++) { //loop through columns
            //copy array[i][j] into matrix position (i,j)
            *(arr_ + i * n_ + j) = array[i][j];
        }
    }
}

/**
*returns the number of rows in the matrix
*@param none
*@return (number of rows (m_))
*/
unsigned int Matrix::rows() const{
    return m_; //m_ stores the number of rows
}

/**
*returns the number of columns in the matrix
*@param none
*@return (number of columns (n_))
*/
unsigned int Matrix::columns() const{
    return n_; //n_ stores the number of columns
}

/**
*returns the element at the ith row and jth column (i and j begin at 0)
*returns 0 if i or j is outside the matrix size
*@param i (row index, passed by value [read-only])
*@param j (column index, passed by value [read-only])
*@return (element at position (i,j))
*/
int Matrix::get(unsigned i, unsigned j) const{
    //returns 0 if i or j is outside the matrix size
    if (i >= m_ || j >= n_) {
        return 0;
    }
    
    //i*n_ skips earlier rows, j moves to column, sums to arr_ to find exact location in matrix
    return *(arr_ + i * n_ + j);
}

/**
*update value at ith row and jth column. (i and j here begin at 0)
*return if i or j is outside the matrix size
*@param i (row index, passed by value [read-only])
*@param j (column index, passed by value [read-only])
*@param value (value to switch to position [read-only])
*@return none (it is a void method so nothing is returned)
*/
void Matrix::set(unsigned i, unsigned j, int value){
    //return if i or j is outside the matrix size
    if (i >= m_ || j >= n_) {
        return;
    }

    //i*n_ skips earlier rows, j moves to column, sums to arr_ to find exact location in matrix and then set it to the value
    *(arr_ + i * n_ + j) = value;
}

/**
*returns a matrix that contains the results of addition of two matrices
*@param mat (matrix to add, passed by const reference [read-only])
*@return new matrix containing sum or an empty [0x0] matrix if different sizes
*/
Matrix Matrix::operator+(const Matrix & mat){
    //matrices must be the same size to add
    if (m_ != mat.m_ || n_ != mat.n_) {
        return Matrix(0, 0); //return an empty matrix if NOT same size
    }

    Matrix sum(m_, n_); //new matrix of same size (starts as zeros)

    for (unsigned int i = 0; i < m_; i++) { //loop through rows
        for (unsigned int j = 0; j < n_; j++) { //loop through columns
            //add elements at the same position and store in result
            sum.set(i, j, get(i, j) + mat.get(i, j));
        }
    }
    return sum;
}

/**
*returns a matrix that contains the results of subtraction of two matrices
*@param mat (matrix to subtract, passed by const reference [read-only])
*@return matrix containing difference or an empty [0x0] matrix if different sizes
*/
Matrix Matrix::operator-(const Matrix & mat){
    //matrices must be the same size to subtract
    if (m_ != mat.m_ || n_ != mat.n_) {
        return Matrix(0, 0); //return an empty matrix
    }

    Matrix subt(m_, n_); //new matrix of same size (starts as zeros)

    for (unsigned int i = 0; i < m_; i++) { //loop through rows
        for (unsigned int j = 0; j < n_; j++) { //loop through columns
            //subtracts elements at the same position and store in result
            subt.set(i, j, get(i, j) - mat.get(i, j));
        }
    }
    return subt;
}

/**
*returns a matrix that contains the results of multiplication of two matrices.
*@param mat (matrix to multiply by, passed by const reference [read-only])
*@return a new matrix containing the product, or an empty 0x0 matrix if
*current matrix columns != rows of mat
*/
Matrix Matrix::operator*(const Matrix & mat){ //matrix multiplication: dot product of rows from matrix1 & columns from matrix2
    //columns of the current matrix must equal rows of mat
    if (n_ != mat.m_) {
        return Matrix(0, 0); //return an empty matrix
    }

    Matrix mult(m_, mat.n_); //result has rows of current matrix, columns of mat

    for (unsigned int i = 0; i < m_; i++) { //loop through rows of current matrix
        for (unsigned int j = 0; j < mat.n_; j++) { //loop through columns of mat
            int sum = 0;
            //multiply row i of current matrix by column j of mat and add them up
            for (unsigned int k = 0; k < n_; k++) {
                sum += get(i, k) * mat.get(k, j);
            }
            mult.set(i, j, sum); //store the total at (i,j)
        }
    }
    return mult;
}

/**
*returns the transpose of current matrix (rows <-become-> columns)
*@param none
*@return transpose matrix of current matrix
*/
Matrix Matrix::operator~() const{
    Matrix transp(n_, m_); //rows and columns are swapped

    for (unsigned int i = 0; i < m_; i++) { //loop through rows
        for (unsigned int j = 0; j < n_; j++) { //loop through columns
            //element (i,j) of current matrix becomes element (j,i) of result
            transp.set(j, i, get(i, j));
        }
    }
    return transp;
}

/**
*returns true(1) if two matrices are the same, otherwise false(0). 
*Two matrices are the same iff they both contain the same element at exact location
*in each matrix
*@param mat (matrix to compare with, passed by const reference [read-only])
*@return true (1) if both are the same, otherwise false (0)
*/
bool Matrix::operator==(const Matrix & mat){
    //matrices of different sizes can't be the same
    if (m_ != mat.m_ || n_ != mat.n_) {
        return false;
    }

    for (unsigned int i = 0; i < m_; i++) { //loop through rows
        for (unsigned int j = 0; j < n_; j++) { //loop through columns
            //if any element is different, the matrices are not the same
            if (get(i, j) != mat.get(i, j)) {
                return false;
            }
        }
    }
    return true; //every element is the same
}

/**
*returns a string representation (showing every element in the matrix) of
*the matrix
*@param none
*@return string representation of matrix
*/
string Matrix::toStr(){

    string s = ""; //start w/ empty string

    for (unsigned int i = 0; i < m_; i++) { //loop through rows
        for (unsigned int j = 0; j < n_; j++) { //loop through columns
            s += to_string(get(i, j)) + " "; //convert element to string and add it
        }
        s += "\n"; //new line at the end of each row
    }
    return s;
}

/**
 *use destructor to free heap memory used by the matrix. 
*@param none
*@return none (NO return values for destructors)
*/
Matrix::~Matrix(){
    //free memory from arr_
    delete[] arr_;
    //set arr_ to a nullptr so it points to null and doesnt point to freed memory
    arr_ = nullptr;
}