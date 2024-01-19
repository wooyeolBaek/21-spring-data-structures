#include <iostream>
#include "srchAMGraph.hpp"

int main(void){
    SrchAMGraph g;
    g.load("graph2.txt");
    std::cout << "그래프를 불러왔습니다. \n";
    g.display();//잘 불러왔는지 확인

    std::cout << "DFS ==> ";
    g.resetVisited();//탐색 전 모두 방문 안 한 것으로 리셋
    g.DFS(0);//처음 시작 0번째부터, 깊이우선 탐색
    std::cout << "\n";

    std::cout << "BFS ==> ";
    g.resetVisited();//탐색 전 모두 방문 안 한 것으로 리셋
    g.BFS(0);//처음 시작 0번째부터, 너비우선 탐색 
    std::cout << "\n";

    return 0;
}