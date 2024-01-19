#pragma once
#include "aLWGraph.hpp"
#include <ctime>

int main(void){

    clock_t start2 = clock();
    AdjListWGraph h2;
    h2.loadNames("bicycleFiles/station_names.txt");
    h2.loadDirLinks("bicycleFiles/bicycle_trips_all.txt");
    std::cout << "그래프를 불러왔습니다.\n";
    
    
    h2.randomWalker(1442, 100000, 0);
    
    h2.visitedPercent();
    
    clock_t end2 = clock();
    std::cout << "AdjListWGraph가 걸린시간 : " << difftime(end2, start2) / 1000.0 << " 초\n";

    //최대 최소 pagerank갖는 노드 찾기
    int j=0;
    for(int i=1;i<=h2.getSize();i++){
        if(h2.getVisited(j)<h2.getVisited(i)){
            j=i;
        }
    }
    std::cout << "the biggest pagerank = " << h2.getVertex(j) << ":" << h2.pageRank(j) << "\n";
    j=0;
    for(int i=1;i<=h2.getSize();i++){
        if(h2.getVisited(j)>h2.getVisited(i)&&h2.getVisited(i)!=0){
            j=i;
        }
    }
    std::cout << "the smallest pagerank = " << h2.getVertex(j) << ":" << h2.pageRank(j) << "\n";
    
    
    return 0;   
}