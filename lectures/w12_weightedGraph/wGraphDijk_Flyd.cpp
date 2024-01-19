#include "wGraphDijkstra.hpp"
#include "wGraphFloyd.hpp"

int main(void){
    WGraphDijkstra g1;//그래프 변수 만들기
    g1.load("graph_sp.txt");
    std::cout << "File loaded\n";
    g1.display();
    std::cout << "Shortest Path By Dijkstra Algorithm\n";//sp알고리즘으로 최단거리 찾는 것 명시
    g1.ShortestPath(0);//정점 0부터 시작하는 경로에 최단거리와 최단 경로를 모두 출력
    std::cout << "Finding completed\n";
    for(int i = 0; i < 7; i++){
        g1.PrintPath(0, i);
    }

    // for(int j = 0; j < 7; j++){
    //     g1.ShortestPath(j);
    //     std::cout << "Finding completed\n";
    //     for(int i = 0; i < 7; i++){
    //         g1.PrintPath(j, i);
    //     }
    // }
    

    WGraphFloyd g2; 
    g2.load("graph_sp.txt");
    g2.display();
    std::cout << "Shortest Path By Floyd Algorithm\n";
    g2.ShortestPathFloyd();
    for(int i = 0; i < 7; i++){
        g2.PrintPath(0, i);
    }


    //dijkstra와 floyd 비교, 정확히 같은 결과가 나옴, 최단경로가 unique하지 않기 때문에 결과가 다를 수도 있음
    /*
    for(int i=0; i<7; i++){
        g1.PrintPath(0,i);
        g2.PrintPath(i, 0);
    }*/
    

    
    
    return 0;
}