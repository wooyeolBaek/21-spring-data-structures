#pragma once
#include <iostream>
#include "binaryTree.hpp"

//이진 탐색 트리
class BinSrchTree : public BinaryTree{
    public:
        BinSrchTree(void){}
        ~BinSrchTree(void){}

        BinaryNode* search(int key) {//재귀로 만듦
            BinaryNode* node = search(root, key);//root부터 key까지 탐색, 실제 탐색하는 것은 밑에 오버로딩한 search 함수
            if(node != nullptr){//leaf까지 도달
                std::cout << "탐색 성공. Key: " << key << "\n";
                std::cout << "노드: " << node->getData();
            }
            else{//nullptr가 리턴
                std::cout << "탐색 실패. Key: " << key << "\n";
                
            }    
            return node;
        }

        BinaryNode* search(BinaryNode *n, int key){//함수 오버로딩, n=시작 노드, key=키
        //이걸 따로 만드는 이유: 이걸로 삽입연산 할 예정
            if(n == nullptr){//nullptr까지 갔는데 못찾은 경우
                return nullptr;
            }
            if(key == n->getData()){//key를 찾음, 성공한 경우
                return n;
            }
            else if (key < n->getData()){//키가 더 작은 경우 왼쪽으로
                return search(n->getLeft(), key);
            }
            else{
                return search(n->getRight(), key);//키 값이 더 크면 오른쪽으로 감
            }
        }

        void insert(BinaryNode* n){
            if(n == nullptr){
                return;
            }
            if(isEmpty()){
                root = n;
            }
            else{
                insert(root, n);
            }
        }

        void insert(BinaryNode* r, BinaryNode* n){//함수 오버로딩
        //r=현재 탐색하고 있는 위치, n=새노드, 집어 넣고 싶은 노드
            if(n->getData() == r->getData()){//이번엔 중복 허용 안함
                return;
            }
            else if(n->getData() < r->getData()){
                if(r->getLeft() == nullptr){//왼쪽이 nullptr인 경우, 탐색이 실패한 경우
                    r->setLeft(n);//아래 왼쪽에 넣어 줌
                }
                else{
                    insert(r->getLeft(), n);//아닌 경우 한번 더 이 함수 불러옴
                }
            }
            else{
                if(r->getRight() == nullptr){
                    r->setRight(n);
                }
                else{
                    insert(r->getRight(), n);//탐색이 성공한 경우
                }
            }
        }
        //삭제부터 어려움
        void remove(int data){
            if(isEmpty()){
                return;
            }				
            BinaryNode *parent = nullptr;//root의 부모 노드 == nullptr
            BinaryNode *node = root;
            while(node != nullptr && node->getData() != data){
                parent = node;
                node = (data < node->getData())//밑에랑 이어지는 논리식
                        ? node->getLeft()
                        : node->getRight();
            }
            if(node == nullptr){//키가 없으니까 실패한 경우
                std::cout << "Key " << data << " does not exist";
                return;
            }
            else{//아니라면, 즉, 키가 있으면 
                remove (parent, node);//지금까지 기억했던 parent, node를 기준으로 삭제연산 시키면 됨
            }
        }

        void remove(BinaryNode* parent, BinaryNode* node){//함수 오버로딩, 자기 자신node와 parent노드를 기준으로 
        //왜나면 자신으로 가리키는 node는 있는데 parent를 가리키는 node는 없음
            //1번 케이스 : 삭제 위치가 단말 노드(leaf노드)일 경우, 그냥 지워주면 됨    
            if(node->isLeaf()){
                if(parent == nullptr){//node=root인 경우
                    root = nullptr;//root를 비움
                }
                else{
                    if(parent->getLeft() == node){//왼쪽을 불러와서 이게 node이면
                        parent->setLeft(nullptr);//이거를 nullptr로 만듦
                    }
                    else{
                        parent->setRight(nullptr);
                    }
                }
            }
            // 2번 케이스, 한 쪽 서브트리만 있는 경우
            else if(node->getLeft() == nullptr || node->getRight()== nullptr){
                BinaryNode *child = (node->getLeft() != nullptr)//왼쪽이 nullptr이 아닌경우
                                    ? node->getLeft()//왼쪽 반환
                                    : node->getRight();//아니면 오른쪽 반환
                if(node == root){//노드==루트인 경우
                    root = child;//root가 새 child가 돼야함
                }
                else{
                    if(parent->getLeft() == node){
                        parent->setLeft(child);
                    }
                    else{
                        parent->setRight(child);
                    }
                }
            }
            // 3번 케이스, 양쪽 서브트리가 다 있는 경우
            //오른쪽 트리를 기준으로 작업하는 것으로 만듦, 양쪽 다하긴 힘듦
            else{
                BinaryNode* succp = node; // 계승자의 바로 위 부모가 노드
                BinaryNode* succ = node->getRight(); // 계승자 노드
                while(succ->getLeft() != nullptr){
                    succp = succ;
                    succ = succ->getLeft();
                } // 오른쪽 트리에서 가장 작은 노드를 골라냅니다.
                if(succp->getLeft() == succ){//parents의 왼쪽 노드가 계승자일때, 보통 다 이 케이스로 넘어감 
                    succp->setLeft(succ->getRight());//succ가 parent의 왼쪽자식, 여기에 succ의 오른쪽 자식들을 쭉 붙여줌
                } 
                // 오른쪽 트리에서 가장 작은 노드가 왼쪽 노드일 때
                // 계승자 부모의 왼쪽 노드를 계승자의 오른쪽 자식노드로 정해줍니다
                else{//딱 한가지 예외 계승자가 바로 위에 있는 경우, 이 케이스가 들어가는 이유는 처음에 오른쪽을 골랐기 때문, BinaryNode* succ = node->getRight(); 이거 때문
                    succp->setRight(succ->getRight());
                }
                // 오른쪽 트리에서 가장 작은 노드가 오른쪽 노드일 때
                // 계승자 부모의 오른쪽 노드를 계승자의 오른쪽 자식노드로 정해줍니다
                node->setData(succ->getData());//node의 데이터를 계승자의 것으로 바꿔줌
                node = succ;
            }
            delete node;//지금의 node는 원래 위치에 복사했으므로 필요 없어서 지움
        }
        
};