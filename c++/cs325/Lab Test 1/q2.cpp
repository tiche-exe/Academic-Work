//Lab Test 1 Revision:
#include <iostream>
using namespace std;

unsigned int length(const char* str){
    unsigned int strlength = 0;
    
    while (*str != '\0'){
        strlength++;
        str++;
    }
    return strlength;
}

int lastIndexOf(const char* str, char c){
    int strlength = length(str);
    int lastIndex = strlength;

    while(str[lastIndex] != c){
        if(str[lastIndex] == c){
            return lastIndex;
        }
        lastIndex--;
    }
    if (lastIndex < 0){
        lastIndex = -1;
    }
    return lastIndex;
}

//test cases:
void test_case_1(){
    const char* str = "abbaba";
    char c = 'b';
    cout<< "str: " << str <<endl;
    cout<< "indexOf 'b': " << lastIndexOf(str, c);
}
void test_case_2(){
    const char* str = "orange";
    char c = 't';
    cout<< "str: " << str <<endl;
    cout<< "indexOf 't': " << lastIndexOf(str, c) <<endl;
}

int main(){
    //call the testcases to run
    cout << "Testcase 1:" <<endl;
    test_case_1();
    cout << "\nTestcase 2:" <<endl;
    test_case_2();
    
    return 0;
}