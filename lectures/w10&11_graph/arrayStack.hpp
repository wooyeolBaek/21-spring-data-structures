#pragma once
#include <iostream>

//#pragma once가 표준은 아닌데 많이 씀,
//정석은 #ifndef ...

#define MAX_STACK_SIZE 100

inline int error(const char* str){ //교과서 예제 코드에서 char* str로 되어있음
//C++ ISO 표준이 바껴서 이제 변수<->상수 암시적 변환이 안됨. 문자열 상수는 const char* 써야함
    std::cerr << str << "\n"; //에러의 경우는 std::cerr로 출력
    exit(1);
}; //inline: 인라인 함수는 함수를 호출하지 않고, 함수를 사용하는 위치에 컴파일러가 코드 자체를 복사해줌
//그래서 라인 안에 들어가 있다고해서 inline...더 빠르긴 함..

class ArrayStack{
    private:
        int data[MAX_STACK_SIZE]; //요소의 배열
        int top; // 요소의 개수

    public:
        ArrayStack(){ top = -1; }
        ~ArrayStack(){}
        bool isEmpty(){ return top == -1;}
        bool isFull(){ return top == MAX_STACK_SIZE-1; }

        void push(int e){
            if(isFull()){ error("스택 포화 에러");}
            data[++top] = e;
        }

        int pop(){
            if(isEmpty()){ error("스택 공백 에러"); }
            return data[top--];
        }

        int peek(){
            if(isEmpty()){error("스택 공백 에러");}
            return data[top];
        }
        
        void display(){
            std::cout << "[스택 항목의 수 = " << top+1 << "] ";
            for(int i=0; i<=top; i++){
                std::cout << "<" << data[i] << ">";
            }
            std::cout << "\n";
        }
};


