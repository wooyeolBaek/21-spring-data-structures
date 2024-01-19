#pragma once
#include <iostream>
#include <vector>
#include <chrono>

//template로 node를 만듦
template<typename T>
struct node{ //struct로 만들면 기본적으로 public으로 지정됨 -> 포인터 접근이 편리, 물론 클래스로 만들어도 public으로 지정할 수는 있음
    T data;
    node<T> *next = nullptr;
    node<T> *prev = nullptr; // 일단 이렇게 노드 포인터 2개를 만들어 줍니다
};

template<typename T>
class s_linked_list{
    protected:
        node<T> *head;
        node<T> *tail;
        int size = 0;
    public:
        s_linked_list(){
            head = nullptr;
            tail = nullptr;
        }
        ~s_linked_list(){
            delete_list();
        }

        //삽입연산들
        void push_front(T n);
        void push_back(T n);
        void insert_node_at(int idx, T n);

        //삭제연산들
        T pop_front();
        T pop_back();
        T pop_node_at(int idx);
        void remove_node(T n);
        void delete_list();

        //대입
        void replace_value_at(int idx, T n);

        //검색 및 표시
        T Size();
        void display_contents();
        T search_value(T n);
};

template<typename T>
void s_linked_list<T>::push_front(T n){
    node<T>* ptr = new node<T>;
    ptr->next = head;
    ptr->data = n;
    head = ptr;
    if(ptr->next == nullptr){
        tail = ptr;
    }
    size++;
}

template<typename T>
void s_linked_list<T>::push_back(T n){
    node<T>* tmp = new node<T>;
    tmp->data = n;
    tmp->next = nullptr;
    if(head == nullptr){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
    size++;
}

template<typename T>
void s_linked_list<T>::insert_node_at(int idx, T n){
    if(size < idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다.\n";
    }
    else if(idx == 0){
        push_front(n);
    }
    else if(idx == size){
        push_back(n);
    }
    else{
        node<T>* ptr = head; // 노드 ptr == 노드 head
        node<T>* tmp = ptr; //노드 tmp == 노드 ptr
        node<T>* new_node = new node<T>; //새 노드 정의
        new_node->data = n; //새 노드의 data = n
        new_node->next = nullptr;//새 노드의 next는 일단 비워두기
        for(int i=0; i < idx; i++){
            tmp = ptr; //들어갈 노드의 직전 노드 위치
            ptr = ptr->next; //들어갈 노드의 위치
        }
        tmp->next = new_node;
        new_node->next = ptr;
        size++; 
    }
}

//삭제연산
template<typename T>
T s_linked_list<T>::pop_front(){
    if(head == nullptr){
        std::cout << "linked list가 비어있습니다.\n";
        exit(1);
    }
    node<T>* ptr = head; //head를 ptr노드로 옮기기
    int value = head->data; //head의 data를 value로 옮기기
    head = ptr->next; //ptr의 next를 head로 놓기
    if(head == nullptr){tail == nullptr;} //head가 비어있으면 tail도 비우기
    delete ptr; //ptr노드 지우기
    size--;
    return value;
}

template<typename T>
T s_linked_list<T>::pop_back(){
    if(size == 0){
        std::cout << "linked list가 비어있습니다. \n";
        exit(1);
    }
    node<T>* ptr = head;
    node<T>* tmp = new node<T>;
    while(ptr->next != nullptr){
        tmp = ptr;
        ptr = ptr->next;
    }
    int value = ptr->data;
    if(ptr == head){
        head = nullptr;
        tail = nullptr;
    }
    else{
        tail = tmp;
        tail->next = nullptr;
    }
    delete ptr;
    size--;
    return value;
}

template<typename T>
T s_linked_list<T>::pop_node_at(int idx){
    int value = -1;
    if(size <= idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다.\n";
    }
    else if(size == 0){
        std::cout << "linked list가 비어있습니다.\n";
        exit(1);
    }
    else if(idx == 0){
        value = pop_front();
    }
    else if(idx == size-1){
        value = pop_back();
    }
    else{
        node<T>* ptr = head;
        node<T>* tmp = ptr;
        for(int i=0; i<idx; i++){
            tmp = ptr;
            ptr = ptr->next;
        }
        value = ptr->data;
        tmp->next = ptr->next;
        size--;
        delete ptr;
        ptr = nullptr;
    }
    return value;
}

template<typename T>
void s_linked_list<T>::remove_node(T n){
    node<T>* ptr = head;
    node<T>* tmp = ptr;
    while(ptr != nullptr){
        if(ptr->data == n){
            break;
        }
        else{
            tmp = ptr;
            ptr = ptr->next; //ptr == 다음 노드
        }
    }
    if(ptr == nullptr){
        std::cout << n << "값의 노드는 존재하지 않습니다.\n";
    }
    else if(size == 1){
        head = nullptr;
        tail = nullptr;
    }
    else{
        size--;
        std::cout << ptr->data << "값의 노드를 하나 지웁니다.\n";
        tmp->next = ptr->next;
        if(ptr == tail){
            tail = tmp;
        }
        delete ptr; //동적할당 해제
    }
}

template<typename T>
void s_linked_list<T>::delete_list(){
    node<T>* ptr = head;
    while(ptr != nullptr){
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    size = 0;
    std::cout << "리스트가 삭제되었습니다. \n";
}

//대입
template<typename T>
void s_linked_list<T>::replace_value_at(int idx, T n){
    node<T>* ptr = head;
    if(size == 0){
        std::cout << "linked list가 비어있습니다. \n";
        exit(1);
    }
    else if(size <= idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다.\n";
    }
    else{
        for(int i=0; i<idx; i++){
            ptr = ptr->next;
        }
        ptr->data = n;
    }
}

//검색 및 표시
template<typename T>
T s_linked_list<T>::Size(){
    return size;
}

template<typename T>
void s_linked_list<T>::display_contents(){
    node<T>* ptr = head;
    while(ptr != nullptr){
        std::cout << ptr->data << "->";
        ptr = ptr->next;
    }
    std::cout << "nullptr" << "\n";
}

template<typename T>
T s_linked_list<T>::search_value(T n){
    node<T>* ptr = head;
    int idx = 0;
    bool isFind = false;
    while(ptr != nullptr){
        if(ptr->data == n){
            std::cout << n << " 은 " << idx << " 에 있습니다. \n";
            isFind = true;
            break;
        }
        ptr = ptr->next;
        idx++;
    }
    if(isFind == false){
        std::cout << n << " 은 리스트 안에 있습니다.\n";
        return -1;
    }
    else{
        return idx;
    }
}


