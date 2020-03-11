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
    int n;
    infile >> n;
    int arr[n];
    cout << n << endl;

    for(int i = 0; i < n; i++) {
        infile >> arr[i];
        cout << arr[i] << endl;
    }

    bool check = false;
    for(int i = 0; i < n-2; i++){
        if(arr[i+1] - arr[i] < 7 && arr[i+2] - arr[i] < 7)
            check = true;
    }
    if(check)
        outfile << "BAD" << endl;
    else
        outfile << "GOOD" << endl;
    return 0;
}
