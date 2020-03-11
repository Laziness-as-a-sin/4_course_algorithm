#include <fstream>

#include <iostream>

using namespace std;



int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int a, b;
    infile >> a >> b;
    int t = 24*60 - (a*60+b);
    a = t/60;
    b = t%60;
    outfile << a << " " << b;
    return 0;
}
