#pragma once
#include "ArrayStackTemplate.hpp"
#include <string>
#include <sstream>
#include <iostream>//이런 수식에선 string 넘기는게 비효율적인 방법

//키보드로 입력받는 방식
double calcPostfixExpr(){ //파라미터 입력없는 경우 키보드에서 받음
    //Postfix 계산기
    char c; //한 글자씩 받는 캐릭터
    double val; // 변수(연산항)을 넣을 변수
    ArrayStack<double> st; //더블 변수를 넣을 스택 
    // 계산기는 계산항(변수)들을 넣는 스택이 필요하고 
    //변환기(후위수식을 중위수식으로 바꿔주는 변환기는 연산자를 넣을 스택이 필요)
    while(std::cin.get(c) && c != '\n'){ 
    //cin.get(c)는 키보드 입력에서 한글자 씩 불러옴 && 한 줄만 불러올 거라 개인문자?가 아닐 때
        if(c == '+' || c == '-' || c == '*' || c == '/'){
            double val2 = st.pop(); //먼저 빼는 것이 두 번쨰 항
            double val1 = st.pop(); //나중에 뺴는 것이 첫 번째 항
            switch(c){ // 네가지 경우 switch 
                case '+' : st.push(val1 + val2); break; //두개 더한거를 스택에 넣고 끝냄
                case '-' : st.push(val1 - val2); break;
                case '*' : st.push(val1 * val2); break;
                case '/' : st.push(val1 / val2); break;
            }
        }
        else if(c >= '0' && c <= '9'){ //만나는 글자를, 이게 가능한 이유는 아스키코드와 utf코드에서 0~9까지 붙어있음
            std::cin.unget(); //버퍼로 마지막에 가져온 것을 다시 집어 넣음, 예) 9를 받으면 9를 다시 집어 넣음
            std::cin >> val; //공백 전 까지의 값을 double로 받음
            st.push(val);
        }
    }
    return (st.pop()); //마지막에 나온 값을 꺼내서 리턴
}


//입력이 이미 방식, string으로 preassign 된 입력이 존재
double calcPostfixExpr(std::string str){ //원래는 표준입력(cin)을 사용했는데, 대신 stringstream을 사용
    std::istringstream iss(str); // input 스트링, 앞에 i가 붙으면 input
    char c; //한 글자씩 받는 캐릭터
    double val; // 변수(연산항)을 넣을 변수
    ArrayStack<double> st; //더블 변수를 넣을 스택 
    // 계산기는 계산항(변수)들을 넣는 스택이 필요하고 
    //변환기(후위수식을 중위수식으로 바꿔주는 변환기는 연산자를 넣을 스택이 필요)
    while(iss.get(c) && c != '\n'){ 
    //cin.get(c)는 키보드 입력에서 한글자 씩 불러옴 && 한 줄만 불러올 거라 개인문자?가 아닐 때
        if(c == '+' || c == '-' || c == '*' || c == '/'){
            double val2 = st.pop(); //먼저 빼는 것이 두 번쨰 항
            double val1 = st.pop(); //나중에 뺴는 것이 첫 번째 항
            switch(c){ // 네가지 경우 switch 
                case '+' : st.push(val1 + val2); break; //두개 더한거를 스택에 넣고 끝냄
                case '-' : st.push(val1 - val2); break;
                case '*' : st.push(val1 * val2); break;
                case '/' : st.push(val1 / val2); break;
            }
        }
        else if(c >= '0' && c <= '9'){ //만나는 글자를, 이게 가능한 이유는 아스키코드와 utf코드에서 0~9까지 붙어있음
            iss.unget(); //버퍼로 마지막에 가져온 것을 다시 집어 넣음, 예) 9를 받으면 9를 다시 집어 넣음
            iss >> val; //공백 전 까지의 값을 double로 받음
            st.push(val);
        }
    }
    return (st.pop()); //마지막에 나온 값을 꺼내서 리턴
}


//중위수식을 후위수식으로 바꾸기

inline int priority(char op){ //연산자의 우선순위 정하기
//inline 함수 : 어떤 함수를 불러오는 위치에 그 함수를 복사해줌 그래서 작동방식이 다름
//main에 inline안하고 이 함수 그냥 쓰게 되면, 이 함수를 호출해서 쓰게 됨 
//대신 inline을 붙히면 main의 그 위치에 함수를 그대로 복사해서 쓰게 됨, 속도는 빨라지고 용량은 커짐
    switch(op){
        case '(' : case ')' : return 0; //return 숫자; 에서 숫자가 높을 수록 우선순위가 높음
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1; // 위의 케이스가 모두 아닌 경우 -1 반환, 에러 
}

// infix 수식을 postfix로 바꾸는 변환기
std::string infix2Postfix(){ //파라미터 입력이 없는 경우는 키보드에서 받음
// 두개를 비교하는 작업 
    char c; //읽어오는 글자
    char op; //스택에서 꺼내오는 글자 
    double val;
    std::ostringstream oss; // 스트림을 쓸껀데 이번엔 input스트림이 아니라 output스트림 사용, 즉 출력하듯이 사용, o가 앞에 붙으면 out
    ArrayStack<char> st; //스택 생성 
    while(std::cin.get(c) && c != '\n'){ //숫자를 먼저 검사해야하기 때문에 아까랑 순서는 반대 
        if((c >= '0' && c <= '9')){
            std::cin.unget();
            std::cin >> val; //공백 전까지의 값을 double로 받음
            oss << val << " ";
        }
        else if(c == '('){ //'와 "도 작동하는 방식이 다름 나중에 찾아보기
            st.push(c);
        }
        else if(c == ')'){
            while(!st.isEmpty()){
                op = st.pop();
                if( op == '(') break;
                else oss << op << " ";
            }
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/'){
            while(!st.isEmpty()){
                op = st.peek();
                if(priority(c) <= priority(op)){//priority검사해서 높은 애들은 다 출력해줌
                    oss << op << " ";
                    st.pop();
                }
                else break;
            }
            st.push(c); //새 오퍼레이터를 스택의 맨 위에 집어 넣음
        }
    }
    while(!st.isEmpty()){//남아있는 오퍼레이터 다 pop으로 뽑기
        op = st.peek();
        oss << st.pop() << " ";
    }
    return oss.str();//str() 스트링으로 반환하는 함수, oss를 str으로 바꿔줌
}


//이번엔 input을 받는 방식
// infix 수식을 postfix로 바꾸는 변환기
std::string infix2Postfix(std::string istr){ //파라미터 입력이 없는 경우는 키보드에서 받음
// 두개를 비교하는 작업 
    char c; //읽어오는 글자
    char op; //스택에서 꺼내오는 글자 
    double val;
    std::ostringstream oss; // 스트림을 쓸껀데 이번엔 input스트림이 아니라 output스트림 사용, 즉 출력하듯이 사용, o가 앞에 붙으면 out
    std::istringstream iss(istr); //얘는 string하나 더 써줘야함, 받은 istr 스트링을 stream 형태로 만들어줌 
    // 그래서 iss는 입력받은 스트링(istr)의 스트림
    ArrayStack<char> st; //스택 생성 
    while(iss.get(c) && c != '\n'){ //숫자를 먼저 검사해야하기 때문에 아까랑 순서는 반대 
        if((c >= '0' && c <= '9')){
            iss.unget();
            iss >> val; //공백 전까지의 값을 double로 받음
            oss << val << " ";
        }
        else if(c == '('){ //'와 "도 작동하는 방식이 다름 나중에 찾아보기
            st.push(c);
        }
        else if(c == ')'){
            while(!st.isEmpty()){
                op = st.pop();
                if( op == '(') break;
                else oss << op << " ";
            }
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/'){
            while(!st.isEmpty()){
                op = st.peek();
                if(priority(c) <= priority(op)){//priority검사해서 높은 애들은 다 출력해줌
                    oss << op << " ";
                    st.pop();
                }
                else break;
            }
            st.push(c); //새 오퍼레이터를 스택의 맨 위에 집어 넣음
        }
    }
    while(!st.isEmpty()){//남아있는 오퍼레이터 다 pop으로 뽑기
        op = st.peek();
        oss << st.pop() << " ";
    }
    return oss.str();//str() 스트링으로 반환하는 함수, oss를 str으로 바꿔줌
}