#pragma once //main함수에서 중복으로 불러오지 않게 방지, 정의 안됐을 때만 불러오는 코드
#include <iostream>
#include "Student.hpp"
#define MAX_STACK_SIZE 100
//Array 기반 Student Stack 구현
inline int error(const char* str){//에러를 받아서 오류메세지 출력하는 함수, const써줘야 상수로 인식함, 암시적변환
    std::cerr << str << "\n";//표준출력 cout 이랑 비슷한거, 에러 내보냄
    exit(1); //정상종료가 아니라 1 출력, int main쓰는 이유가 0으로 종료하면 정상적인거고 그게 아니면 비정상적
};

// StudentStack : 학생정보를 저장하는 스택 클래스
class StudentStack{
    private:
        Student data[MAX_STACK_SIZE]; //data array
        int top; // top을 가리키는 index

    public:
        StudentStack(){top = -1;}
        ~StudentStack(){}
        bool isEmpty(){return top == -1;}
        bool isFull(){return top == MAX_STACK_SIZE -1;} //0부터 시작하니까 하나 더 작아야함
        
        void push(Student e){ // 정수 데이터를 넣고 top이 하나 늘어남
            if(isFull()){//isFull이면 에러출력
                error("스택이 가득 차 있습니다.");
            }
            data[++top] = e;
        }
        Student pop(){ //데이터를 꺼내고 top이 하나 줄어듬
            if(isEmpty()){
                error("스택이 비어 있습니다.");
            }
            return data[top--];//top에 있는 데이터를 꺼내고 -1이 되어 top이 하나 작아짐
        }
        Student peek(){
            if(isEmpty()){
                error("스택이 비어 있습니다.");
            }
            return data[top];
        }
        void display(){//내부 데이터 확인
            std::cout << "[스택 항목의 수 = " << top+1 << "]\n";
            for(int i = 0; i <= top; i++){
                std::cout << " <" << data[i].contents() << ">\n";
            }
            
        }
};
