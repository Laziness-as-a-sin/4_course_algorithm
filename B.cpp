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
    int n, n1;
    infile >> n;
    int arr[n+1];
    cout << n << endl;

    arr[0] = 0;
    for(int i = 1; i < n+1; i++) {
        infile >> arr[i];
        arr[i] += arr[i-1];
    }

    infile >> n1;
    for(int i =0; i < n1; i++){
        int l, r;
        infile >> l >> r;
        outfile << arr[r] - arr[l-1] << " ";
    }
    return 0;
}
