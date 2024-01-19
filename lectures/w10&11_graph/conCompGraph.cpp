#include <iostream>
#include "conCompGraph.hpp"

int main(void){
    ConnectedComponentGraph g;

    //ppt그림의 구조 구현함 
    for(int i=0; i<5; i++){
        g.insertVertex(std::string(1,'A'+i));//vertex 만들어줌 
    }
    g.insertEdge(1, 0);
    g.insertEdge(2, 0);
    g.insertEdge(3, 4);
    g.store("graph3.txt");
    std::cout << "Connected Component Test";
    g.display();
    g.resetVisited();
    g.findConnectedComponent();

    return 0;
}