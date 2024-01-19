#include <fstream>
#include <iostream>
#include <string>
#include "ArrayStackTemplate.hpp"

//괄호닫기 프로그램
bool CheckMatching(std::string filename){ // std::string filename 대신 const char* filename 으로 대체 가능
    std::ifstream is(filename);//파일의 스트림 불러오기
    if(!is.is_open()){ //열려있는지 검사
        error("Error : 파일이 제대로 열리지 않았습니다. \n");
    }
    int nLine = 1; //문서가 제대로 읽혔는지 확인, 줄 세기
    int nChar = 0; //문서가 제대로 읽혔는지 확인, 글자 수 세기
    ArrayStack<char> stack; //검사할 것은 char이므로 <char>
    char ch; //한 글자를 받아옴, 한 글자씩 전달
    while(is.get(ch)){ // 파일 스트림이 끝나지 않는 동안에 
        if(ch == '\n'){nLine++;} //ch 문자가 나오면, 한 줄 더 있다고 판단
        nChar++; // 한 글자 카운트해주기
        if(ch == '[' || ch == '{' || ch == '('){
            stack.push(ch);
        }
        else if(ch == ']' || ch == '}' || ch == ')'){
            char prev = stack.pop();
            if((ch == ']' && prev != '[')
            || (ch != '}' && prev != '{')
            || (ch == ')' && prev != '(')){break;}
            stack.push(ch);
        }
    }
    is.close();
    std::cout << filename << "파일 검사결과 : \n";

    if(!stack.isEmpty()){
        std::cout << "Error : 문제발견! (총 라인 수 : " << nLine << ", 총 문자 수 : " << nChar << ") \n";
    }
    else{
        std::cout << "OK : 괄호닫기 정상! (총 라인 수 : " << nLine << ", 총 문자 수 : " << nChar << ") \n";
    }
    return stack.isEmpty();
}

int main(){
    CheckMatching("./ArrayStack.h"); //파일 열기
    CheckMatching("./main_CheckBraket.cpp"); //파일 열기
    return 0;
}