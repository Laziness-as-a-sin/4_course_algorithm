#include <iostream>
#include <fstream>
#include "string"
using namespace std;
// 97
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    string str, str1;
    in >> str >> str1;
    bool arrCheck[26];
    for(int i = 0; i < 26; i++) arrCheck[i] = true;

    for(int i = 0; i < str1.length(); i++){
        int nInt = (int) str1[i];
        arrCheck[nInt - 97] = !arrCheck[nInt - 97];
        cout << arrCheck[nInt - 97] << endl;
    }
    for(int i = 0; i < str.length(); i++){
        if(arrCheck[(int) str[i] - 97])
            str[i] = '.';
    }
    out << str;
    return 0;
}
