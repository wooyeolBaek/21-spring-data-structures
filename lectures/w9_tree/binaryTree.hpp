#pragma once
#include <iostream>
#include "binaryNode.h"
#include "circularQueue.h" //레벨 순회용

//tree만들기
class BinaryTree{
    protected:
        BinaryNode* root; //루트 정의
    
    public:
        BinaryTree(): root(nullptr){}
        ~BinaryTree(){}

        void setRoot(BinaryNode* node){ //root 지정
            root = node;
        }
        BinaryNode* getRoot(){ //root 반환 
            return root;
        }
        bool isEmpty(){ //root 비어있는지 확인
            return root == nullptr;
        }
        //탐색함수, 순환
        //전위 순회
        void preorder(BinaryNode* node){ //전위순회, root->left->right, root출력->왼쪽탐색->오른쪽탐색
            if(node != nullptr){//받은 노드가 nullptr가 아닐 때
                std::cout << " [" << node->getData() << "] "; //받은 node 값 출력
                if(node->getLeft() != nullptr){ //왼쪽탐색
                    preorder(node->getLeft()); //왼쪽 자식의 값 반환
                }
                if(node->getRight() != nullptr){ // 오른쪽탐색
                    preorder(node->getRight()); //오른쪽 자식의 값 반환
                }
            }
        }
        void preorder(){//전위순회 오버로딩, node가 주어지지 않을 경우 root를 노드로 순회
            std::cout << "preorder: ";
            preorder(root);
            std::cout << "\n";
        }
        
        //중위 순회
        void inorder(BinaryNode* node){ //중위순회, left->root->right, 왼쪽탐색->root출력->오른쪽탐색
            if(node != nullptr){ //받은 노드가 nullptr가 아닐 때 
                if(node->getLeft() != nullptr){ //왼쪽 탐색
                    inorder(node->getLeft()); //왼쪽 자식의 값 반환
                }
                std::cout << " [" << node->getData() << "] ";//받은 node 값 출력
                if(node->getRight() != nullptr){ //오른쪽 탐색
                    inorder(node->getRight()); // 오른쪽 자식의 값 반환
                }
            }
        }
        void inorder(){ //중위순회 오버로딩, node가 주어지지 않을 경우 root를 노드로 순회
            std::cout << "inorder: ";
            inorder(root);
            std::cout << "\n";
        }
        
        //후위 순회
        void postorder(BinaryNode* node){ //후위순회, 왼쪽탐색->오른쪽탐색->root출력
            if(node != nullptr){ //받은 노드가 nullptr가 아닐 때 
                if(node->getLeft() != nullptr){//왼쪽 탐색
                    postorder(node->getLeft());//왼쪽 자식의 값 반환
                }
                if(node->getRight() != nullptr){//오른쪽 탐색
                    postorder(node->getRight());//오른쪽 자식의 값 반환
                }
                std::cout << " [" << node->getData() << "] ";//받은 node 값 반환
            }
        }
        void postorder(){//후위순회 오버로딩, node가 주어지지 않을 경우 root를 노드로 순회
            std::cout << "postorder: ";
            postorder(root );
            std::cout << "\n";
        }
        void levelorder(){ //레벨 순회, 큐={1,2,3,4,5,6,7,...}이런 식으로 노드가 하나씩 추가됨, 앞에서 하나씩 빼서 출력하는 방식
            std::cout << "levelorder: ";
            if(!isEmpty()){ //비어있지 않을 때 
                CircularQueue q; //원형 큐,q 정의
                q.enqueue(root); //큐에 root 넣기
                while(!q.isEmpty()){ //큐가 차있을 때 
                    BinaryNode* n = q.dequeue(); //큐에서 값을 하나 빼 n으로 지정
                    if(n != nullptr){ //n이 빈 값이 아닐 때 
                        std::cout << " [" << n->getData() << "] ";//root n 값 반환
                        q.enqueue(n->getLeft()); // root n의 좌우 자식 큐에 넣기
                        q.enqueue(n->getRight());
                    }
                }
            }
            std::cout << "\n";
        }
        
        int getCount(BinaryNode* node){ //트리 전체의 node 개수
            if(node == nullptr){ //비어있는 node는 0 반환
                return 0;
            }
            return 1 + getCount(node->getLeft()) + getCount(node->getRight()); //받은 node 하나 세고, 왼쪽 자식 오른쪽 자식 넣어서 재귀
        }
        int getCount(){ //트리 전체의 node 개수 오버로딩
            return isEmpty() ? 0 : getCount(root); //비어있으면 0, 차있으면 getCount(root) 반환
        } //isEmpty() ? 0까지 지워도 됨
        
        int getLeafCount(BinaryNode* node){ //입사귀 개수 셈
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()){ //node가 입사귀이면 1 반환
                return 1;
            }
            else{
                return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());//양쪽 자식에 재귀로 입사귀가 나올때까지 탐색
            }
        }
        int getLeafCount(){ //오버로딩, 비어있지 않은 node에 대해 입사귀 개수 셈
            return isEmpty() ? 0 : getLeafCount(root); //isEmpty() ? 0까지 지워도 됨
        }

        int getHeight(BinaryNode* node){// 왼쪽 오른쪽 자식중 높이가 큰 것을 반환
            if(node == nullptr){
                return 0;
            }
            int hLeft = getHeight(node->getLeft());
            int hRight = getHeight(node->getRight());
            return (hLeft>hRight) ? hLeft+1 : hRight+1;//자식이 없으면 1, 있으면 1보다 큰 수 반환
        }
        int getHeight(){ //오버로딩, root의 왼쪽 오른쪽 자식중 높이가 큰 것 반환
            return isEmpty() ? 0 : getHeight(root); //isEmpty() ? 0까지 지워도 됨
        }
        
        int evaluate(BinaryNode* node){//수식 트리를 통한 계산
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()){ return node->getData();} //node가 리프노드일때 값(피연산자) 반환
            else{//그냥 노드일때 
                int op1 = evaluate(node->getLeft());//node의 왼쪽 리프노드
                int op2 = evaluate(node->getRight());//node의 오른쪽 리프노드
                switch(node->getData()){//node의 data 종류별로 연산 정의
                    case '+': return op1+op2;
                    case '-': return op1-op2;
                    case '*': return op1*op2;
                    case '/': return op1/op2;
                }
                return 0;
            }
        }
        int evaluate(){//오버로딩,
            return evaluate(root);
        }

        int calcSize(BinaryNode* node){//용량계산 
            if(node == nullptr){
                return 0;
            }
            return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
        }//node자신의 값 + node 왼쪽 자식 값 + node 오른쪽 자식 값
        int calcSize(){//오버로딩
            return calcSize(root);
        }
};