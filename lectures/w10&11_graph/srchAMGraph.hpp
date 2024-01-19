#pragma once
#include <iostream>
#include "adjMatGraph.hpp"
#include "circularQueue.hpp"

class SrchAMGraph : public AdjMatGraph{
    protected:
        bool visited[MAX_VTXS]; //방문기록을 남기는 변수

    public:
        void resetVisited(){ //방문기록들을 다 지움
            for(int i=0; i<size; i++){
                visited[i] = false;
            }
        }

        bool isLinked(int u, int v){ return getEdge(u, v)!=0; }
        //u, w가 연결되어있는지 확인
        // 가중치가 있는 것 할때도 사용하려고 0이 아닌 경우로 함

        //깊이 우선 탐색
        void DFS(int v){
            visited[v] = true;
            std::cout << getVertex(v) << " ";
            for(int w=0; w<size; w++){//전체 노드들에 대해
                if(isLinked(v, w)&&visited[w]==false){//시작점v와 노드w가 연결이 돼있고 방문하지 않은 경우
                    DFS(w);//재귀호출, 스택과 같은 효과
                }
                //이웃한 모든 vertex에 대해서 깊이 우선 탐색을 수행
                //재귀호출 사용
                //방문한 기록이 있으면 깊이 우선 탐색을 하지 않음
                //주의할 점 : self-loop가 있는 네트워크에서는 제대로 작동하지 않을 수 있음
            }
        }

        //너비 우선 탐색
        void BFS(int v){
            visited[v] = true;//자신은 방문한걸로 바꿈
            std::cout << getVertex(v) << " ";
            CircularQueue que;
            que.enqueue(v); //queue에 v 삽입
            while(!que.isEmpty()){ //큐가 빌 때까지
                int v = que.dequeue(); //queue에 남아 있는 vertex중 가장 먼저 삽입한 vertex를 가져옴
                for(int w=0; w<size; w++){
                    if(isLinked(v, w)&&visited[w]==false){//시작한 노드v와 노드w가 연결됐고 w를 방문하지 않은 경우
                        visited[w] = true;//w 방문
                        std::cout << getVertex(w) << " ";//w 출력
                        que.enqueue(w);//w 넣어줌
                    }//큐에 넣어줌
                }
                //이웃한 모든 vertex를 일단 queue에 삽입
                //큐에서 먼저 삽입한 순서(= seed노드에서 가까운 순서)로 꺼내서 탐색
            }
        }



};




