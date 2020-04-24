#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int x1, x2, y1, y2;
    infile >> x1 >> y1 >> x2 >> y2;

    if((x1 - x2) * (x1 - x2) == (y1 - y2) * (y1 - y2)) {
        if (abs(x1 - x2) > 1)
            if (x2 > x1 && y2 > y1)
                outfile << x1 + 1 << " " << y1 + 1;
            else if (x2 > x1 && y2 < y1)
                outfile << x1 + 1 << " " << y1 - 1;
            else if (x2 < x1 && y2 > y1)
                outfile << x1 - 1 << " " << y1 + 1;
            else
                outfile << x1 - 1 << " " << y1 - 1;
        else {
            outfile << 0;
        }
        return 0;
    }


    for(int x0 = 1; x0 < 9; ++x0)
        for(int y0 = 1; y0 < 9; ++y0)
            if((x1 - x0) * (x1 - x0) == (y1 - y0) * (y1 - y0) && x1 != x0 && y1 != y0)
                if((x2 - x0) * (x2 - x0) == (y2 - y0) * (y2 - y0) && x2 != x0 && y2 != y0){
                    outfile << x0 << " " << y0;
                    return 0;
                }

    outfile << 0;
    return 0;
}
