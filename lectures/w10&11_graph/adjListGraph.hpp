#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "adjMatGraph.hpp"
#define MAX_VTXS 256 //vertices 최대수 정의

class Node{//인접리스트를 위한 Node 클래스, 모든 정점들 마다 리스트를 가지는데 그 리스트들의 연결리스크에 사용될 Node, vertex[i]: vertex[p]->vertex[q]->...
    protected:
        int id; //Vertex의 id
        Node* link; //이웃 Node의 포인터
    public:
        Node(int i, Node* l = nullptr) : id(i), link(l) {}//생성자는 nullptr를 기본으로 갖거나 입력받은 링크로 값을 만들어 줌 
        ~Node(void){//소멸장는 link를 다 지움
            if(link != nullptr){
                delete link;
            }
        }
        int getId(){ return id; }//Node의 id를 반환, Node=id(vertex)+link(Node)구조
        Node* getLink(){ return link; }//Node의 link가 가리키는 Node 반환
        void setLink(Node* l){ link = l; }//Node의 link가 가리키는 Node를 l로 정해줌
};

class AdjListGraph{
    protected:
        int size; //Vertex의 총 수
        std::string vertices[MAX_VTXS]; //MAX_VTXS크기의 vertices배열 정의, 값=vertex의 이름, Vertex의 정보 (Node 등으로 확장이 가능)
        Node* adj[MAX_VTXS]; //각 Vertex의 인접 리스트, MAX_VTXS크기의 adj배열 정의, 값 = Node(A에 연결된 vertex), 
        //adj[i]=vertex[i]의 포인터(링크), vertex[i]의 연결된 vertices들은 adj[i]를 따라 가야 찾을 수 있음
    public:
        AdjListGraph(void): size(0){}
        ~AdjListGraph(void){ reset();}

        std::string getVertex(int i){ return vertices[i]; } //i번째 vertix를 가져옴
        
        bool isEmpty(){ return size == 0; }
        bool isFull(){ return size>=MAX_VTXS; }

        void reset(void){
        //MAX_VTXS는 비효율적, 할당은 해놨지만 실제로 데이터가 안들어간 부분들은 리스트 길이가 가변적이기 때문에 값이 없으므로 메모리 할당이 안돼있음
            for(int i=0; i<size; i++){
                delete adj[i];//각각의 node가 가지고 있는 인접 리스트를 지움
            }
            size=0;
        }

        void insertVertex(std::string name){
            if(!isFull()){
                vertices[size] = name;//size번째 vertex를 name값으로 정해줌
                adj[size++] = nullptr;//size++번째 vertex는 없으니까 adj[size++]=nullptr, 왜냐하면 adj[u]==nullptr로 vertives[size-1]정의할때 같이 정의했기 때문
            }
            else{ std::cout << "Exceeding maximum number of vertices"; }
        }

        void insertEdge(int u, int v){
            //adj[u] = new Node(v, adj[u]);
            //이런 식으로 하면되는데 이미 graph.txt의 행렬이 대칭이니까 굳이 이렇게 할 필요 없음
            //만약 Adj Matrix와 같은 순서로 만들고 싶으면
            if(adj[u] == nullptr){//vertex[u]에 연결된 vertex들이 없을 때
                adj[u] = new Node(v, adj[u]);//id=v리스트에 Node=l를 가리키는 링크
            }//새로 생기는 edge들이 앞으로 붙음 
            else{
                Node* p = adj[u]; //어떤 node p를 정해주고, node 끝까지 탐색함
                while(p->getLink() != nullptr){//adj[u]의 포인터가 nullptr가 나오는 끝까지 이동
                    p = p->getLink();
                }
                p->setLink(new Node(v, nullptr)); //맨 뒤 Node, p 뒤에 Node, v 추가하고 포인터는 nullptr
            }
            //adj[v] = new Node(u, adj[v]);
        }

        void display(){//인접행렬 출력
            std::cout << size << "\n";//일단 사이즈 출력
            for(int i=0; i<size; i++){
                std::cout << getVertex(i) << " ";//vertex 출력
                for(Node* v = adj[i]; v != nullptr; v=v->getLink()){ //adj[i]의 Node들 모두 출력
                //첫 번째 node에서 시작해서 nullptr가 나오기 전까지 링크를 따라가면서 순회
                    std::cout << getVertex(v->getId()) << " "; //Node(v)안에 id(vertex)를 가져옴(몇번째 vertex인지)
                    //몇 번째 vertex인지 나오게 하면됨, 자기 id에 해당하는 vertex를 불러서 정보를 가져옴?
                }
                std::cout << "\n";
            }
        }

        void load(std::string filename){
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            std::cout << line << std::endl;
            std::stringstream ls(line);
            int n;
            ls >> n;
            for(int i=0; i<n; i++){
                std::getline(ifs, line);
                std::string str;
                std::stringstream ls(line);
                int n;
                ls >> n;
                for(int i=0; i<n; i++){
                    std::getline(ifs, line);
                    std::string str;
                    int val;
                    std::stringstream ls(line);
                    ls >> str;
                    insertVertex(str);
                    for(int j=0; j<n; j++){
                        ls >> val;
                        if(val != 0){
                            insertEdge(i, j);
                        }
                    }
                }
            }
            ifs.close();
        }
    
};
