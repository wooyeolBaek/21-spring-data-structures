#pragma once
#include "CircularQueue.hpp"

class CircularDeque : public CircularQueue{
    public:
        CircularDeque(){}
        void addFront(int val){
            if(isFull()){
                error("ERRPR : 덱이 포화상태입니다. \n");
            }
            else{
                data[front] = val;
                front = (front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            }
        }
        void addRear(int val){enqueue(val);}
        int deleteFront(){return dequeue();}
        int deleteRear(){
            if(isEmpty()){
                error("ERROR : 덱이 공백상태입니다. \n");
                return 0; // 이상해서 내가 넣음
            }
            else{
                int result = data[rear];
                rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                return result;
            }
        }
        int getFront(){return peek();}
        int getRear(){
            if(isEmpty()){
                error("ERROR : 덱이 공백상태입니다. \n");
                return 0; // 이상해서 내가 넣음
            }
            else{
                return data[rear];
            }
        }
        void display(){
            std::cout << "Deque 안에는 : ";
            int maxi =(front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            //논리연산 ? 참값 : 거짓값 
            for(int i = front+1; i <= maxi; i++){
                std::cout << data[i % MAX_QUEUE_SIZE] << " ";
            }  
            std::cout << "\n";
        }
};

int main(){
    CircularDeque que;
    for(int i = 1; i < 10; i++){
        if(i % 2 == 0){que.addFront(i);}
        else{que.addRear(i);}
    }
    que.display();
    que.deleteFront();
    que.deleteFront();
    que.deleteRear();
    que.display();
    return 0;
}