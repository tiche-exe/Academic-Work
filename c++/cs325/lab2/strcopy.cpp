//Mateo Inigo Lahera Lab 2 cs325

//include iostream library/header file for c++
#include <iostream>
//std::string isnt used for lab2
using namespace std;


/* copy function: copies src (including '\0') into dest if dest is big enough
   src: string source (where it is copied from)
   dest: string destination (where it is copied into)
   returns dest or NULL if dest too small*/
char* copy(char* dest, const char* src){
    //we set the source's length
    int srcLength = 0;
    //we count the characters in src until the end ('\0')
    while(src[srcLength] != '\0'){
        srcLength++;
    }
    
    //we set the destination's length
    int destLength = 0;
    //we count the characters in dest until the end ('\0')
    while(dest[destLength] != '\0'){
        destLength++;
    }

    //if destLength < srcLength we return NULL
    if (destLength < srcLength){
        return NULL;
    }

    //we copy each char from src to dest
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    //we add '\0' because while loop skips it
    dest[i] = '\0';

    //we return dest to see if was copied correctly from src
    return dest;
}

//test case for: 'string' (dest has enough chars)
void copy_test_case_1(){
    char dest[10] = "ccccccccc";
    const char* src = "string";
    copy(dest, src);
    //showcase both src and dest to see if it worked
    cout<< "src: " << src <<endl;
    cout<< "dest: " << dest <<endl;
}
//test case for: 'string\0' (dest has enough chars)
void copy_test_case_2(){
    char dest[10] = "ccccccccc";
    const char* src = "string\0";
    copy(dest, src);
    //showcase both src and dest to see if it worked
    cout<< "src: " << src <<endl;
    cout<< "dest: " << dest <<endl;
}
//test case for: 'strings123\0string\0' (dest doesn't have enough chars)
void copy_test_case_3(){
    char dest[4] = "ccc"; //should return 'ccc' as the NULL returns nothing added to the original string
    const char* src = "strings123\0string\0";
    copy(dest, src);
    //showcase both src and dest to see if it worked
    cout<< "src: " << src <<endl;
    cout<< "dest: " << dest <<endl;
}


int main(){
    //call the testcases to run
    copy_test_case_1();
    copy_test_case_2();
    copy_test_case_3();

    //return 0 for the int function
    return 0;
}
