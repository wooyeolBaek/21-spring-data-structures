#pragma once
#include <iostream>

inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};
// 다른 식으로 singly linked list를 구현
// linkedlist로 리스트 구현
class node{
    private:
        int data; 
        node* next; //다음번 노드를 포인트하는 next라는 포인터
    public:
        node(int val = 0){//노드 생성자
            data = val;
            next = nullptr;
        }

    //node class의 연산
        node* getLink(){return next;} //다음번 노드를 가리키는 포인터를 반환 
        int getData(){return data;} //노드 데이터 리턴 
        void setLink(node* target){next = target;} 
        //노드의 포인터를 하나 받아서 받은 노드의 포인터와 next노드의 포인터가 같아지게 함

        void insertNext(node* newnode){ //삽입연산
            if(newnode != nullptr){
                newnode->next = next; //A->B->C에서 newnode->C과정
                next = newnode; //A->B->C에서 A->newnode과정
            }    
        } //노드의 다음 자리에 새 노드 넣음

        node* removeNext(){ //다음노드 지우기
            node* removed = next;
            if(removed != nullptr){
                next = removed->next;
            }
            return removed; //removed가 마지막 노드여도 문제없이 반환
        }//노드의 다음 자리 노드를 지우는 연산
}; 

class hn_s_linked_list{
    protected:
        node origin;
    public:
        hn_s_linked_list(): origin(0){}//생성자, 0으로 initialized 되는 노드
        ~hn_s_linked_list(){clear();} //소멸자

        void clear();//리스트를 지우는 연산
        node* getHead(); //첫 노드를 부르는 연산, 노드의 포인터로 리턴
        bool isEmpty(); //공백 확인

        node* getEntry(int pos); //pos위치 노드 조회연산
        void insert(int pos, node* n); //삽입연산
        void remove(int pos); //삭제연산
        node* find(int value); //검색연산
        void replace(int pos, node* n); // 치환연산
        size_t size(); //사이즈 반환
        void display(); //LinkedList의 전체내용 출력
};

void hn_s_linked_list::clear(){
    while(!isEmpty()){
        remove(0);
    }
} // 리스트를 지우는 연산

node* hn_s_linked_list::getHead(){
    return origin.getLink(); 
    //origin은 처음 initialize할때 head 노드 전에 있는 가상의 노드
    //따라서 origin의 다음 노드가 실제 linkedlist의 head 노드
} // 첫 노드를 부르는 연산

bool hn_s_linked_list::isEmpty(){
    return getHead() == nullptr;
} // 공백 확인

node* hn_s_linked_list::getEntry(int pos){
    node* n = &origin;
    for(int i = -1; i < pos; i++, n = n->getLink()){
        //시작점;종료조건;루프돌 때 마다 연산 => 사실 연산은 하나가 아니라 여러개 가능 
        if(n == nullptr){ break; }
    }
    return n;
} // 조회연산

void hn_s_linked_list::insert(int pos, node *n){
    node* prev = getEntry(pos - 1); //추가할 위치  이전의 노드포인터를 가져옴
    if(prev != nullptr){ // 이전 노드가 비어있을 경우 이전 노드 다음에 n을 추가해줌
        prev->insertNext(n);
    }
} // 삽입연산

void hn_s_linked_list::remove(int pos){
    node* prev = getEntry(pos - 1);
    delete prev->removeNext();
} // 삭제연산

node* hn_s_linked_list::find(int value){
    for(node *p = getHead() ; p != nullptr ; p = p->getLink()){
    //for문: 초기식;조건식;변화식
        if(p->getData() == value){ return p; }
    }
    return nullptr;
} // 검색연산 (value와 같은 값을 찾음). 가장 먼저 나오는 노드를 리턴
    
void hn_s_linked_list::replace(int pos, node *n){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        delete prev->removeNext();
        prev->insertNext(n);
    }        
} // 치환연산

size_t hn_s_linked_list::size(){
    int count = 0;
    for(node *p = getHead(); p != nullptr ; p = p->getLink()){
        count++;
    }
    return count;
} // 사이즈 구하기

void hn_s_linked_list::display(){
    std::cout << "전체 항목의 수: " << size() << ", ";
    for(node *p = getHead(); p != nullptr ; p = p->getLink()){
        std::cout << p->getData() << " ";
    }
    std::cout << "\n";
} // Linked List의 전체 내용 출력


