#pragma once
#include <iostream>

#define INF 9999

//another way to make singly linked list

class node{
    private:
        int weight;//가중치
        int v1;//첫 번째 간선
        int v2;//두번째 간선
        node* next;//다음 node, link랑 같은 역할

    public:
        node(int val = INF, int vx1 = -1, int vx2 = -1){
            weight = val;
            v1 = vx1;
            v2 = vx2;
            next = nullptr;
        }
        ~node(){}

        node* getLink(){ return next; }//다음 Node를 리턴
        int getWeight(){ return weight; }//간선의 weight를 리턴
        int getSource(){ return v1; }//소스 = 정점1
        int getTarget(){ return v2; }//타겟 = 정점2 

        void setLink(node* target){ next = target; }//포인터가 target가리키게함

        void insertNext(node* newnode){//node의 다음 자리에 newnode 넣기
            if(newnode!=nullptr){
                newnode->next = next;//원래 node->next를 newnode->next로 정해줌, 즉 원래 node 뒤에 오는 node를 newnode 뒤에 붙여줌
                next = newnode;//원래 node->next 를 newnode로 바꿔줌, 즉 원래 node 뒤에 newnode를 붙여줌
            }   
        }
        
        node* removeNext(){//node의 다음 자리 node를 지움 
            node* removed = next;//node 뒤 node, 즉 지울 node, next를 removed로 정함
            if(removed!=nullptr){//지울 node,removed가 마지막 node인 경우
                next = removed->next;//removed앞의 node의 next가 removed의 다음 node가 됨
            return removed;
            }
        }
};


class o_linked_list{
    protected:
        node origin;//시작 node

    public:
        o_linked_list(){}
        ~o_linked_list(){ clear(); }

        void clear(){
            while(!isEmpty()){
                origin.removeNext();
            }
        }

        bool isEmpty(){//공백 확인
            return getHead() == nullptr;//origin 바로 다음 node == head
        }

        node* getHead(){//예전 연결리스트에서 head node 방식 그대로, 첫 node를 부르는 연산
            return origin.getLink();
        }//getHead()를 쓰는 이유: 간선중에 가장 작은 애들을 불러와야하기 때문 

        void removeHead(){//head 를 지우는 연산
            origin.removeNext();//return은 내가 추가함
        }//removeHead()를 쓰는 이유 : getHead()에서 불러온 head를 쓰면 안되기 때문에 지워줌

        void orderedInsert(node* n){//가장 중요함
            int w = n->getWeight();
            node* prev = &origin;//이전 node는 일단 origin의 주소로 정해둠
            node* now = getHead();//현재 node는 head
            while(now!=nullptr){//현재 target이 nullptr가 아닌 경우
                int now_w = now->getWeight();//now의 weight가 현재의 weight 보다 크거나 같으면
                // 1 3 7 9 16 인 리스트에서
                // 8 을 넣는 경우 생각
                // 8>1, 3, 7 && 9>8 => 9앞에 8 넣음 
                if(now_w >= w){//등호는 빼도 상관없음
                    prev->insertNext(n);
                    return;//void 함수는 끝내려면 아무 것도 넣지않고 return 해주면 됨
                }
                prev = now;
                now = now->getLink();//한 칸씩 옮겨줌
            }
            prev->insertNext(n);//맨 끝에 삽입해야하는데 끝까지 가서 now==nullptr이라 작동 안하는 경우
            return;
        }

        size_t size(){
            int count = 0;
            for(node* p=getHead(); p!=nullptr; p=p->getLink()){
                count++;
            }
            return count;
        }//사이즈 구하기

        void display(){
            std::cout << "항목 수: " << size() << "\n";
            for(node* p=getHead(); p!=nullptr; p=p->getLink()){
                std::cout << p->getWeight() << " " << p->getSource() << " ";
                std::cout << p->getTarget() << "\n";
            }
        }
};