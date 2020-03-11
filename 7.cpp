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
    int a, b;
    infile >> a >> b;
    int ans = b - a;

    if(ans == 0)
        if(a%2 == 1)
            outfile << "1 -1 100";
        else
            outfile << "2 -1 100";
    else{
        if(ans%2 == 1)
            if(a%2 == 1)
                outfile << "2 -1 3 -2 1 -1 100";
            else
                outfile << "1 -1 3 -2 2 -1 100";

        if(ans%2 == 0)
            if(a%2 == 1)
                outfile << "2 -1 3 0 -2 1 -1 100";
            else
                outfile << "1 -1 3 0 -2 2 -1 100";
    }
    return 0;
}
