#pragma once
#include "adjListGraph.hpp"
#include "circularQueue.hpp"

//srchAMGraph와 거의 비슷
class SrchALGraph : public AdjListGraph{
    protected:
        bool visited[MAX_VTXS];

    public:
        void resetVisited(){
            for(int i=0; i<size; i++){
                visited[i] = false;
            }
        }
        bool isLinked(int u, int v){
            for(Node* p = adj[u]; p != nullptr; p=p->getLink()){//adj[u]를 따라 탐색
                if(p->getId()==v){ return true; }//v와 연결돼 있으면 true 출력
            }
            return false;
        }

        //깊이 우선 탐색
        void DFS(int v){
            visited[v] = true;
            std::cout << getVertex(v) << " ";
            for(Node* p = adj[v]; p!=nullptr; p=p->getLink()){//탐색법만 바뀜
                if(visited[p->getId()]==false){
                    DFS(p->getId());
                }
            }
        }

        //깊이 우선 탐색
        void BFS(int v){
            visited[v]=true;
            std::cout << getVertex(v) << " ";
            CircularQueue que;
            que.enqueue(v);
            while(!que.isEmpty()){
                int v = que.dequeue();
                for(Node* w = adj[v]; w != nullptr; w=w->getLink()){//이 것도 탐색법이 바뀜
                    int id = w->getId();//id를 따로 불러야함, 왜냐면 노드마다 가지고있는 id의 정보가 따로 있음
                    if(!visited[id]){//한 id를 가지는 노드가 여러개 있음,
                    //주의할 것: adj list 가 같은 id를 공유해도 서로 다른 노드
                        visited[id] = true; //방문 한적 없는 id를 true로 바꿔줌
                        std::cout << getVertex(id) << " ";
                        que.enqueue(id);
                    }
                }
            }
        }
};