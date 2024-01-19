#include "aMGraph.hpp"
#include <ctime>

int main(void){
    
    //clock_t start = clock();
    AdjMatGraph h1;
    h1.loadNames("bicycleFiles/station_names.txt");
    h1.loadDirLinks("bicycleFiles/bicycle_trips_all.txt");
    std::cout << "그래프를 불러왔습니다.\n";
    
    
    h1.randomWalker(1463, 100000, 0);
    
    h1.visitedPercent();
    
    //clock_t end = clock();
    // std::cout << difftime(end, start) / 1000.0 << " 초\n";

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

    
    //실험 내용: 허브 노드 찾기, 망원역 1번 출구 앞
    //실험 내용: 어떤 역에서 어떤 역까지 자전거가 적게 지나간 곳
    //실험 내용: 어떤 역에서 어떤 역까지 루프가 존재하는 지
    //실험 내용: 인접행렬 vs 인접리스트 중 뭐가 빠른지
    
    return 0;   
}