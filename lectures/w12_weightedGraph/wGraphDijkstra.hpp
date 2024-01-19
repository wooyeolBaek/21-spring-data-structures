#pragma once

#include "wGraph.hpp"
#include <iostream>

class WGraphDijkstra : public WGraph{
    protected:
        int path[MAX_VTXS];//어떤 path를 거쳐서 이 최소 경로가 나왔는지, 자신 바로 전꺼만 저장하면됨, 자신과의 어떤 간선이 그 역할을 해주는지 
        int dist[MAX_VTXS];	//그 시점에서의 거리 배열
        bool found[MAX_VTXS]; // 최단거리의 정점을 찾았는지 여부 확인

    public:
        WGraphDijkstra(){}
        ~WGraphDijkstra(){}

        void PrintDistance(){
            for(int i = 0; i<size; i++){
                std::cout << dist[i] << " ";//자신의 거리를 출력
            }
        }

        void PrintPath(int start, int end){//자신의 경로를 표현
            std::cout << "Shortest path " << getVertex(end) << "->" << getVertex(start) << ": ";
            std::cout << getVertex(end);//최단 거리를 보여줌
            while(path[end] != start){//첫 시작점 = end, 패스를 역으로 추적함, 소스의 처음에 정했던 씨드?부터 추적하는게 아니라 각 정점들부터 씨드까지의 path를 추적
                std::cout << "-" << getVertex(path[end]);//시작점이 나올 때까지 자기 앞의 노드들을 추적
                end = path[end];//출력하고 나면 자신은 빠짐, 
                //작동 원리: 어떤 노드를 거쳐서 최단경로가 만들어졌는지 path에 기록, 자신 직전 경로를 추적하다 소스 노드가 나오게 되면 그게 최단거리
            }
            //std::cout << "-" << getVertex(path[end]) << "\n";
            std::cout << "-" << getVertex(start) << "\n";
        }

        int chooseVertex(){//s를 확장해 줄 다음 노드를 구하는 작업
            // 이미 subgroup에서 최단거리리를 찾은 node group에서 
            // 가장 가까운 못찾은 node를 구합니다
            int min = INF;//초기에는 최소값을  무한대로 줘야함
            int minpos = -1;//거리가 최소인 노드의 index
            for(int i = 0; i < size; i++){
                if(dist[i]< min && !found[i]){//지금 이전까지의 거리가 지금까지 찾았던 가장 작은 거리보다 작고, 그리고 아직 이게 s그룹에 들어가 있지 않음(found가 s그룹에 들어가 있으면 true로 바뀜)
                    min = dist[i];
                    minpos = i;
                }
            }
            return minpos;
        }

        void ShortestPath(int start){
            for(int i = 0; i < size; i++){
                dist[i] = getEdge(start, i);//start부터의 거리
                path[i] = start;
                found[i] = false;//아직 못찾아서 falase
            }//이렇게 다 바꿔놓고 start를 바꾸는게 논리연산 보다 빠름
            found[start] = true;//start만 true		
            dist[start] = 0; // 시작점까지와의 거리는 0

            for(int i = 0; i < size; i++){
                std::cout << "STEP " << i+1 << " ";
                PrintDistance();//거리출력
                int u = chooseVertex();//최소거리vertex를 골라줌 
                // 최단경로를 모르는 노드 중 현재 발견된 노드에서 가장 가까운 노드를 뽑습니다.
                // negative weight가 없으므로 이렇게 뽑은 경로는 당연히 최단경로가 됩니다.
                found[u] = true;//노드를 찾았으니까 true로 바꿔줌 
                for(int w = 0; w < size; w++){//distance matrix를 업데이트 해줘야하니까 한번 더 루프를 돎
                    if(!found[w]){//아직 찾지 않은 노드일 때 
                        if(dist[u] + getEdge(u,w) < dist[w]){//이게 u라는 우리가 최소 거리 노드를 새로 추가하는 것을 새로 통과하는 경로의 거리 < 기존에 알고 있던 w까지의 거리
                            // 만약 최단거리를 아직 모르는 w에 대햇허
                            // u를 거치는 경로가 기존에 우리가 정해준 경로보다 짧다면
                            // (INF이거나, start부터의 weight이거나 둘 중 하나일 것입니다)
                            // 최단 경로를 u를 거치는 경로로 바꿔줍니다
                            // 다시한번 강조. negative weight가 있으면 작동 안합니다.
                            dist[w] = dist[u] + getEdge(u,w);//w의 거리가 u를 거치는 경로로 바뀜
                            path[w] = u;//w로 가는 path는 바로 앞의 u를 거치므로 u를 추가함
                        }
                    }
                }
                std::cout << "\n";
            }
        }
};
