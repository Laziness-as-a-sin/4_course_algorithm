#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <iterator>
#include <queue>
using namespace std;

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int N, M;
    priority_queue<int> arr;
    infile >> N >> M;

    int temp;
    for(int i = 0; i < N; ++i){
        infile >> temp;
        arr.push(temp);
    }

    for(int i = 0; i < M; ++i){
        temp = arr.top()/10;
        arr.pop();
        arr.push(temp);
    }

    unsigned __int64 sum = 0;
    for(int i = 0; i < N; ++i){
        sum += arr.top();
        arr.pop();
    }

//    outfile << 100000 << " " << 100000 << endl;
//    for(int i = 0; i < 100000; ++i)
//        outfile << rand << " ";

    outfile << sum;
    return 0;
}
