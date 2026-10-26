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
    //we set a copy of n to compare since we will change n to reverse it
    int og = n; 

    //if n is negative it can never be a palindrome so it will always be false
    if (n < 0){
        cout << "false";
        //return 0 for the int method
        return 0;
    }

    //divide n into digits
    while(n > 0){
        //rn = 0, so we find the last digit of n with n % 10
        rn = rn * 10 + n % 10;
        //we now go the next digit to find by n / 10 and getting rid of the last digit from n % 10
        n = n / 10;
        /*we repeat this until there are no more digits because when the last digit is read 
        itll be in decimal and truncated to 0 ending the while loop*/
    }

    //we compare the original n and its reverse to see if it is a palindrome or not
    if (og == rn){
        cout << "true";
    }
    else{
        cout << "false";
    }
    //return 0 for the int method
    return 0;
}