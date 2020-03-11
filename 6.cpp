#include <fstream>
#include <math.h>
#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int number, n;
    infile >> n;

    cout << n << endl;
    string answer = "";
    for(int i = 0; i < pow(2, n); i++) {
        number = i;
        for (int k = 0; k < n; k++) {
            answer = to_string(number % 2) + answer;
            number /= 2;
        }
        outfile << answer << endl;
        answer = "";
    }

    return 0;
}
