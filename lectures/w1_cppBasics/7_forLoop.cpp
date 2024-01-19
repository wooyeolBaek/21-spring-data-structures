//for loop
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main(void){

    //step1: 1D array
    int myNumbers[5];
    int yourNumbers[5] = {3,4,7,6,1};
    cout << "Your Number 1 : " << yourNumbers[0] << endl;

    //step2: 2D array
    int yourNumbers2d[2][5]={{3,4,7,6,1},
                            {13,14,17,16,11}};
    for(int i = 1; i <= 10; i++){
        cout << i << endl;
    }
    for(int j=0; j<2; j++){
        for(int k = 0; k<5; k++){ //nested loop
            cout << yourNumbers2d[j][k] << " ";
        }
        cout << "\n";
    }
    return 0;
}