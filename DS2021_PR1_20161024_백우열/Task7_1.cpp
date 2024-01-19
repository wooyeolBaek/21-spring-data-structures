#pragma once
#include "aMWGraph.hpp"
#include <ctime>

int main(void){
    
    clock_t start1 = clock();
    AdjMatWGraph h1;
    h1.loadNames("bicycleFiles/station_names.txt");
    h1.loadDirLinks("bicycleFiles/bicycle_trips_all.txt");
    std::cout << "그래프를 불러왔습니다.\n";
    
    
    h1.randomWalker(1442, 100000, 0);
    
    h1.visitedPercent();
    
    clock_t end1 = clock();
    std::cout << "AdjMatWGraph가 걸린시간 : " << difftime(end1, start1) / 1000.0 << " 초\n";


    //최대 최소 pagerank갖는 노드 찾기
    int j=0;
    for(int i=1;i<=h1.getSize();i++){
        if(h1.getVisited(j)<h1.getVisited(i)){
            j=i;
        }
    }
    std::cout << "the biggest pagerank = " << h1.getVertex(j) << ":" << h1.pageRank(j) << "\n";
    j=0;
    for(int i=1;i<=h1.getSize();i++){
        if(h1.getVisited(j)>h1.getVisited(i)&&h1.getVisited(i)!=0){
            j=i;
        }
    }
    std::cout << "the smallest pagerank = " << h1.getVertex(j) << ":" << h1.pageRank(j) << "\n";

    return 0;   
}