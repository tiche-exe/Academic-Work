//Lab Test 1 Revision:
#include <iostream>
using namespace std;

void invertSigns(int numbers[], int size){

    for(int i = 0; i < size; i++){
        int n = numbers[i];
        if(n != 0){
            n = ~n + 1;
        }
        else{
            n = 0;
        }
        cout<< n<< " ";
    }
}

//test cases:
void test_case_1(){
    int numbers[] = {-3,-2,2,-1};
    int size = 4;
    invertSigns(numbers, size);
}
void test_case_2(){
    int numbers[] = {-1,5,0,-9};
    int size = 4;
    invertSigns(numbers, size);
}

int main(){
    //call the testcases to run
    cout << "Testcase 1:" <<endl;
    test_case_1();
    cout << "\nTestcase 2:" <<endl;
    test_case_2();
    
    return 0;
}
