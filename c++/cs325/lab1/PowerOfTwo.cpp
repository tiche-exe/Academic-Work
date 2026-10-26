//Mateo Inigo Lahera Lab 1 cs325

//include iostream library/header file for c++
#include <iostream>
//use std namespace to save doing std:: with standard methods
using namespace std;

int main(){
    //we ask for user input
    int k;
    cout << "Input an positive int: ";
    cin >> k;

    //we divide by 2 constantly until the result is 0, if it is then its a power of 2, if not it isnt

    //set a base case for 0 since it isnt a power of 2
    if (k == 0){
        cout << "false";
        //end main method
        return 0;
    }

    //while loop to check if it is divisble by 2 and never gives decimals (if we get 1 then we divided 2/2 which is the end of division)
    while (k > 1 && k % 2 == 0){
        //loop to divide by 2 until we reach 1, meaning it is a power of 2
        k = k / 2;
    }

    //if k == 1, that means that the last division was 2/2 so all divisions were square so it is a power of 2
    if (k == 1){
        cout <<"true";
    }
    else{// if k != 1 then in any of the divisions the result wasnt divisble by 2 so it cant be a power of 2
        cout <<"false";
    }
    //end main method
    return 0;
}