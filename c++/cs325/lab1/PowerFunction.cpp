//Mateo Inigo Lahera Lab 1 cs325

//include iostream library/header file for c++
#include <iostream>
//use std namespace to save doing std:: with standard methods
using namespace std;

//set a power method to call in main to do the power function
int PowFunc(int n, int p){
    //set the solution for n^p (has to be 1 because it needs to multiply with n and cant be 0)
    int sol = 1;

    /*to make it O(logn), we jump powers from 2 on 2 or 3 on 3, or 5 on 5 
    (2 on 2 is better since its the minmum power where the answer isnt 0 or n)*/

    //set a while loop to multiply n, p times
    while(p > 0){
        //if p is odd, then we multiply the remaining x to the solution (max 1 remaining); 
        for(int i = 0; i < p % 2; i++){
            sol = sol * n;
        }
        //we multiply n * n (n^2)
        n = n * n;
        //we halve p to make O(logn) as it makes the answers grow exponentially
        p = p / 2;
    }
    //return the solution
    return sol;
}

int main(){
    //we set the variable and its power from the users input
    int n;
    int p;
    cout<< "Input int: ";
    cin>> n;
    cout<< "Input power of int: ";
    cin>> p;

    //call the power function method for int n and its power p
    cout<< PowFunc(n, p);
    //end main method
    return 0;
}