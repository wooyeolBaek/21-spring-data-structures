#pragma once
#include <iostream>
#include "adjMatGraph.hpp"
#include "srchAMGraph.hpp"

class ConnectedComponentGraph : public SrchAMGraph{
    protected:
        //visited, label 2가지의 array로 구현
        int label[MAX_VTXS]; //어떤 연결성분이 속하는지 정해주는 MAX_VTXS

    public:
        void labelDFS(int v, int color){//label을 정해주는 함수, 이거는 BFS로 해도 정답을 찾을 수 있음
            visited[v] = true;
            label[v] = color;//color는 색깔처럼 생각할 수 있기 때문에 color라고 이름 붙임
            std::cout << getVertex(v) << " ";
            for(int w = 0; w<size; w++){//모든 노드에 대해서
                if(isLinked(v, w) && visited[w]==false){ //v와 w가 이웃하고 있고, 아직 w를 방문하지 않았을 때
                    labelDFS(w, color);//BFS와 같은데 차이점은 탐색할 때마다 색깔도 같이 변경해준다는 것 하나임 
                }
            }
        }

        void findConnectedComponent(){//connectedcomponent를 찾는 함수
            int count = 0;//color를 바꿔주는 count변수를 만듦 
            for(int i = 0; i<size; i++){//전체의 vertex들에 대해서 
                if(visited[i]==false){
                    labelDFS(i, ++count);//labelDFS할 때마다 많은 노드들이 visited가 true로 바뀜
                    //첫 번째 labelDFS에서 count가 0인 color를 갖지 못한 애들은 아직까지도 visited가 false로 되어있음
                }//그래서 두번째로 등장하는 애들은 이제 1이라는 값을 가지고 labelDFS을 또 돈다.
                //이런 식으로 전체가 탐색될 때까지 labelDFS를 돌게 됨 
            }
            std::cout << "\nNumber of Connected Components: " << count << "\n";//이제 찾았으니까 출력을 해줌
            for(int i=0; i<size; i++){//모든 vertex들에 대해서 
                std::cout << getVertex(i) << ":" << label[i] << " "; //각각의 label를 출력시켜봄 
            }
            std::cout << "\n";
        }
};