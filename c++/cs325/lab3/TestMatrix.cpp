#include "Matrix.h" //we call the Matrix class from Matrix.h
#include <iostream> //include iostream library/header file for c++
using namespace std;//use std namespace to save doing std:: with standard methods

//4.1: Matrix(mxn) testcases

//test case 0 for Matrix(mxn).
void Test_Case_0_Constructor(){
    cout<<"Test case 0 (empty matrix):"<<endl;
    Matrix m0(0, 2);//set m0(0, n) should return empty matrix
    //print m0 using its size [0x2] (should return an empty matrix)
    for (unsigned int i = 0; i < 0; i++) {
        for (unsigned int j = 0; j < 2; j++) {
            cout << m0.get(i, j) << " ";//we use get method to print and follow assignment format
        }
        cout << endl;
    }
    cout<<endl;
}
//test case 1 for Matrix(mxn).
void Test_Case_1_Constructor(){
    cout<<"Test case 1:"<<endl;
    Matrix m1(6, 7);//set m1(m, n) so a matrix of 6 rows & 7 columns
    //print m1 using its size [6x7]
    for (unsigned int i = 0; i < 6; i++) {
        for (unsigned int j = 0; j < 7; j++) {
            cout << m1.get(i, j) << " ";//we use get method to print and follow assignment format
        }
        cout << endl;
    }
}
//test case 2 for Matrix(mxn).
void Test_Case_2_Constructor(){
    cout<<"Test case 2:"<<endl;
    Matrix m2(5, 5);//set m2(m, n) so a matrix of 5 rows & 5 columns
    //print m2 using its size [5x5]
    for (unsigned int i = 0; i < 5; i++) {
        for (unsigned int j = 0; j < 5; j++) {
            cout << m2.get(i, j) << " ";//we use get method to print and follow assignment format
        }
        cout << endl;
    }
}

//4.2: Matrix(mxn) copy testcases

//test case 1 for Matrix(mxn) copy.
void Test_Case_1_Copy(){
    cout<<"Test case 1:"<<endl;
    Matrix m1(6, 7);
    Matrix m3(m1); //copy matrix1 to matrix3
    //print m3 (should be the same as m1)
    for (unsigned int i = 0; i < 6; i++) {
        for (unsigned int j = 0; j < 7; j++) {
            cout << m3.get(i, j) << " "; //we use get method to print and follow assignment format
        }
        cout << endl;
    }
}
//test case 2 for Matrix(mxn) copy.
void Test_Case_2_Copy(){
    cout<<"Test case 2:"<<endl;
    Matrix m2(5, 5);
    Matrix m4(m2); //copy matrix2 to matrix4
    //print m4 (should be the same as m2)
    for (unsigned int i = 0; i < 5; i++) {
        for (unsigned int j = 0; j < 5; j++) {
            cout << m4.get(i, j) << " "; //we use get method to print and follow assignment format
        }
        cout << endl;
    }
}
//test case 3 for Matrix(mxn) copy.
void Test_Case_3_Copy(){
    cout<<"Test case 3 (copy has own memory):"<<endl;
    Matrix m1(2, 2);
    //we set values to m1 instead of just 0
    m1.set(0,0,1); m1.set(0,1,2); m1.set(1,0,3); m1.set(1,1,4); //set uses question 4.7 to give m1 real values
    Matrix m3(m1); //copy m1 to m3
    m1.set(0,0,9); //change m1 after copying (m3 doesnt change)
    //print m1
    cout<<"filled m1:"<<endl;
    for (unsigned int i = 0; i < m1.rows(); i++) {
        for (unsigned int j = 0; j < m1.columns(); j++) {
            cout << m1.get(i, j) << " ";
        }
        cout << endl;
    }
    //print m3, expect 1 2 / 3 4 (unchanged since it has separate memory)
    cout<<"m3 (copy):"<<endl;
    for (unsigned int i = 0; i < m3.rows(); i++) {
        for (unsigned int j = 0; j < m3.columns(); j++) {
            cout << m3.get(i, j) << " ";
        }
        cout << endl;
    }
}

//4.3: Matrix m[i][j] 2D Array testcases

//test case 1 for Matrix m[i][j] 2D Array.
void Test_Case_1_Array(){
    cout<<"Test case 1:"<<endl;
    //set m and n for Matrix[m][n]
    int** mx = new int*[4]; //set one pointer per row
    for (int i = 0; i < 4; i++) {
        mx[i] = new int[2]; //row contains 2 values
    }
    //set array values
    mx[0][0] = 1; mx[0][1] = 2; 
    mx[1][0] = 3; mx[1][1] = 4;
    mx[2][0] = 5; mx[2][1] = 6; 
    mx[3][0] = 7; mx[3][1] = 8;
    Matrix m5(mx, 4, 2); //create matrix from 2D array
    //free 2D array (m5 has own copy of values)
    for (int i = 0; i < 4; i++) {
        delete[] mx[i];
    }
    delete[] mx;
    //print m5 after memory freed
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 2; j++) {
            cout << m5.get(i, j) << " "; //we use get method to print and follow assignment format
        }
        cout << endl;
    }
}
//test case 2 for Matrix m[i][j] 2D Array.
void Test_Case_2_Array(){
    cout<<"Test case 2:"<<endl;
    //set m and n for Matrix[m][n]
    int** my = new int*[2]; //set one pointer per row
    for (int i = 0; i < 2; i++) {
        my[i] = new int[2]; //row contains 2 values
    }
    //set array values
    my[0][0] = 6; my[0][1] = 1; 
    my[1][0] = 1; my[1][1] = 7;
    Matrix m6(my, 2, 2); //create matrix from 2D array
    //free 2D array (m6 has own copy of values)
    for (int i = 0; i < 2; i++) {
        delete[] my[i];
    }
    delete[] my;
    //print m6 after memory freed
    for (unsigned int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 2; j++) {
            cout << m6.get(i, j) << " "; //we use get method to print and follow assignment format
        }
        cout << endl;
    }
}

//4.4: row return testcases

//test case 1 for row return.
void Test_Case_1_Rows(){
    cout<<"Test case 1:"<<endl;
    Matrix m1(6, 7);
    cout<< "rows in m1: "<< m1.rows()<<endl; //returns number of rows in m1
}
//test case 2 for row return.
void Test_Case_2_Rows(){
    cout<<"Test case 2:"<<endl;
    int** mx = new int*[4]; //one pointer per row
    for (int i = 0; i < 4; i++) {
        mx[i] = new int[2]; //each row has 2 values
    }
    mx[0][0] = 1; mx[0][1] = 2;
    mx[1][0] = 3; mx[1][1] = 4;
    mx[2][0] = 5; mx[2][1] = 6;
    mx[3][0] = 7; mx[3][1] = 8;
    Matrix m5(mx, 4, 2);
    //free the 2D array (m5 has its own copy)
    for (int i = 0; i < 4; i++) {
        delete[] mx[i];
    }
    delete[] mx;
    cout<< "rows in m5: "<< m5.rows()<<endl; //returns number of rows in m5
}

//4.5: column return testcases

//test case 1 for column return.
void Test_Case_1_Columns(){
    cout<<"Test case 1:"<<endl;
    Matrix m2(5, 5);
    cout<< "columns in m2: "<< m2.columns()<<endl; //returns number of columns in m2
}
//test case 2 for column return.
void Test_Case_2_Columns(){
    cout<<"Test case 2:"<<endl;
    //build m6 with the 2D array constructor (4.3)
    int** my = new int*[2]; //one pointer per row
    for (int i = 0; i < 2; i++) {
        my[i] = new int[2]; //each row has 2 values
    }
    my[0][0] = 6; my[0][1] = 1;
    my[1][0] = 1; my[1][1] = 7;
    Matrix m6(my, 2, 2);
    //free the 2D array (m6 has its own copy)
    for (int i = 0; i < 2; i++) {
        delete[] my[i];
    }
    delete[] my;
    cout<< "columns in m6: "<< m6.columns()<<endl; //returns number of columns in m6
}

//4.6: get(i,j) testcases

//test case 1 for get(i,j).
void Test_Case_1_Get(){
    cout<<"Test case 1:"<<endl;
    //build m6 with the 2D array constructor (4.3)
    int** my = new int*[2]; //one pointer per row
    for (int i = 0; i < 2; i++) {
        my[i] = new int[2]; //each row has 2 values
    }
    my[0][0] = 6; my[0][1] = 1;
    my[1][0] = 1; my[1][1] = 7;
    Matrix m6(my, 2, 2);
    //free the 2D array (m6 has its own copy)
    for (int i = 0; i < 2; i++) {
        delete[] my[i];
    }
    delete[] my;
    cout<< "element in m6[0][1]: "<< m6.get(0,1)<<endl; //returns element at m6[0][1]
}
//test case 2 for get(i,j).
void Test_Case_2_Get(){
    cout<<"Test case 2:"<<endl;
    //build m5 with the 2D array constructor (4.3)
    int** mx = new int*[4]; //one pointer per row
    for (int i = 0; i < 4; i++) {
        mx[i] = new int[2]; //each row has 2 values
    }
    mx[0][0] = 1; mx[0][1] = 2;
    mx[1][0] = 3; mx[1][1] = 4;
    mx[2][0] = 5; mx[2][1] = 6;
    mx[3][0] = 7; mx[3][1] = 8;
    Matrix m5(mx, 4, 2);
    //free the 2D array (m5 has its own copy)
    for (int i = 0; i < 4; i++) {
        delete[] mx[i];
    }
    delete[] mx;
    cout<< "element in m5[2][1]: "<< m5.get(2,1)<<endl; //returns element at m5[2][1]
}
//test case 3 for get(i,j).
void Test_Case_3_Get(){
    cout<<"Test case 3 (out of range):"<<endl;
    Matrix m2(2, 2);
    //i and j are outside the matrix size so 0 is returned
    cout<< "element in m2[5][5]: "<< m2.get(5,5)<<endl;
}

//4.7: set(i,j,value) testcases

//test case 1 for set(i,j,value).
void Test_Case_1_Set(){
    cout<<"Test case 1:"<<endl;
    Matrix m2(5, 5);
    m2.set(0,1,7);
    //print m2 fully again to see the changed value
    for (unsigned int i = 0; i < m2.rows(); i++) {
        for (unsigned int j = 0; j < m2.columns(); j++) {
            cout << m2.get(i, j) << " ";
        }
        cout << endl;
    }
}
//test case 2 for set(i,j,value).
void Test_Case_2_Set(){
    cout<<"Test case 2:"<<endl;
    Matrix m2(5, 5);
    m2.set(0,1,7);
    m2.set(3,2,2);
    //print m2 fully again to see both values changed
    for (unsigned int i = 0; i < m2.rows(); i++) {
        for (unsigned int j = 0; j < m2.columns(); j++) {
            cout << m2.get(i, j) << " ";
        }
        cout << endl;
    }
}
//test case 3 for set(i,j,value).
void Test_Case_3_Set(){
    cout<<"Test case 3 (out of range):"<<endl;
    Matrix m2(2, 2);
    m2.set(5,5,9); //i and j are outside the matrix size so nothing changes
    //print m2, expect 0 0 / 0 0
    for (unsigned int i = 0; i < m2.rows(); i++) {
        for (unsigned int j = 0; j < m2.columns(); j++) {
            cout << m2.get(i, j) << " ";
        }
        cout << endl;
    }
}

//4.8 + operator

//test case 1 for matrix operation +.
void Test_Case_1_Plus(){
    cout<<"Test case 1:"<<endl;
    cout<<"Matrix m7:"<<endl;
    Matrix m7(2, 2); //constructor from question 1, all zeros
    m7.set(0,0,10); m7.set(0,1,10); m7.set(1,0,10); m7.set(1,1,10); //we set actual values for matrix
    for (unsigned int i = 0; i < m7.rows(); i++) {
        for (unsigned int j = 0; j < m7.columns(); j++) {
            cout << m7.get(i, j) << " ";
        }
        cout << endl;
    }
    cout<<"-----------------------------------------"<<endl;
    cout<<"Matrix m8:"<<endl;
    Matrix m8(2, 2); //constructor from question 1, all zeros
    m8.set(0,0,1); m8.set(0,1,2); m8.set(1,0,3); m8.set(1,1,4); //we set actual values for matrix
    for (unsigned int i = 0; i < m8.rows(); i++) {
        for (unsigned int j = 0; j < m8.columns(); j++) {
            cout << m8.get(i, j) << " ";
        }
        cout << endl;
    }
    cout<<"-----------------------------------------"<<endl;
    cout<<"we sum m7 + m8:"<<endl;
    Matrix sum(m7 + m8);
    //print the sum, expect 11 12 / 13 14
    for (unsigned int i = 0; i < sum.rows(); i++) {
        for (unsigned int j = 0; j < sum.columns(); j++) {
            cout << sum.get(i, j) << " ";
        }
        cout << endl;
    }
}
//test case 2 for matrix operation +.
void Test_Case_2_Plus(){
    cout<<"Test case 2 (different sizes):"<<endl;
    Matrix mx(2, 2);
    Matrix my(3, 3);
    Matrix sum(mx + my); //sizes don't match so empty matrix is returned
    //empty matrix -> rows: 0, columns: 0
    cout<<"rows: "<< sum.rows() <<", columns: "<< sum.columns() <<endl;
}

//4.9 - operator

//test case 1 for matrix operation -.
void Test_Case_1_Minus(){
    cout<<"Test case 1:"<<endl;
    Matrix m7(2, 2);
    m7.set(0,0,10); m7.set(0,1,10); m7.set(1,0,10); m7.set(1,1,10);
    Matrix m8(2, 2);
    m8.set(0,0,1); m8.set(0,1,2); m8.set(1,0,3); m8.set(1,1,4);
    cout<<"we subtract m7 - m8:"<<endl;
    Matrix subt(m7 - m8);
    //print the difference, expect 9 8 / 7 6
    for (unsigned int i = 0; i < subt.rows(); i++) {
        for (unsigned int j = 0; j < subt.columns(); j++) {
            cout << subt.get(i, j) << " ";
        }
        cout << endl;
    }
}

//4.10 * operator

//test case 1 for matrix operation *.
void Test_Case_1_Multiply(){
    cout<<"Test case 1:"<<endl;
    Matrix m7(2, 2);
    m7.set(0,0,10); m7.set(0,1,10); m7.set(1,0,10); m7.set(1,1,10);
    Matrix m8(2, 2);
    m8.set(0,0,1); m8.set(0,1,2); m8.set(1,0,3); m8.set(1,1,4);
    cout<<"we multiply m7 * m8:"<<endl;
    Matrix mult(m7 * m8);
    //print the product, expect 40 60 / 40 60
    for (unsigned int i = 0; i < mult.rows(); i++) {
        for (unsigned int j = 0; j < mult.columns(); j++) {
            cout << mult.get(i, j) << " ";
        }
        cout << endl;
    }
}
//test case 2 for matrix operation *.
void Test_Case_2_Multiply(){
    cout<<"Test case 2:"<<endl;
    Matrix ma(2, 2);
    ma.set(0,0,1); ma.set(0,1,2); ma.set(1,0,3); ma.set(1,1,4);
    cout<<"Matrix ma:"<<endl;
    for (unsigned int i = 0; i < ma.rows(); i++) {
        for (unsigned int j = 0; j < ma.columns(); j++) {
            cout << ma.get(i, j) << " ";
        }
        cout << endl;
    }
    Matrix mb(2, 2);
    mb.set(0,0,5); mb.set(0,1,6); mb.set(1,0,7); mb.set(1,1,8);
    cout<<"Matrix mb:"<<endl;
    for (unsigned int i = 0; i < mb.rows(); i++) {
        for (unsigned int j = 0; j < mb.columns(); j++) {
            cout << mb.get(i, j) << " ";
        }
        cout << endl;
    }
    cout<<"we multiply ma * mb:"<<endl;
    Matrix mult(ma * mb);
    //print the product, expect 19 22 / 43 50
    for (unsigned int i = 0; i < mult.rows(); i++) {
        for (unsigned int j = 0; j < mult.columns(); j++) {
            cout << mult.get(i, j) << " ";
        }
        cout << endl;
    }
}

//4.11 ~ operator (matrix transpose)

//test case 1 for matrix transpose operation.
void Test_Case_1_Transpose(){
    cout<<"Test case 1:"<<endl;
    Matrix m5(4, 2);
    m5.set(0,0,1); m5.set(0,1,2); m5.set(1,0,3); m5.set(1,1,4);
    m5.set(2,0,5); m5.set(2,1,6); m5.set(3,0,7); m5.set(3,1,8);
    cout<<"we show the transpose of m5:"<<endl;
    Matrix transp1(~m5);
    for (unsigned int i = 0; i < transp1.rows(); i++) {
        for (unsigned int j = 0; j < transp1.columns(); j++) {
            cout << transp1.get(i, j) << " ";
        }
        cout << endl;
    }
}
//test case 2 for matrix transpose operation.
void Test_Case_2_Transpose(){
    cout<<"Test case 2:"<<endl;
    Matrix m8(2, 2);
    m8.set(0,0,1); m8.set(0,1,2); m8.set(1,0,3); m8.set(1,1,4);
    cout<<"we show the transpose of m8:"<<endl;
    Matrix transp2(~m8);
    for (unsigned int i = 0; i < transp2.rows(); i++) {
        for (unsigned int j = 0; j < transp2.columns(); j++) {
            cout << transp2.get(i, j) << " ";
        }
        cout << endl;
    }
}

//4.12 == operator

//test case 1 for matrix operation ==.
void Test_Case_1_Equal(){
    cout<<"Test case 1:"<<endl;
    Matrix m7(2, 2);
    m7.set(0,0,10); m7.set(0,1,10); m7.set(1,0,10); m7.set(1,1,10);
    Matrix m8(2, 2);
    m8.set(0,0,1); m8.set(0,1,2); m8.set(1,0,3); m8.set(1,1,4);
    cout<<"we check if m7 == m8: "<< ((m7 == m8) ? "true(1)" : "false(0)")<<endl;
}
//test case 2 for matrix operation ==.
void Test_Case_2_Equal(){
    cout<<"Test case 2:"<<endl;
    Matrix m8(2, 2);
    m8.set(0,0,1); m8.set(0,1,2); m8.set(1,0,3); m8.set(1,1,4);
    cout<<"Matrix m8:"<<endl;
    //print m8 under its label
    for (unsigned int i = 0; i < m8.rows(); i++) {
        for (unsigned int j = 0; j < m8.columns(); j++) {
            cout << m8.get(i, j) << " ";
        }
        cout << endl;
    }
    Matrix m9(m8);//we copy m8 to m9 and check if theyre equal
    cout<<"we check if m8 == m9: "<< ((m8 == m9) ? "true(1)" : "false(0)")<<endl;
}
//test case 3 for matrix operation ==.
void Test_Case_3_Equal(){
    cout<<"Test case 3 (different sizes):"<<endl;
    Matrix a(2, 2);
    Matrix b(3, 3);
    //false(0) since different sizes
    cout<<"we check if a == b: "<< ((a == b) ? "true(1)" : "false(0)")<<endl;
}

//4.13 toStr()

//test case 1 for toStr().
void Test_Case_1_ToStr(){
    cout<<"Test case 1:"<<endl;
    Matrix m5(4, 2);
    m5.set(0,0,1); m5.set(0,1,2); m5.set(1,0,3); m5.set(1,1,4);
    m5.set(2,0,5); m5.set(2,1,6); m5.set(3,0,7); m5.set(3,1,8);
    string s = m5.toStr(); //store the returned string in s
    cout<<"m5 to string:"<<endl;
    cout<< s;
}
//test case 2 for toStr().
void Test_Case_2_ToStr(){
    cout<<"Test case 2:"<<endl;
    Matrix m0(0, 2);
    cout<<"m0 to string (empty matrix):"<<endl;
    cout<< m0.toStr(); //returns an empty string since m0 has no rows
}

/**
 *test program that runs testcases for methods in Matrix class
 *@param none
 *@return 0 if the program ran successfully
 */
int main()
{
    cout<<"Matrix 4.1 tests"<<endl;
    Test_Case_0_Constructor();
    Test_Case_1_Constructor();
    Test_Case_2_Constructor();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.2 tests"<<endl;
    Test_Case_1_Copy();
    Test_Case_2_Copy();
    Test_Case_3_Copy();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.3 tests"<<endl;
    Test_Case_1_Array();
    Test_Case_2_Array();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.4 tests"<<endl;
    Test_Case_1_Rows();
    Test_Case_2_Rows();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.5 tests"<<endl;
    Test_Case_1_Columns();
    Test_Case_2_Columns();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.6 tests"<<endl;
    Test_Case_1_Get();
    Test_Case_2_Get();
    Test_Case_3_Get();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.7 tests"<<endl;
    Test_Case_1_Set();
    Test_Case_2_Set();
    Test_Case_3_Set();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.8 tests"<<endl;
    Test_Case_1_Plus();
    Test_Case_2_Plus();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.9 tests"<<endl;
    Test_Case_1_Minus();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.10 tests"<<endl;
    Test_Case_1_Multiply();
    Test_Case_2_Multiply();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.11 tests"<<endl;
    Test_Case_1_Transpose();
    Test_Case_2_Transpose();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.12 tests"<<endl;
    Test_Case_1_Equal();
    Test_Case_2_Equal();
    Test_Case_3_Equal();
    cout<<"-------------------------------------------"<<endl;

    cout<<"Matrix 4.13 tests"<<endl;
    Test_Case_1_ToStr();
    Test_Case_2_ToStr();
    cout<<"-------------------------------------------"<<endl;

    //return 0 for the int function
    return 0;
}