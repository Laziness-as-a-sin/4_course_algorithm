#include <fstream>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{

    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int r, l;
    infile >> r >> l;
    double answer = 2*M_PI*r*r+M_PI*r*l/2-M_PI*r*r/2;


    outfile << fixed;
    outfile.precision(8);
    outfile << answer;
    return 0;
}
