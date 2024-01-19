#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "adjMatGraph.hpp"
#include "adjListGraph.hpp"

int main(void){
    AdjListGraph g;
    g.load("graph.txt");//아까 만든 그래프파일 불러오기
    g.display();


    return 0;
}