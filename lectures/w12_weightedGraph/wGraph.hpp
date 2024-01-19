#include "adjMatGraph.hpp"
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#define INF 9999//최대 가중치, INF 이상의 가중치는 무한대로 생각

class WGraph : public AdjMatGraph{
    public:
        WGraph(){}
        ~WGraph(){}

        bool hasEdge(int i, int j){ return (getEdge(i, j) < INF); }//i, j의 가중치가 INF보다 작은경우 반환

        void insertEdge(int u, int v, int wgt){
            if(wgt >= INF){ wgt = INF; }//edge가 없는 경우
            setEdge(u, v, wgt);
        }

        void load(std::string filename){//파일:filename의 성분을 받아  graph를 만듦
            std::cout << filename << std::endl;
            std::ifstream ifs(filename);//ifstream: ifs(filename) = filename 텍스트를 불러옴
            std::string line;//string의 line 정의
            std::getline(ifs, line); //getline: stream(ifs)에서 한줄 씩 텍스트를 받아 line에 저장
            std::cout << line << "\n";
            std::stringstream ls(line); //stringstream: stream으로 string을 바꿔줌, 즉 텍스트를 스트림단위(공백단위)로 받아 ls에 저장
            //예를 들면, cout 같은 것들은 출력을 stream 형태로 함 
            //stream 단위는 데이터를 끊어서 주고 받을 수 있음, 여기선 공백단위로 끊음
            int n;
            ls >> n;//공백단위로 끊은 값 n에 저장
            for(int i=0; i<n; i++){
                std::getline(ifs, line);//한 줄 받아 line에 저장
                std::string str;//vertices의 이름 넣
                int val;
                std::stringstream ls(line);//한 공백단위 텍스트 받아옴
                ls >> str;//공백단위 텍스트 str에 저장
                insertVertex(str);//str이름의 vertex 저장
                for(int j=0; j<n; j++){
                    ls >> val;//다음 공백단위 텍스트 val에 저장
                    insertEdge(i, j, val);//val 값의 edge 저장
                }
            }
            ifs.close();//파일 닫기
        }

};