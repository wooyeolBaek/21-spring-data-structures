#pragma once
#include <iostream>
#include <vector>
#include <chrono>

struct node{
    int data;
    node* next;
};

class s_linked_list{
    protected:
        node* head;
        node* tail;
        int size = 0;
    public:
        s_linked_list(){
            head = nullptr;
            tail = nullptr;
        }
        ~s_linked_list(){
            delete_list();
        }

        void push_front(int n);
        void push_back(int n);
        void insert_node_at(int idx, int n);

        int pop_front();
        int pop_back();
        int pop_node_at(int idx);
        void remove_node(int n);
        void delete_list();

        void replace_value_at(int idx, int n);

        int Size();
        void display_contents();
        int search_value(int n);
};

void s_linked_list::push_front(int n){
    node* ptr = new node;//새 노드의 메모리 할당
    ptr->next = head;
    ptr->data = n;
    head = ptr;
    if(ptr->next == nullptr){
        tail = ptr;
    }
    size++;
}
void s_linked_list::push_back(int n){
    node* tmp = new node; //새 노드의 메모리 할당
    tmp->data = n;
    tmp->next = nullptr;
    if(head == nullptr){ //head가 없으면 tail도 없음
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
    size++;
}
void s_linked_list::insert_node_at(int idx, int n){
    if(size < idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다. \n.";
    }
    else if(idx == 0){
        push_front(n);
    }
    else if(idx == size){
        push_back(n);
    }
    else{
        node* ptr = head; // head주소 ptr에 저장
        node* tmp = ptr; //ptr
        node* new_node = new node; //새 node 선언
        new_node->data = n; //새노드의->data 에 n저장
        new_node->next = nullptr; //새 node의 next 초기화
        for(int i = 0; i < idx; i++){
            tmp = ptr; //들어갈 노드의 직전 노드 위치
            ptr = ptr->next; // 들어갈 노드의 위치
        }
        tmp->next = new_node;
        new_node->next = ptr; // 노드 삽입
        size++;
        }
    }

    int s_linked_list::pop_front(){
        if(head == nullptr){
            std::cout << "linked list가 비었습니다.\n";
            exit(1);
        }
        node* ptr = head;
        int value = head->data;
        head = ptr->next;
        if(head == nullptr){ tail == nullptr ;}
        delete ptr;
        size--;
        return value;
    }
    int s_linked_list::pop_back(){
        if(head == nullptr){
            std::cout << "linked list가 비었습니다.\n";
            exit(1);
        }
        node* ptr = head;
        node* tmp = new node;
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
    int s_linked_list::pop_node_at(int idx){
        int value = -1;
        if(size <= idx || 0 > idx){
            std::cout << "해당 인덱스는 존재하지 않습니다. \n";
        }
        else if(idx == 0){
            std::cout << "linked list가 비었습니다. \n";
            exit(1);
        }
        else if(idx == 0){
            value = pop_front();
        }
        else if(idx == size -1){
            value = pop_back();
        }
        else{
            node* ptr = head;
            node* tmp = ptr;
            for(int i = 0; i < idx; i++){
                tmp = ptr; //현재 노드 = tmp
                ptr = ptr->next; //다음 노드로 타겟 바꾸기
            }
        }   
    }
    void s_linked_list::delete_list(){
        node* ptr = head;
        while(ptr != nullptr){
            head = ptr->next;
            delete ptr;
            ptr = head;
        }
        size = 0;
        std::cout << "리스트가 삭제되었습니다. \n";
    }

    void s_linked_list::replace_value_at(int idx, int n){
        node* ptr = head;
        if(size == 0){
            std::cout << "linked list가 비었습니다. \n";
            exit(1);
        }
        else if(size <= idx || 0 > idx){
            std::cout << "해당 인덱스는 존재하지 않습니다.\n";
        }
        else {
            for(int i = 0; i < idx; i++){
                ptr = ptr->next;
            }
            ptr->data = n;
        }
    }

    int s_linked_list::Size(){
        return size;
    }
    void s_linked_list::display_contents(){
        node* ptr = head;
        while(ptr != nullptr){
            std::cout << ptr->data << "->";
            ptr = ptr->next;
        }
        std::cout << "nullptr" << "\n";
    }
    int s_linked_list::search_value(int n){
        node* ptr = head;
        int idx = 0;
        bool isFind = false;
        while(ptr != nullptr){
            if(ptr->data ==n){
                std::cout << n << " 은 " << idx << " 에 있습니다. \n";
                isFind = true;
                break;
            }
            ptr = ptr->next;
            idx++;
        }
        if(isFind == false){
            std::cout << n << " 은 리스트 안에 없습니다. \n";
            return -1;
        }
        else{
            return idx;
        }
    }


