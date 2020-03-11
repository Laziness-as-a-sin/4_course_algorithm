#include <fstream>
#include <math.h>
#include <iostream>
#include <bitset>
#include <string>
#include <map>
#include <vector>

using namespace std;

int fMax(vector <int> arr, int first_index, int second_index) {

    if(first_index < 0)
        first_index = 0;
    if(second_index >= arr.size() && second_index > -1)
        second_index = arr.size() - 1;

    if(second_index < first_index)
        return -1;

    int max = arr[first_index];
    int maxInd = first_index;
    for(int i = first_index; i <= second_index; i++)
        if(arr[i] > max){
            max = arr[i];
            maxInd = i;
        }

    return maxInd;
}

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    int N, d;
    infile >> N >> d;
    vector <int> arr(N);

    for(int i = 0; i < N; i++)
        infile >> arr[i];

    int maxInd = fMax(arr, 0 ,N-1);
    int max = arr[maxInd];

    int lin = 0, lout = 0, rin = 0, rout = 0;

    if(fMax(arr, 0, maxInd-d) > -1)
        lout = arr[fMax(arr, 0, maxInd-d)];

    if(fMax(arr, maxInd-d+1, maxInd-1) > -1)
        lin = arr[fMax(arr, maxInd-d+1, maxInd-1)];

    if(fMax(arr, maxInd+1, maxInd+d-1) > -1)
        rin = arr[fMax(arr, maxInd+1, maxInd+d-1)];

    if(fMax(arr, maxInd+d, N-1) > -1)
        rout = arr[fMax(arr, maxInd+d, N-1)];

//    cout << lout << " " << lin << " " << max << " " << rin << " " << rout;

    int answer1, answer2;
    answer1 = lin + rin;
    if(rout >= lout)
        answer2 = max + rout;
    else
        answer2 = max + lout;

    if(answer2 >= answer1 && answer2 != max)
        outfile << answer2;
    else{
        answer1 = 0;
        int lindex, rindex;
        if(maxInd - d + 1 >= 0)
            lindex = maxInd - d + 1;
        else
            lindex = 0;

        if(maxInd + d - 1 >= N)
            rindex = N - 1;
        else
            rindex = maxInd + d - 1;

        for(int i = lindex; i < maxInd; i++){
            if(i + d < N)
                if(answer1 < arr[i] + arr[fMax(arr, i + d, rindex)])
                    answer1 = arr[i] + arr[fMax(arr, i + d, rindex)];
        }

        if(answer2 >= answer1 && answer2 != max)
            outfile << answer2;
        else
            outfile << answer1;
    }
    return 0;
}
