#pragma once
#include <iostream>

//node 만들기
class BinaryNode{
    protected:
        int data;
        BinaryNode* left;
        BinaryNode* right;
    
    public:
        BinaryNode(int val=0, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
            :data(val), left(l), right(r){} //l:왼쪽 자식, r:오른쪽 자식
        ~BinaryNode(){}

        void setData(int val){//데이터 정해줌
            data = val;
        }
        void setLeft(BinaryNode* l){//왼쪽 자식 정해줌
            left = l;
        }
        void setRight(BinaryNode* r){//오른쪽 자식 정해줌
            right = r;
        }
        int getData(){//데이터값 반환
            return data;
        }
        BinaryNode* getLeft(){//왼쪽 자식 반환
            return left;
        }
        BinaryNode* getRight(){//오른쪽 자식 반환
            return right;
        }
        bool isLeaf(){//자식이 아에 없으면 true
            return left == nullptr && right == nullptr;
        }
};

