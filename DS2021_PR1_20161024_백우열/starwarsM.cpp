#include "aMGraph.hpp"
#include "aMWGraph.hpp"
#include <ctime>

int main(void){
    
    clock_t start = clock();
    AdjMatGraph h1;
    AdjMatWGraph h2;
    h1.loadNames("starwarsFiles/starwars-full-interactions-allCharacters-nodes.txt");
    h1.loadLinks("starwarsFiles/starwars-full-interactions-allCharacters-links.txt");
    h2.loadNames("starwarsFiles/starwars-full-interactions-allCharacters-nodes.txt");
    h2.loadLinks("starwarsFiles/starwars-full-interactions-allCharacters-links.txt");
    std::cout << "그래프를 불러왔습니다.\n";
    std::cout << h1.getVertex(0) << "\n";
    std::cout << h2.getVertex(0) << "\n";
    
    h1.randomWalker(0, 100000, 0);
    h2.randomWalker(0, 100000, 0);
    
    h1.visitedPercent();
    h2.visitedPercent();

    clock_t end = clock();
    std::cout << difftime(end, start) / 1000.0 << " 초\n";

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

    j=0;
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

    //h1.findPath(0,3);

    //실험 내용: 허브 노드 찾기, ANAKIN, LUKE
    //실험 내용: 어떤 역에서 어떤 역까지 자전거가 많이 지나간 곳
    //실험 내용: 어떤 역에서 어떤 역까지 루프가 존재하는 지
    
    return 0;   
}