#include <iostream>
#include <string>
#include "adjMatGraph.hpp"

//인접행렬 실행
int main(void){
    AdjMatGraph g;
    for(int i=0; i<4; i++){
        g.insertVertex(std::string(1, 'A'+i));//A,B,..이름의 vertex 정의, size는 4
    }//'A'는 A아스키 코드, 여기에 1씩 더해주면 'B', 'C'의 아스키 코드가 나옴
    //string()으로 그 아스키 코드를 string 으로 변환 
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    g.display();
    g.store("graph.txt");//g를 저 파일명으로 저장, 같은 폴더안에 graph.txt가 생김
    std::cout << "Graph saved \n";
    g.reset();//edge다 끊기
    std::cout << "Graph reset \n";
    g.display();
    g.load("graph.txt");//파일 불러오기
    std::cout << "Graph loaded \n";
    g.display();
}