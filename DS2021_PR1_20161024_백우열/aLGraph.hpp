#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#define MAX_VTXS 100000

static std::mt19937 gen = std::mt19937((unsigned int)time(NULL)); 
static std::uniform_real_distribution<> dist(0,1);

class Node{//adjList를 위한 Node
    protected:
        int id;
        int wgt;
        Node* link;

    public:
        Node(int i, int w = 0, Node* l = nullptr) : id(i), wgt(w), link(l) {}
        ~Node(void){ delete link; }
        
        int getId(){ return id;}//node의 id 불러옴
        int getWgt(){ return wgt; }//node의 weight불러옴
        Node* getLink(){ return link; }//node의 다음 노드(링크) 불러옴
        void setLink(Node* l){ link = l; }//node의 다음 노드(링크) l로 정해줌
};

class AdjListGraph{
    protected:
        int size;//그래프의 크기
        std::string* vertices;//vertex의 이름
        int* verNum;//vertex의 고유 번호, 데이터 불러올 때 사용
        Node* adj[MAX_VTXS];//인접 리스트
        int* visited;//vertex방문 횟수, randomwalker에서 사용
        int* inDeg;//indegree 개수
        int* outDeg;// outdegree 개수   

    public:
        AdjListGraph(void) : size(0) {
            vertices = new std::string [MAX_VTXS];
            verNum = new int [MAX_VTXS];
            visited = new int [MAX_VTXS];
            inDeg = new int [MAX_VTXS];
            outDeg = new int [MAX_VTXS];
            reset();
        }
        ~AdjListGraph(void){ 
            for(int i=0; i<size; i++){
                delete adj[i];
            }
            delete [] vertices;
            delete [] verNum;
            delete [] visited;
            delete [] inDeg;
            delete [] outDeg;
        }

        void reset(void){
            for(int i=0; i<MAX_VTXS; i++){
                adj[i] = nullptr;
                visited[i]=0;
                inDeg[i] = 0;
                verNum[i] = 0;
            }
            size = 0;
        }

        bool isLinked(int u, int v){//u, v 사이에 링크가 존재하는지
            for(Node* p = adj[u]; p != nullptr; p=p->getLink()){
                if(p->getId()==v){ return true; }
            }
            return false;
        }

        bool isEmpty(){ return size==0; }//vertex의 개수가 0인지 확인

        bool isFull(){ return size==MAX_VTXS; }//vertex의 개수가 MAX_VTXS인지 확인

        std::string getVertex(int i){ return vertices[i]; }//i번째 vertex 이름 불러옴

        int getEdge(int i, int j){//i에서 j로의 간선의 가중치 불러옴
            Node* w = adj[i];
            while(w->getId()!=j || w!=nullptr){
                w = w->getLink();
            }
            return w->getWgt(); 
        }

        int getVisited(int i){ return visited[i]; }//i번째 vertex 방문 횟수 불러옴

        int getVerByNum(int i){//i의 고유 번호를 갖는 vertex가 몇 번째인지 불러옴
            for(int j=0; j<size; j++){
                if(verNum[j]==i){
                    return j;
                }
            }
        }

        int getSize(){ return size; }//vertex의 크기 불러옴

        void insertVertex(int id, std::string name){//vertex 추가
            if(!isFull()){
                verNum[size] = id;
                vertices[size] = name;
                adj[size] = nullptr;
                inDeg[size] = 0;
                outDeg[size] = 0;
                visited[size] = 0;
                size++;
            }
            else{ std::cout << "Exceeding maximum number of vertices. \n"; }
        }

        void insertEdge(int u, int v, int w=1){//u에서 v로의 가중치가 w인 간선 추가
            if(adj[u]==nullptr){
                adj[u]=new Node(v, w, nullptr);
            }
            else{
                Node* p = adj[u];
                while(p->getLink()!=nullptr){
                    p = p->getLink();
                }
                p->setLink(new Node(v, w, nullptr));
            }
            outDeg[u]++;
            inDeg[v]++;
        }

        void display(){//vertex : 간선이 존재하는 vertices 모두 출력
            std::cout << size << "\n";
            for(int i=0; i<size; i++){
                std::cout << getVertex(i) << " : ";
                for(Node* v=adj[i]; v!=nullptr; v=v->getLink()){
                    std::cout << getVertex(v->getId()) << " ";
                }
                std::cout << "\n";
            }
        }

        void loadNames(std::string filename){//데이터 파일에서 vertices 이름 불러옴
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            std::stringstream ls(line);
            while(!ifs.eof()){
                std::getline(ifs, line);
                int id;
                std::string name;
                std::string name1;
                std::stringstream ls(line);
                ls >> id;
                while(!ls.eof()){
                    ls >> name1;
                    name += " ";
                    name += name1;
                }
                insertVertex(id, name);
                }
            ifs.close();
        }

        void loadLinks(std::string filename){//데이터 파일에서 vertices 방향이 없는 링크 불러옴
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            std::stringstream ls(line);
            while(!ifs.eof()){
                std::getline(ifs, line);
                int src;
                int tar;
                int wgt;
                std::stringstream ls(line);
                ls >> src;
                ls >> tar;
                ls >> wgt;
                insertEdge(getVerByNum(src), getVerByNum(tar));
                insertEdge(getVerByNum(tar), getVerByNum(src));
            }    
            ifs.close();
        }

        void loadDirLinks(std::string filename){//데이터 파일에서 vertices 방향이 있는 링크 불러옴
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            std::stringstream ls(line);
            while(!ifs.eof()){
                std::getline(ifs, line);
                int src;
                int tar;
                int wgt;
                std::stringstream ls(line);
                ls >> src;
                ls >> tar;
                ls >> wgt;
                insertEdge(getVerByNum(src), getVerByNum(tar));
            }    
            ifs.close();
        }

        void store(std::string filename){
            std::ofstream ofs(filename);
            ofs << size << "\n";
            for(int i=0; i < size; i++){
                ofs << getVertex(i) << " ";
                for(int j = 0; j < size; j++){
                    ofs << getEdge(i, j) << " ";
                }
                ofs << "\n";
            }
            ofs.close();
        }

        void randomWalker(int i, int n, float q){//randomwalker, i는 시작 노드, n은 이동 회수, q는 jump할 확률(0~1)
            //std::cout << "start:" << getVertex(i) << " -> ";
            visited[i];//시작 vertex 방문 
            while((n-1)!=0){
                if(q>dist(gen) || outDeg[i]==0){//jump하는 경우, q 확률보다 작거나, outDeg가 없는 경우
                    int j;
                    j= (int)(dist(gen)*(size-1))+1;//adj 배열이 0~size-1자리까지 vertex가 존재, 따라서 0~size-1까지의 숫자를 임의로 뽑음
                    i = (i+j)%size;//자기 자신으로 jump하는 경우는 빼기 위해 i+j를 size로 나눠줌
                    //std::cout << "jump:" << getVertex(i) << " -> \n"; 
                }
                else{
                    int p = (int)(dist(gen)*outDeg[i])+1;//0~outDeg사이의 수를 임의로 뽑음
                    Node* w=adj[i];
                    while(w->getLink()!=nullptr && p!=0){//p번 만큼 adj의 node들을 이동, 이동할 때 마다 p를 하나씩 줄여서 p번 째 node에 멈춤
                        w = w->getLink();
                        p--;
                    }
                    i = w->getId();//선택된 node의 id로 이동
                    //std::cout << "move:" << getVertex(i) << " -> \n";
                }
                visited[i]++;
                n--;
                }
                //std::cout << "end\n";
        }

        float pageRank(int i){
            int sum = 0;//전체 node들의 방문 횟수의 합
            for(int j=0; j<size; j++){
                    //std::cout << getVertex(j) << ":" << visited[j] << " ";
                    sum = sum + visited[j];
            }
            float tmp = visited[i];//i의 방문 횟수
            return tmp/sum;
        }

        int visitedVertices(){//방문한 vertecis의 개수 출력
            int num = 0;
            for(int i=0; i<size; i++){
                if(visited[i]!=0){
                    num++;
                }
            }
            return num;
        }

        void visitedPercent(){//몇 %의 vertices를 방문했는지
            std::cout << 100*visitedVertices()/getSize() << "% vertices have been visited." << "\n";
        }

};