#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#define MAX_VTXS 256

//인접행렬 구현
class AdjMatGraph{
    protected:
        int size; //Graph의 사이즈,Vertex의 수
        std::string vertices[MAX_VTXS]; //MAX_VTX크기의 vertices 배열 정의, 값 = 각 Vertex의 이름(한 글자로)
        int adj[MAX_VTXS][MAX_VTXS]; // MAX_VTX크기의 edge 배열 정의, 값 = Adjacency matrix의 성분

    public:
        AdjMatGraph(){ reset(); }
        ~AdjMatGraph(){}

        std::string getVertex(int i){ return vertices[i]; } //vertex의 i번째 값 출력
        int getEdge(int i, int j){ return adj[i][j]; } //edge의 i,j 값 출력
        //i, j 사이에 edge가 있으면 1 없으면 0, 가중치 그래프에서도 쓰이니까 boolean으로 안하고 0,1로 함
        //가중치 그래프에서는 이 int의 값만 바꿔주면 됨, 사실 int가 아니고 float여도 됨
        void setEdge(int i, int j, int val){ adj[i][j] = val; }//edge의 i,j 값 = val로 정해줌
        bool isEmpty(){ return size == 0; }//return size == 0;
        bool isFull(){ return size>=MAX_VTXS; }//return size>=MAX_VTX;

        void reset(){ //그래프를 한번 싹 지움 
            size = 0;
            for(int i=0; i<MAX_VTXS; i++){
                for(int j=0; j<MAX_VTXS; j++){
                    setEdge(i,j,0); //모든 edge를 다 끊음
                }
            }
        }

        void insertVertex(std::string name){ //Vertex를 새로 넣음
            if(!isFull()){ vertices[size++] = name; } //vertices[size++] = name, vertex size+1자리에 name값 넣어줌
            else{ std::cout << "Exceeding maximum number of vertices";}
        }

        void insertEdge(int u, int v){ //edge를 새로 넣음, 가중치 넣으려면 parameter에 가중치도 포함
            if(u<0 || u>=size || v<0 && v>=size){
                std::cout << "out of range";
                exit(0);
            }
            setEdge(u, v, 1);
            setEdge(v, u, 1);
        }//방향이 없는 그래프이기 때문에 대칭 행렬로 양쪽 edge를 동시에 추가해 주어야함

        void display(){ //상태 확인, 
            std::cout << size << "\n"; //size 출력 
            for(int i=0; i<size; i++){
                std::cout << getVertex(i) << " ";//vertex 출력
                for(int j=0; j<size; j++){
                    std::cout << getEdge(i, j) << " ";//edge 출력
                }
                std::cout << "\n";
            }
        }

        void load(std::string filename){//파일:filename의 성분을 받아  graph를 만듦
            std::ifstream ifs(filename);//ifstream: ifs(filename) = filename 텍스트를 불러옴
            std::string line;//string의 line 정의
            std::getline(ifs, line); //getline: stream(ifs)에서 한줄 씩 텍스트를 받아 line에 저장
            std::cout << line << std::endl;
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
                    if(val != 0){
                        insertEdge(i,j);//val 값의 edge 저장
                    }
                }
            }
            ifs.close();//파일 닫기
        }
        
        void store(std::string filename){ //파일(filename)을 저장
            std::ofstream ofs(filename);//outstream: 파일의 outstream을 해줌, 파일을 열어줌
            ofs << size << "\n"; //화면 출력하던 std::cout 을 ofs로 바꿔줌, of << size << "\n";:파일에 저장할 텍스트값(size) 입력
            for(int i=0; i < size; i++){
                ofs << getVertex(i) << " ";//저장할 파일(filename)에 모든 vertex 값(이름)+" " 저장
                for(int j = 0; j < size; j++){
                    ofs << getEdge(i, j) << " ";//저장할 파일(filename)에 모든 edge 값(이름)+" " 저장
                }
                ofs << "\n";//저장할 파일(filename)에 개행문자 추가
            }
            ofs.close();//파일 닫기
        }
};