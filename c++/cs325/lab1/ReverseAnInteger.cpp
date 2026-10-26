//Mateo Inigo Lahera Lab 1 cs325

//include iostream library/header file for c++
#include <iostream>
//use std namespace to save doing std:: with standard methods
using namespace std;

int main(){
    //set the number and its reverse
    int n;
    int rn = 0;

    //have the user input the value of n
    cout << "Input int: ";
    cin >> n;

    //divide n into digits
    while(n != 0){
        //rn = 0, so we find the last digit of n with n % 10
        rn = rn * 10 + n % 10;
        //we now go the next digit to find by (n / 10) which gets rid of the last digit from n
        n = n / 10;
        /*we repeat this until there are no more digits because when the last digit is read 
        itll be in decimal and truncated to 0 ending the while loop*/
    }

    //output the reverese n
    cout << rn <<endl;
    //return 0 for the int method
    return 0;
}