#pragma once
#include "wGraph.hpp"

class WGraphFloyd : public WGraph{
    protected:
        int	A[MAX_VTXS][MAX_VTXS];//최단경로 거리 matrix
        int path[MAX_VTXS][MAX_VTXS];//경로 기록 matrix

    public:
        void ShortestPathFloyd(){ //Floyd에 대해 최단거리를 구해줌
            for(int i = 0; i < size; i++){//초기화먼저 해줌
                for(int j = 0; j < size; j++){
                    A[i][j] = getEdge(i, j);//A의 i,j성분=i,j의 가중치
                    path[i][j] = j;//일단 모든 path는 destination을 거쳐간다고 생각해서 j로 둠
                }
            }

            for(int k = 0; k < size; k++){
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size ; j++){
                        if (A[i][k] + A[k][j] < A[i][j]){
                            A[i][j] = A[i][k] + A[k][j];//기존의 A의 i,j값을 i,k와 k,j의 합으로 바꿔줌
                            path[i][j] = path[i][k];//i,j의 path를 i,k path로 바꿈
                        }
                    }
                }
                printA();//중간과정 확인용
            }
        }

        void PrintPath(int start, int end){//시작점부터 종료점까지의 path 출력
            std::cout << "Shortest path " << getVertex(start) << "->" << getVertex(end) << ": ";
            //start부터 시작
            std::cout << getVertex(start);
            while(path[start][end] != end){//path의 start부터 end로 가는게 진짜 종료점이 아닌 경우
                std::cout << "-" << getVertex(path[start][end]);//path의 start란 점을 계속 바꿔줌 
                start = path[start][end];
            }
            std::cout << "-" << getVertex(end) << "\n";
        }

        void printA(){//A출력, 원리: path matrix에 자기가 거쳐온 길들을 기록해 논 것을 start를 한자리씩 옮겨가면서 자기 뒤에 것을 계속 따라가서 출력해줌 
            std::cout << "Shortest path length matrix\n";
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(A[i][j] == INF){//거리가 무한대이면 INF출력
                        std::cout << "INF ";
                    }
                    else{//거리 출력
                        std::cout << A[i][j] << " ";
                    }
                }
                std::cout << "\n";
            }
        }
};