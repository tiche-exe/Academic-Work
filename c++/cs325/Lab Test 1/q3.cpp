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

int PowFunc(int n, int p){
    int sol = 1;
    
    while(p > 0){
        for(int i = 0; i < p % 2; i++){
            sol = sol * n;
        }
        n = n * n;
        p = p / 2;
    }
    return sol;
}

int binaryToDecimal(const char* binary){
    int strlength = length(binary);
    int counter = 0;
    int result = 0;

    for(int i = strlength - 1; i >= 0; i--){
        if(binary[i] == '1'){
                result += PowFunc(2, counter);
        }
        counter++;
    }
    return result; 
}


//test cases:
void test_case_1(){
    const char* bin = "101";
    cout<< "binary: " << bin <<endl;
    cout<< binaryToDecimal(bin);
}
void test_case_2(){
    const char* bin = "1101";
    cout<< "binary: " << bin <<endl;
    cout<< binaryToDecimal(bin);
}

int main(){
    //call the testcases to run
    cout << "Testcase 1:" <<endl;
    test_case_1();
    cout << "\nTestcase 2:" <<endl;
    test_case_2();
    
    return 0;
}