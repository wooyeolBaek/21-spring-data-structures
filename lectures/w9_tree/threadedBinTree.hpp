#pragma once
#include <iostream>

//BinaryNode를 약간 바꾼거
class ThreadedBinNode{
    protected:
        int data;
        ThreadedBinNode* left;
        ThreadedBinNode* right;
    public:
    bool bThread;
    ThreadedBinNode(int val = 0, ThreadedBinNode* l = nullptr,
    ThreadedBinNode* r = nullptr, bool bTh = false)//thread인지 판별하는 bTh가 추가됨
    :data(val), left(l), right(r), bThread(bTh){}//여기에도 bTh 추가함
    int getData(){
        return data;
    }
    void setRight(ThreadedBinNode* r){
        right = r;
    }
    ThreadedBinNode* getLeft(){
        return left;
    }
    ThreadedBinNode* getRight(){
        return right;
    }
};

class ThreadedBinTree{
    private:
        ThreadedBinNode* root;
    public:
    ThreadedBinTree(): root(nullptr){}
    ~ThreadedBinTree(){}

    void setRoot(ThreadedBinNode* node){
        root = node;
    }
    ThreadedBinNode* getRoot(){
        return root;
    }
    bool isEmpty(){
        return root == nullptr;
    }
    void threadedInorder(){
        if(!isEmpty()){
            std::cout << "스레드 이진 트리 중위 순회: ";
            ThreadedBinNode* q = root;
            while(q->getLeft()){//nullptr이 나오면 멈춤
                q = q->getLeft(); //가장 왼쪽 노드로 이동
            }
            do{
                std::cout << " [" << q->getData() << "]"; //데이터를 출력
                q = findSuccessor(q); //후속자를 불러옴
            }while(q);
            std::cout << "\n";//개행:줄바꿈
        }
    }
    ThreadedBinNode* findSuccessor(ThreadedBinNode* p){//후속자 찾는 함수
        ThreadedBinNode* q = p->getRight(); //오른쪽 자식 포인터를 저장
        if(q == nullptr || p->bThread){
            //오른쪽 자식이 nullptr 이거나 스레드이면 오른쪽 포인터를 반환
            return q;
        }
        while(q->getLeft() != nullptr){
            //만약 오른쪽 자식이 존재하면(즉, 일반적인 노드라면) 다시 가장 왼쪽 노드로 이동
            //쭉 끝까지 이동함 
            q = q->getLeft();
        }
        return q;
    }
};