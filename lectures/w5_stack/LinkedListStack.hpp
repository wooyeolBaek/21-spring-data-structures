#pragma once
#include "SingleLinkedList.hpp"

//연결리스트기반 스텍 구현

inline int error(const char* str){
    //에러를 받아서 오류메세지 출력하는 함수
    std::cerr << str << "\n";
    exit(1);
};

class LinkedlistStack : public s_linked_list{
    public:
        LinkedlistStack() : s_linked_list(){} //생성자도 연결리스트 생성자 만드는 것과 동일하게 만듦, 연결리스트와 동일하게 생성
        bool isEmpty(){return Size() == 0;}
        void push(int e){
            push_front(e);
        }
        int pop(){
            if(isEmpty()){ error("스텍이 비어있습니다. ");}
            return pop_front();
        }
        int peek(){
            if(isEmpty()){ error ("스택이 비어있습니다. ");}
            return head->data;
        }
        void display(){ //순서가 반대로 나올 것임
            node* ptr = head;
            std::cout <<"[전체 스택의 수 = " << Size() << "]";
            for(int i = 0; i < Size(); i++){
                std::cout << "<" << ptr->data << ">";
                ptr = ptr->next;
            }
            std::cout << "\n";
        }
};