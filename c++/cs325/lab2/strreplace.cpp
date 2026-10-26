//Mateo Inigo Lahera Lab 2 cs325

//include iostream library/header file for c++
#include <iostream>
//std::string isnt used for lab2
using namespace std;


/* replace function: makes a new string where every c in str is changed to p
   c: the character to replace
   p: the character to replace c
   str: the original string (isnt changed)
   returns a new string (use delete[] on it), a plain copy of str if c is not found*/
char* replace(char c, char p, const char* str){
    //we count the characters in str until the end ('\0')
    int strLength = 0;
    while(str[strLength] != '\0'){
        strLength++;
    }

    //we make a new string the same size as str (+1 for the '\0')
    char* result = new char[strLength + 1];

    //we go through str and copy each char, swapping c for p
    for (int i = 0; i < strLength; i++){
        if (str[i] == c){
            result[i] = p;
        }
        else{
            result[i] = str[i];
        }
    }
    //the loop stops before '\0', so we add it ourselves
    result[strLength] = '\0';

    //we return the new string
    return result;
}

//test case for: replace i with x in string (result should print strxng)
void replace_test_case_1(){
    const char* str = "string";
    char* result = replace('i', 'x', str);
    cout<< "str: " << str <<endl;
    cout<< "replace 'i' with 'x'" <<endl;
    cout<< "result: " << result <<endl;
    //we free the memory made with new[]
    delete[] result;
}
//test case for: c not found, replace z with x in string (result should print string)
void replace_test_case_2(){
    const char* str = "string";
    char* result = replace('z', 'x', str);
    cout<< "str: " << str <<endl;
    cout<< "replace 'z' with 'x'" <<endl;
    cout<< "result: " << result <<endl;
    delete[] result;
}
//test case for: c found several times, replace t with T in tattoo (result should print TaTToo)
void replace_test_case_3(){
    const char* str = "pepperpots";
    char* result = replace('p', 'P', str);
    cout<< "str: " << str <<endl;
    cout<< "replace 'p' with 'P'" <<endl;
    cout<< "result: " << result <<endl;
    delete[] result;
}


int main(){
    //call the testcases to run
    replace_test_case_1();
    replace_test_case_2();
    replace_test_case_3();

    //return 0 for the int function
    return 0;
}