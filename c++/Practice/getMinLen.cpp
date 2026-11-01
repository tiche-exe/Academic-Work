#include <iostream>
#include <string>
using namespace std;

//delete "AB"/"BB" from seq containing only A's & B's
//return length
int getMinLen(string seq) {

    cout << "\"" << seq << "\"" << endl; //quotes so empty string is visible

    size_t index = seq.find("AB");
    if (index == string::npos) { //no AB, try BB
        index = seq.find("BB");
    }

    //recursion base case
    if (index == string::npos) {
        return seq.length();
    }

    //remove pair & recurse
    seq.erase(index, 2);
    return getMinLen(seq);
}

int main() {
    //set test cases
    cout << "Length: " << getMinLen("BABB") << endl << endl;
    cout << "Length: " << getMinLen("ABBA") << endl << endl;
    cout << "Length: " << getMinLen("AAAA") << endl << endl;
    cout << "Length: " << getMinLen("BBBB") << endl << endl;
    cout << "Length: " << getMinLen("") << endl;
    return 0;
}
