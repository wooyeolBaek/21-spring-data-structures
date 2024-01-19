//사칙연산
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void){
    cout << "8 + 3 = " << 8 + 3 << "\n";
    cout << "8 - 3 = " << 8 - 3 << "\n";
    cout << "8 * 3 = " << 8 * 3 << "\n";
    cout << "8 / 3 = " << 8 / 3 << "\n";
    cout << "8 % 3 = " << 8 % 3 << "\n"; // "\n" is bit faster than endl; 

    //step2 ++, -- 연산자

    int eight = 8;
    cout << "8++ = " << eight++ << " " << eight << "\n";
    cout << "++8 = " << ++eight << " " << eight << "\n";
    cout << "8-- = " << eight-- << " " << eight << "\n";
    cout << "--8 = " << --eight << " " << eight << "\n";

    //step3 +=, -= 연산자
    eight = 8;
    eight += 6; // eight = eight + 6;
    cout << "eight += 6 is " << eight << "\n";
    eight -= 6; // eight = eight -6
    cout << "eight =+ 6 is " << eight << "\n";

    //step4 연산의 순서: */가 먼저, 그 다음이 + - 
    cout << "1 + 2 - 3 * 4 = " << 1 + 2 - 3 * 4 << "\n";
    cout << "(1 + 2 - 3) * 4 = " << (1 + 2 - 3) * 4 << "\n";

    //step5 Typecast
    cout << "10 / 11 = " << 10 / 11 << "\n";
    cout << "10 / 11 = " << (float)10 / 11 << "\n";

    return 0;
}