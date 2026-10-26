//Mateo Inigo Lahera Lab 1 cs325

//include iostream library/header file for c++
#include <iostream>
//use std namespace to save doing std:: with standard methods
using namespace std;

int main(){
    int n1;
    int n2;
    cout<< "Input int 1: ";
    cin>> n1;
    cout<< "Input int 2: ";
    cin>> n2;

    //n2 can NEVER be 0 because you cant divide by 0
    while (n2 != 0){
        //use euclidean algorithm:
        //divide n1/n2 to find remainder
        int r = n1 % n2;
        /*keep going by setting n1=n2 and n2=remainder until remainder is 0, if it reaches 0 it ends so we get last non-zero 
        remainder (n1) which is the greatest common divisor*/
        n1 = n2;
        n2 = r;
    }

    //we showcase the greatest common divisor (n1)
    cout<< n1;
    //end main method
    return 0;
}
