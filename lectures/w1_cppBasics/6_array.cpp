//Array
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void){
    //step1: 1D array
    int myNumbers[5];
    int yourNumbers[5] = {3, 4, 7, 6, 1};
    cout << "Your Number 1: " << yourNumbers[0] << endl;

    //step2: 2D array
    int yourNumbers2d[2][5] = {{3,4,7,6,1},
                                {13,14,17,16,11}}; 
    cout << "Your Number 2D 0, 2 : " << yourNumbers2d[0][2] << endl;

    int yourNumbers2d2[][5] = {{3,4,7,6,1},
                                {13,14,17,16,11}};
    cout << "Your Number 2D 0, 2 : " << yourNumbers2d2[0][2] << endl;

    int Array2D[3][5] = {0};
    cout << "Array2D 2,4 : " << Array2D[2][4] << endl;
}