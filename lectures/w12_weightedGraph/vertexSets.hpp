#include "wGraph.hpp"
#pragma once

//정점 집합들을 관리하는 클래스.
class VertexSets{//연결선을 만드는데 이게 사이클을 만드는지 아닌지 확인하는 방식?
    protected:
        int parent[MAX_VTXS];
        int size;
    public:
        VertexSets(int nSets){
            size = nSets;
            for(int i=0; i<nSets; i++){
                parent[i] = -1;//이 node가 root(set의 대표 node)라는 것을 표시하기 위해 -1로 설정, 초기에는 연결된 노드들이 없어서 모든 노드가 다 루트
            }//-1이 아닌 다른 값이 있으면 자신의 parent를 가지는 거
        }

        bool isRoot(int i){//root인지 검사, 부모가 -1(음수)이면 root node임
            return parent[i] < 0;
        }

        int findSet(int vertex){//주어진 node의 루트(set의 대표노드)를 찾음
            int id = vertex;
            while(!isRoot(id)){//root가 나올 떄까지 id를 parent[id]에 넣어줌
                id = parent[id];//자신의 parent를 따라가다가 root가 나오면 그 root에 멈춤
            }
            return id;
        }

        void unionSets(int s1, int s2){//주어진 두 s1, s2를 합침, root node로 주어짐
        //s2 node의 parent를 s1을 만들어줌 => 쭉 따라가다가 s1의 진짜 parent root까지 감 => 같은 그룹에 있는지 확인 할 수 있음, 간선을 만들어줌
            parent[s1] = s2;//s1의 root node 를 s2로 정의
            size--;//set이 하나 줄어듦, size==set의 숫자, 초기의 size==전체 node수 
        }

};