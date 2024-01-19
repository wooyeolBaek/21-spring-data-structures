#include "EvalMathEq.hpp"
#include <iostream>
#include <string>

int main(){
    //계산기 테스트
    /*
    std::cout << "수식 입력 (postfix) : \n"; //수식 키보드 입력, 후위수식이라고 명시,postfix
    double res = calcPostfixExpr();
    std::cout << "계산 결과 = " << res << "\n"; 
    std::string input = "30 20 100 + *"; //input값에 이거 넣기, 항 사이는 공백으로 띄우는게 좋음 
    std::cout << " 미리입력된 수식 (postfix) : " << input << "\n";
    res = calcPostfixExpr(input);
    std::cout << "계산 결과 = " << res << "\n";
    */

    /*
    //수식 테스트
    std::cout << "수식 입력 (infix) : \n"; //수식 키보드 입력, 후위수식이라고 명시,postfix
    std::string res2 = infix2Postfix();
    std::cout << "변화 결과 = " << res2 << "\n"; 
    std::string input2 = "30 + 20 * 100 "; //input값에 이거 넣기, 항 사이는 공백으로 띄우는게 좋음 
    std::cout << " 미리입력된 수식 (infix) : " << input2 << "\n";
    res2 = infix2Postfix(input2);
    std::cout << "계산 결과 = " << res2 << "\n";
    */

    //계산기 + 수식 변환기를 합치기
    std::string input3 = "30 + 20 * 100";
    std::cout << " 미리입력된 수식 (infix) : " << input3 << "\n";
    std::string res3 = infix2Postfix(input3);
    std::cout << "변환 결과 = " << res3 << "\n";
    double res4 = calcPostfixExpr(res3);
    std::cout << "수식 계산 결과" << res4 << "\n";

    
    return 0;
}