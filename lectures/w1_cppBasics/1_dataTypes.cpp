#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std; // std namespace를 기본으로 사용

//기본데이터
int main(){
    cout << "Hello World" << endl; 
    const double PI = 3.1415926535; //const가 붙으면 변수의 값을 바꿀 수 없음. 이런 경우 변수명으로 보통 대문자로 씀
    char myGrade = 'A'; //문자
    bool isRain = false; //boolean 
    int myRoomNo = 708; // 정수
    float pi = 3.14; // 실수(단정밀도)
    double e = 2.71828182846; // 실수(배정밀도)
    cout << "e= " << e << endl;

    cout << "Size of int " << sizeof(myRoomNo) << "\n";
    cout << "Size of char " << sizeof(myGrade) << "\n";
    cout << "Size of bool " << sizeof(isRain) << "\n";
    cout << "Size of float " << sizeof(pi) << "\n";
    cout << "Size of double " << sizeof(e) << "\n";

    int TESTINT = 2147483648;
    cout << "largest int is " << INT_MAX << endl;
    cout << "latgest int overflow " << TESTINT << endl;

    // short int : 최하 16비트 이상의 integer
    // long int : 최하 32비트 이상의 integer
    // long long int : 최하 64비트 이상의 integer -> 컴파일러와 시스템에 따라서 달라짐
    // unsigned (long/short) int : signed version과 같은 메모리 크기, 음수가 없음
    // long double : (일반적으로) double 과 다르지 않음

    return 0;
}
