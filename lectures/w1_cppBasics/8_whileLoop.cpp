//While loop
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void){
    //step1: While loop
    int randNum = (rand()%20)+1; //실제로는 더 좋은 (pseudo) random number generator를 써야함
    while(randNum != 20){ 
        cout << randNum << " ";
        randNum = (rand() % 20) + 1;
    }
    cout << randNum << endl;

    //step2: while loop 를 for loop처럼 쓰기
    int idx = 0;
    while(idx<10){
        cout << idx << " ";
        idx++;
    }

    //step3: do-while loop
    randNum = (rand() % 20) + 1;
    do{
        cout << randNum << " ";
        randNum = (rand() % 20) + 1;
    }
    while(randNum != 20); //do를 먼저 실행함
    return 0;
}