#include <fstream>
#include <math.h>
#include <iostream>
#include <bitset>
#include <string>
#include <map>

using namespace std;

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int n, number;
    infile >> n;
    map<int, int> mp;
    int arr[2001];
    for(int i = 0; i < 2001; i++)
        arr[i] = 0;
    cout << n << endl;
    
    for(int i = 0; i < n; i++) {
        infile >> number;
        arr[number+1000] += 1;
    }

    for(int i = 0; i < 2001; i++)
        if(arr[i] > 0)
            outfile << i-1000 << " " << arr[i] << endl;

    return 0;
}
