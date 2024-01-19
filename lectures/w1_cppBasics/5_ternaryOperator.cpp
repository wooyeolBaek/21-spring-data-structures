//삼항연산자
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void){
    //"변수 = 조건 ? 참값 : 거짓값" 형태
    int largerNum = (10>5) ? 10 : 5;
    cout << "Larger Number 10 and 5 is : " << largerNum << endl;
}