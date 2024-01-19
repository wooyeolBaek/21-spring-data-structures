#include <fstream>
#include <iostream>
#include <string>
#include <stack>

inline int error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};

//괄호닫기 프로그램
bool CheckMatching(std::string filename){
    std::ifstream is(filename);
    if(!is.is_open()){
        error("Error : 파일이 제대로 열리지 않았습니다. \n");
    }
    int nLine = 1; //줄
    int nChar = 0; //글자
    std::stack<char> stack; 
    char ch; //한 글자를 받아옴
    while(is.get(ch)){
        if(ch == '\n'){nLine++;} 
        nChar++; 
        if(ch == '[' || ch == '{' || ch == '('){
            stack.push(ch);
        }
        else if(ch == ']' || ch == '}' || ch == ')'){
            if(stack.empty()){stack.push(ch);}
            char prev = stack.top();
            if((ch == ']' && prev == '[')
                || (ch == '}' && prev == '{')
                || (ch == ')' && prev == '(')){
                stack.pop();
            }
            else{
                stack.push(ch);
            }            
        }
    }
    is.close();
    std::cout << filename << " 파일 검사결과 : \n";

    if(!stack.empty()){
        std::cout << "Error : 문제발견! (총 라인 수 : " << nLine << ", 총 문자 수 : " << nChar << ") \n";
        std::cout << "오류가 발생한 괄호 : " << stack.top() << "\n";
    }
    else{
        std::cout << "OK : 괄호닫기 정상! (총 라인 수 : " << nLine << ", 총 문자 수 : " << nChar << ") \n";
    }
    return stack.empty();
}

int main(){
    CheckMatching("./test1.h");
    CheckMatching("./test2.h");
    CheckMatching("./test3.h"); 
    CheckMatching("./test4.h"); 
    
    
    return 0;
}