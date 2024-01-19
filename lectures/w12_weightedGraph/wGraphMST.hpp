#pragma once
#include <iostream>
#include "wGraph.hpp"
#include "oLinkedList.hpp"
#include "vertexSets.hpp"



#define INF 9999

//WGraphMST: 최소 신장 트리(MST) 기능이 추가된 가중치 그래프 클래스
class WGraphMST : public WGraph{
        public:
            //Kruskal MST: kruskal의 최소 비용 신장 트리 프로그램
            void Kruskal(){
                o_linked_list o_edgelist;
                std::cout << "start," << "size:" << size;
                for(int i=0; i<size-1; i++){//모든 간선을 ordered에 넣음
                    std::cout << "i:" << i;
                    for(int j=i+1; j<size; j++){//self-edge가 없으므로 i==j인 것은 필요없음 그래서 위의 for문 i는  size-1까지만 하면됨
                        std::cout << "j:" << j;
                        if(hasEdge(i,j)){
                            std::cout << "inserted:";
                            o_edgelist.orderedInsert(new node(getEdge(i,j),i,j));//생성자의 인수는 weight, 정점1, 정점2 순서
                        }//이렇게 쭉 돌면 orderedlist가 만들어짐 
                    }
                }
                std::cout << "\n";
                VertexSets set(size);//여기서의 size=전체 vertex 숫자
                int edgeAccepted = 0;//MST edge가 몇개 들어갔는지 확인
                while(edgeAccepted<size-1){
                    node* e = o_edgelist.getHead();
                    int uset = set.findSet(e->getSource());//sourcevertex의 set을 구해 uset에 넣어줌
                    int vset = set.findSet(e->getTarget());//targetvertex의 set을 구해 vset에 넣어줌
                    if(uset!=vset){
                        std::cout << "An edge added to MST: " << getVertex(e->getSource());
                        std::cout << " " << getVertex(e->getTarget()) << " " << e->getWeight() << "\n";
                        set.unionSets(uset, vset);//uset과 vset을 합쳐줌
                        edgeAccepted++;
                    }
                    o_edgelist.removeHead();//head지워주기, 왜냐면 다음 것을 불러와야함
                }
                std::cout << "\n";
            }

            void Prim(){//Prim의 최소 비용 신장 트리 프로그램
                bool selected[MAX_VTXS];//정점인지 확인하기 위함
                int dist[MAX_VTXS];//지금까지 정점들과의 거리를 구함
                int source_vertex[MAX_VTXS];//prim알고리즘으로 할때 어떤 정점에서 잰 거리인지 정확하게 재줌,정점 그룹들에서의 거리이기 때문에 그 소스가 뭔지 같이 가지고 있어줘야 함
                for(int i=0; i<size; i++){//모든 정점들에서 
                    dist[i] = INF; //거리는 무한대로 줌
                    selected[i] = false; //아직 고른적 없으니까 selected도 다 flase로 둠
                    source_vertex[i] = 0;
                } 
                dist[0] = 0;//0번부터 시작, 자기 자신은 0번 부터 시작하니까
                for(int i=0; i<size; i++){
                    int u = getMinVertex(selected, dist);//현재 MST에서 최소 거리 vertex를 고름
                    //이렇게 되면 0번을 처음에 고름
                    selected[u] = true;//우리가 고른점은 골랐으니까 true가 됨
                    if(dist[u]>=INF){//말이 안되는 경우, 가장작은 정점을 골랐는데 간선이 없는 경우, 간선 못만듦
                        return;
                    }
                    if(u!=source_vertex[u]){//u가 selfvertex가 아니면 
                        std::cout << "An edge added to MST: " << getVertex(u) << " ";//첫 번째는 source_vertex와 같아지니까 출력이 안됨
                        std::cout << getVertex(source_vertex[u]) << " ";
                        std::cout << getEdge(u, source_vertex[u]) << "\n";
                    }//새 mst부터 노드들의 거리를 업데이트함
                    for(int v=0; v<size; v++){//루프를 계속 돌면서 
                        if(getEdge(u, v)!=INF){//edge가 있다면
                            if(!selected[v] && getEdge(u, v) < dist[v]){//고른적이 없는 정점인데 set에 추가하는 정점의 거리가 지금까지 우리가 찾았던 최저 거리보다 작으면 
                                dist[v] = getEdge(u, v);//새 정점부터의 거리가 최소이니까 그 거리를 추가해줌. 그 거리를 u,v의 정점 사이의 가중치로 바꿔줌
                                source_vertex[v] = u;
                            }
                        }
                    }

                }
                std::cout << "\n";

            }

            //주변의 정점들 중 지금 고른 정점들 중 가장 가까운 정점을 찾는 함수
            int getMinVertex(bool* selected, int* dist){ //selected는 우리가 이미 이 정점을 골랐는지 아닌지 임, dist는 근처 정점 중 자신과의 거리 계산
                int minv = 0;
                int mindist = INF;//최소거리(mindistance)=INF, 왜냐면 이게 가장 큰 값보다 조금 작아져야함
                for(int v=0; v<size; v++){
                    if(!selected[v] && dist[v]<mindist){//이게 아직 고르지 않은 정점이고, 그 정점까지의 거리가 mindistance보다 가까우면
                        mindist = dist[v];//최소거리가 새 거리로 바뀜
                        minv = v;//최소거리를 가지는 정점이 v로 바뀜
                    }
                }
                return minv;
            }
            
};