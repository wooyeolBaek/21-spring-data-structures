#pragma once
#include <iostream>
#include "binaryNode.h"

#define MAX_QUEUE_SIZE 100

inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
}

//예전에 만든 circularqueue인데 data type만 int에서 BinaryNode*로 바뀜
class CircularQueue{
    protected:
        int front;
        int rear;
        BinaryNode* data[MAX_QUEUE_SIZE];
    public:
        CircularQueue(){front = rear = 0;}
        ~CircularQueue(){}
        bool isEmpty(){return front == rear;}
        bool isFull(){return (rear+1) % MAX_QUEUE_SIZE == front;}
        void enqueue(BinaryNode* val){ //큐 맨뒤에 데이터를 추가
            if(isFull()){
                error(" Error: 큐가 포화상태 입니다. \n");
            }
            else{
                rear = (rear+1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        BinaryNode* dequeue(){ //큐 맨 앞에서 데이터를 꺼냄
            if(isEmpty()){
                error(" Error: 큐가 공백상태입니다\n");
            }
            else{
                front = (front+1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }
};