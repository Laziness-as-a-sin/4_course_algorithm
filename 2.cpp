#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    in >> N;

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                out << (i + j + k)%N + 1;
                if(j == N - 1)
                    out << "\n";
                else
                    out << " ";
            }
    return 0;
}
