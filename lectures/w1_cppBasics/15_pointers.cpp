//pointer와 references
//자료구조에서 가장 중요한 문법
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int change_val(int* p){ // function for 2nd step, 포인터 *p로 number를 조회
    *p = 3;
    return 0;
}

int change_val2(int& p){ // function for 3rd step, 레퍼런스 &p로 number를 조회
    p = 3;
    return 0;
}

//function for 4th step, reference를 반환
//int return_ref1(int& a){ return a; } //이 형태는 작동이 안됨
int& return_ref2(int& a){ return a;} //이건 작동

int main(){
    int myAge = 100;
    char myGrade = 'A';

    cout << "Size of int" << sizeof(myAge) << "\n";
}