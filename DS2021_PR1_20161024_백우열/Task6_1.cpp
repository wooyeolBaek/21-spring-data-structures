#include "aMWGraph.hpp"
#include <ctime>

int main(void){
    
    // clock_t start = clock();
    AdjMatWGraph h1;
    
    h1.loadNames("starwarsFiles/starwars-full-interactions-allCharacters-nodes.txt");
    h1.loadLinks("starwarsFiles/starwars-full-interactions-allCharacters-links.txt");
    
    std::cout << "그래프를 불러왔습니다.\n";
    
    
    h1.randomWalker(0, 100000, 0);
    
    
    h1.visitedPercent();
    

    // clock_t end = clock();
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

    return 0;   
}