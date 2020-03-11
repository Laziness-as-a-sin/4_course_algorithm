#include <iostream>
#include <fstream>
#include "string"
using namespace std;

void swap(int array[], int first_index, int second_index) {
    int temp = array[ first_index ];
    array[ first_index ] = array[ second_index ];
    array[ second_index ] = temp;
}

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    string answer = "";
    int N, sCounter;
    infile >> N;
    int arr[N+1];
    sCounter = 0;
    for(int i = 1; i < N+1; i++){
        infile >> arr[i];
        if(arr[i] != i)
            sCounter += 2;
    }

    outfile << sCounter;
    
    for(int i = 1; i < N+1; i++)
        if(arr[i] != i){
            outfile << "\n-" << arr[i] << " " << i;

            while(arr[i] != i){
                outfile << "\n-" << arr[arr[i]] << " " << arr[i] << "\n" << arr[i] << " " << arr[i];
                swap(arr, i, arr[i]);
            }
            outfile << "\n" << arr[i] <<  " " << arr[i];
        }

    return 0;
}
