#pragma once
#include "aLGraph.hpp"
#define INF 99999


class AdjListWGraph : public AdjListGraph{
    public:
        AdjListWGraph(void){}
        ~AdjListWGraph(void){}

        // bool hasEdge(int i, int j){ return (getEdge(i, j)<INF); }//i, j의 가중치가 INF보다 작은경우 반환

        // void insertVertex(int id, std::string name){
        //     if(!isFull()){
        //         verNum[size] = id;
        //         vertices[size] = name;
        //         adj[size] = nullptr;
        //         inDeg[size] = 0;
        //         outDeg[size] = 0;
        //         visited[size] = 0;
        //         size++;
        //     }
        //     else{ std::cout << "vertex 추가 가능 범위를 초과했습니다. \n"; }
        // }

        // void insertEdge(int u, int v, int w=1){
        //     if(adj[u]==nullptr){
        //         adj[u]=new Node(v, w, nullptr);
        //     }
        //     else{
        //         Node* p = adj[u];
        //         while(p->getLink()!=nullptr){
        //             p = p->getLink();
        //         }
        //         p->setLink(new Node(v, w, nullptr));
        //     }
        //     outDeg[u]++;
        //     inDeg[v]++;
        // }

        void randomWalker(int i, int n, float q){//randomwalker 오버로딩, 가중치에 비례한 확률로 이동
            //std::cout << "start:" << getVertex(i) << "->\n";
            visited[i];
            while((n-1)!=0){
                if(q>dist(gen) || outDeg[i]==0){
                    int j;
                    j= (int)(dist(gen)*(size-1))+1;//0~7,size=8 => 0~6 => 1~7
                    i = (i+j)%size;
                    //std::cout << "jump:" << getVertex(i) << "->\n"; 
                }
                else{//가중치에 비례한 확률로 이동
                    int sum=0;//node에 연결된 간선들의 가중치들의 합
                    Node* w=adj[i];//i번째 vertex에 연결된 node들의 리스트
                    for(Node* u=adj[i]; u!=nullptr; u=u->getLink()){//연결된 간선들의 가중치 합을 구함
                        sum+=u->getWgt();
                    }
                    int p = (int)(dist(gen)*sum);//p = 0~가중치합 의 임의의 숫자를 뽑음
                    while(w->getLink()!=nullptr && p>0){//node들을 하나씩이동, 이동할 때 마다 가중치를 p에서 빼줌, p<0이 되면 멈춤 
                        w = w->getLink();
                        p-=w->getWgt();
                    }
                    i = w->getId();
                    // std::cout << "move:" << getVertex(i) << "->\n";
                }
                visited[i]++;
                n--;
            }
            // std::cout << "end\n";
        }

};