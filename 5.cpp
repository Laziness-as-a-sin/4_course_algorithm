#include <fstream>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{

    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    double r, R;
    infile >> r >> R;
    cout << r << " " << R << endl;
    double answer = M_PI*R*r;
    cout << fixed;

    cout.precision(8);
    cout << answer << endl;

    outfile << fixed;
    outfile.precision(8);
    outfile << answer;
    return 0;
}
