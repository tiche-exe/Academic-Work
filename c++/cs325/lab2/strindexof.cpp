//Mateo Inigo Lahera Lab 2 cs325

//include iostream library/header file for c++
#include <iostream>
//std::string isnt used for lab2
using namespace std;


/* indexOf function: finds position of first c in str
   c: the character to look for
   str: the string to search
   returns the position of the first c (starting at 0) or -1 if c not found*/
int indexOf(char c, const char* str){
    //we go through str until '\0'
    int i = 0;
    while(str[i] != '\0'){
        //if this char = c, return its position
        if (str[i] == c){
            return i;
        }
        i++;
    }
    //if char != c, return -1
    return -1;
}

//test case for: i in string (pos 3)
void indexOf_test_case_1(){
    const char* str = "string";
    cout<< "str: " << str <<endl;
    cout<< "indexOf 'i': " << indexOf('i', str) <<endl;
}
//test case for: a in string (return -1)
void indexOf_test_case_2(){
    const char* str = "string";
    cout<< "str: " << str <<endl;
    cout<< "indexOf 'a': " << indexOf('a', str) <<endl;
}
//test case for: p in pepperpots (first pos: 0)
void indexOf_test_case_3(){
    const char* str = "pepperpots";
    cout<< "str: " << str <<endl;
    cout<< "indexOf 'p': " << indexOf('p', str) <<endl;
}


int main(){
    //call the testcases to run
    indexOf_test_case_1();
    indexOf_test_case_2();
    indexOf_test_case_3();

    //return 0 for the int function
    return 0;
}