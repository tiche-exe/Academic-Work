//Mateo Inigo Lahera Lab 2 cs325

//include iostream library/header file for c++
#include <iostream>
//std::string isnt used for lab2
using namespace std;


/* length function: counts chars in str (not including '\0')
   str: set of characters to measure set in test cases
   returns length of characters in string w/o counting '\0'*/
unsigned int length(const char* str){
    /*we set the unsigned count 
    to return the length of string*/
    unsigned int strlength = 0;
    
    /*we go through each value of the string 
    and count until the value '\0' is found so we return*/
    while (*str != '\0'){
        strlength++;
        str++;
    }
    //return the length of the string
    return strlength;
}

//test case for: string
void length_test_case_1(){
    const char* str = "string";
    cout<< "str: " << str <<endl;
    cout<< "length: " << length(str) <<endl;
}
//test case for: string\0
void length_test_case_2(){
    const char* str = "string\0";
    cout<< "str: " << str <<endl;
    cout<< "length: " << length(str) <<endl;
}
//test case for: strings123\0string\0
void length_test_case_3(){
    const char* str = "strings123\0string\0";
    cout<< "str: " << str <<endl;
    cout<< "length: " << length(str) <<endl;
}


int main(){
    //we tell the user the string checked for the testcases
    cout<< "We test the following cases: 1. string 2. string\\0 3. strings123\\0string\\0"<<endl; //have to put \\0 so it shows like \0 in the terminal
    //call the testcases to run
    length_test_case_1();
    length_test_case_2();
    length_test_case_3();

    //return 0 for the int function
    return 0;
}