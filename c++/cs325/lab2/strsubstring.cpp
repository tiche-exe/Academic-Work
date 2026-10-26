//Mateo Inigo Lahera Lab 2 cs325

//include iostream library/header file for c++
#include <iostream>
//std::string isnt used for lab2
using namespace std;


/* substring function: makes a new string from index i up to index j - 1 of str
   i: the index where the substring starts
   j: the index where the substring ends (the char at j is not included)
   str: the original string (it is not changed)
   returns a new string (use delete[] on it), or NULL if i or j is not valid*/
char* substring(int i, int j, const char* str){
    //we count the characters in str until the end ('\0')
    int strLength = 0;
    while(str[strLength] != '\0'){
        strLength++;
    }

    //we set cases for when NULL has to be returned
    if (i < 0 || j > strLength || i > j){//i can't be negative, j can't go past the end, and i can't go after j
        return NULL;
    }

    //we make a new string for the chars from i to j - 1 (+1 since '\0' is 1 extra char)
    char* result = new char[j - i + 1];

    //we copy the chars, k - i makes them start at the beginning of result
    for (int k = i; k < j; k++){
        result[k - i] = str[k];
    }
    //the loop stops before '\0', so we add it ourselves
    result[j - i] = '\0';

    //we return the new string
    return result;
}

//test case for: substring(0, 3) of string (should print str)
void substring_test_case_1(){
    const char* str = "string";
    char* result = substring(0, 3, str);
    cout<< "str: " << str <<endl;
    cout<< "substring(0, 3): " << result <<endl;
    //we free the memory made with new[]
    delete[] result;
}
//test case for: substring(2, 6) of string, up to the end (should print ring)
void substring_test_case_2(){
    const char* str = "string";
    char* result = substring(2, 6, str);
    cout<< "str: " << str <<endl;
    cout<< "substring(2, 6): " << result <<endl;
    delete[] result;
}
//test case for: substring(2, 10) of string, j too big (should return NULL)
void substring_test_case_3(){
    const char* str = "string";
    char* result = substring(2, 10, str);
    cout<< "str: " << str <<endl;
    //we can't print a NULL pointer with cout, so we check it first
    if (result == NULL){
        cout<< "substring(2, 10): NULL" <<endl;
    }
    else{
        cout<< "substring(2, 10): " << result <<endl;
        delete[] result;
    }
}


int main(){
    //call the testcases to run
    substring_test_case_1();
    substring_test_case_2();
    substring_test_case_3();
 
    //return 0 for the int function
    return 0;
}