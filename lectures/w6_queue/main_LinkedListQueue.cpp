#pragma once
#include "CircularQueue.hpp"
#include "SingleLinkedList.hpp"

class LinkedListQueue : public s_linked_list{
    public:
        LinkedListQueue() : s_linked_list(){}
        ~LinkedListQueue(){}
        bool isEmpty(){return Size() == 0;} //isFull은 만들 필요 없음, 연결리스트라 계속 만들 수 있으니까
        void enqueue(int e){ // 연결리스트 특성상 앞에서 빼고 뒤에서 넣는 방식이 편리
            push_back(e);
        } 
        int dequeue(){
            if(isEmpty()){error("Queue가 비어있습니다.");}
            return pop_front();
        }
        int peek(){
            if(isEmpty()){error("Queue가 비어있습니다.");}
            return head->data;
        }
        void display(){
            std::cout << "Queue안에는 : ";
            node* ptr = head;
            while(ptr != nullptr){
                std::cout << ptr->data << " ";
                ptr = ptr->next;
            }
            std::cout << "\n";
        }
};

int main(){
    LinkedListQueue que;
    for(int i = 1; i < 10; i++){
        que.enqueue(i);
    }
    que.display();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.display();
    return 0;
}