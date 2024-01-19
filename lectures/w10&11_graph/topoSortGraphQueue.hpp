#include <iostream>
#pragma once
#include "adjListGraph.hpp"
#include "circularQueue.hpp"


class TopoSortGraph : public AdjListGraph{
    public:
        TopoSortGraph(void){}
        ~TopoSortGraph(void){}

        void insertDirEdge(int u, int v){ //u에서 v로의 방향성 있는 edge를 만듦, 지금까지는 방향성이 없는 edge만 썻었음
            adj[u] = new Node(v, adj[u]); //vertices[u]가 가리키는 링크,즉 adj[u]를 Node(v)로 정함 + v가 가리키던 링크는 기존의 adj[u]가 가리키던 Node로 유지
        }
        void TopoSort(){
            CircularQueue q;
            int* inDeg = new int [size]; //size크기의 동적할당으로 모든 Vertices의 in-degree(진입차수) 정의, indegree==vertex에 들어오는 edge개수, inDeg[i]==i의 indegree 수
            for(int i=0; i<size; i++){//indegree의 모든 값 0으로 초기화
                inDeg[i] = 0;
            }
            for(int i=0; i<size; i++){
                Node* node = adj[i]; //i번째 adjlist의 첫 번째 Node
                while(node!=nullptr){//adj[i]의 마지막 Node가 나올 때까지
                    inDeg[node->getId()]++;//adj[i]의 Node에 있는 vertices들의 indegree를 하나씩 늘려줌
                    node = node->getLink();//다음 Node로 이동
                }
            }//여기부터 나중에
            for(int i=0; i<size; i++){//초기에 q에 들어갈 것들을 넣어줌 
                if(inDeg[i]==0){ q.enqueue(i); }
            }//indegree가 0인 vertex들을 stack에 삽입합니다.
            //이 vertex들이 위상정렬에서 처음 나오는 vertex들입니다.

            while(q.isEmpty()==false){//빌 때까지 이 작업 반복
                int w = q.dequeue();//하나 꺼내고 
                std::cout << getVertex(w) << " ";//vertex출력 
                Node* node = adj[w];
                while(node != nullptr){//전체의 리스트 순회
                    int u = node->getId(); //seed vertex의 이웃 vertex에 대해 연산을 수행합니다.현재 노드의 아이디를 보여줌
                    inDeg[u]--; // 그 노드들의 in-degree를 하나씩 줄여줍니다. 위에 20번쨰줄에서 한 작업의 반대 작업
                    if(inDeg[u]==0){
                        q.enqueue(u); // 그 노드들의 in-degree를 하나씩 줄여줍니다. 위에 20번쨰줄에서 한 작업의 반대 작업
                    }
                    node = node->getLink(); //다음 이웃을 조회, 노드를 다음 노드로 옮겨줌 
                }
            }
            std::cout << "\n";
            delete [] inDeg; // array 삭제는 delete [], 잊지 말기, 동적할당 해제
        }

};