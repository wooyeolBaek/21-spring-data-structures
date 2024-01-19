#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#define MAX_VTXS 10000

static std::mt19937 gen = std::mt19937((unsigned int)time(NULL)); 
static std::uniform_real_distribution<> dist(0,1);

class Node{//randonwalker에서 사용할 node
    protected:
        int id;
        int wgt;
        Node* link;

    public:
        Node(int i, int w = 0, Node* l = nullptr) : id(i), wgt(w), link(l) {}
        ~Node(void){ delete link; }
        
        int getId(){ return id;}
        int getWgt(){ return wgt; }
        Node* getLink(){ return link; }
        void setLink(Node* l){ link = l; }
};


class AdjMatGraph{
    protected:
        int size;//그래프 크기
        std::string* vertices;//vertex 이름
        int* verNum;//vertex의 고유 번호
        int** adj;//adjmatrix 성분 값
        int* visited;//vertex 방문 횟수, randomwalker에서 사용
        int* inDeg;//indegree 개수
        int* outDeg;//outdegree 개수
        Node** adjL;//vertex에 연결된 간선 조회시 사용
        

    public:
        AdjMatGraph(){ 
            vertices = new std::string [MAX_VTXS];
            verNum = new int [MAX_VTXS];
            adj = new int* [MAX_VTXS];
            visited = new int [MAX_VTXS];
            inDeg = new int [MAX_VTXS];
            outDeg = new int [MAX_VTXS]; 
            for(int i=0; i<MAX_VTXS; i++){
                adj[i] = new int[MAX_VTXS];
            }
            adjL = new Node* [MAX_VTXS];//added
            size = 0;
            for(int i=0; i<MAX_VTXS; i++){
                adjL[i] = nullptr;
            }
            size = 0;
        }

        ~AdjMatGraph(){
            delete [] vertices;
            delete [] verNum;
            for(int i=0; i<MAX_VTXS; i++){
                delete [] adj[i];
            }
            delete [] adj;
            delete [] visited;
            delete [] inDeg;
            delete [] outDeg;
            delete [] adjL;
            size=0;
        }

        std::string getVertex(int i){ return vertices[i]; } //vertex의 i번째 값 출력

        int getEdge(int i, int j){ return adj[i][j]; } //edge의 i,j 값 출력

        int getSize(){ return size; }//vertices size불러옴

        int getVisited(int i){ return visited[i]; }//i번째 vertex 방문 횟수 불러옴

        int getVerByNum(int i){//i의 고유번호를 갖는 vertex가 몇 번째인지 불러옴
            for(int j=0; j<size; j++){
                if(verNum[j]==i){
                    return j;
                }
            }
        }
        
        void setEdge(int i, int j, int val){ adj[i][j] = val; }//edge의 i,j 값 = val로 정해줌
        
        bool isEmpty(){ return size == 0; }//vertex의 개수가 0인지 확인
        
        bool isFull(){ return size>=MAX_VTXS; }//vertex의 개수가 MAX_VTXS인지 확인

        bool isLinked(int u, int v){//u, v사이에 링크가 존재하는지
            if(adj[u][v]==0 && adj[v][u]==0){ 
                return false; 
            }
            return true;
        }

        void insertVertex(int id, std::string name){//vertex 추가
            if(!isFull()){
                verNum[size] = id;
                vertices[size] = name;
                for(int i=0;i<=size;i++){
                    adj[size][i] = 0;
                    adj[i][size] = 0;
                }
                inDeg[size] = 0;
                outDeg[size] = 0;
                visited[size] = 0;
                size++;
            }
            else{ std::cout << "Exceeding maximum number of vertices. \n"; }
        }

        void insertEdge(int u, int v, int w=1){//u에서 v로의 가중치가 w인 간선 추가
            if(u<0 || u>=size || v<0 || v>=size){
                std::cout << "out of range";
                exit(0);
            }
            else if(adjL[u]==nullptr){
                adjL[u]=new Node(v, w, nullptr);
            }
            else{
                Node* p = adjL[u];
                while(p->getLink()!=nullptr){
                    p = p->getLink();
                }
                p->setLink(new Node(v, w, nullptr));
            }
            setEdge(u, v, w);
            outDeg[u]++;
            inDeg[v]++;
        }

        void display(){//vertex : 간선이 존재하는 vertices 모두 출력
            std::cout << size << "\n"; //size 출력 
            for(int i=0; i<size; i++){
                std::cout << getVertex(i) << " ";//vertex 출력
                for(int j=0; j<size; j++){
                    std::cout << getEdge(i, j) << " ";//edge 출력
                }
                std::cout << "\n";
            }
        }

        void loadNames(std::string filename){//데이터 파일에서 vertices의 이름 불러옴
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
                // std::cout << "id:" << id << " name:" << name << " \n";
            }
            ifs.close();
        }
        
        void loadLinks(std::string filename){//데이터 파일에서 vertices의 방향이 없는 링크 불러옴
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

        void loadDirLinks(std::string filename){//데이터 파일에서 vertices의 방량이 있는 링크 불러옴
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

        void loadDirLinksNotSelf(std::string filename){//데이터 파일에서 vertices의 방량이 있는 링크 불러옴, 자신으로 가는 링크 제외
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
                if(src!=tar){
                    insertEdge(getVerByNum(src), getVerByNum(tar));
                }
            }    
            ifs.close();
        }

        //task 1
        void randomWalker(int i, int n, float q){//randomwalker, i는 시작 노드, n은 이동 회수, q는 jump할 확률(0~1)
            // std::cout << "start:" << getVertex(i) << " -> \n";
            visited[i]++;//시작 vertex 방문 
            while((n-1)!=0){
                if(q>dist(gen) || outDeg[i]==0){//jump하는 경우, q 확률보다 작거나, outDeg가 없는 경우
                    int j;
                    j= (int)(dist(gen)*(size-1))+1;//adj 배열이 0~size-1자리까지 vertex가 존재, 따라서 0~size-1까지의 숫자를 임의로 뽑음
                    i = (i+j)%size;//자기 자신으로 jump하는 경우는 빼기 위해 i+j를 size로 나눠줌
                    // std::cout << "jump:" << getVertex(i) << " -> \n"; 
                }
                else{
                    int p = (int)(dist(gen)*outDeg[i])+1;//0~outDeg사이의 수를 임의로 뽑음
                    Node* w=adjL[i];
                    while(w->getLink()!=nullptr && p!=0){//p번 만큼 adj의 node들을 이동, 이동할 때 마다 p를 하나씩 줄여서 p번 째 node에 멈춤
                        w = w->getLink();
                        p--;
                    }
                    i = w->getId();//선택된 node의 id로 이동
                    // std::cout << "move:" << getVertex(i) << " -> \n";
                }
                visited[i]++;
                n--;
                }
                // std::cout << "end\n";
        }

        void moveTO(int i, int j){//vertex i에서 j로 이동할 때 지나가는 vertices수 와 그 가중치 합을 구하는 함수
            std::cout << "start:" << getVertex(i) << " -> \n";
            visited[i]++;
            int n=0;//지나는 vertices 수
            int sum=0;//지나는 간선들의 가중치 합
            std::cout << getVertex(i) << " to " << getVertex(j) << ": ";
            while(i!=j){//j에 도착할 때까지 이동
                if(outDeg[i]==0){//이동할 node가 없는 경우
                    std::cout << i << "there is no way out.\n";
                    exit(0);
                }
                else{
                    int p = (int)(dist(gen)*outDeg[i])+1;//outdeg보다 작은 임의의 수를 뽑아서
                    Node* w=adjL[i];
                    while(w->getLink()!=nullptr && p!=0){
                        w = w->getLink();
                        p--;
                    }
                    i = w->getId();
                    n++;
                    sum+=w->getWgt();
                    visited[i]++;
                }
            }
            std::cout << " moved:" << n << ", traffic: "<< sum << "\n";
        }

        //task 2.
        float pageRank(int i){//i번쨰 vertex의 pagerank
            int sum = 0;
            for(int j=0; j<size; j++){
                    sum = sum + visited[j];
            }
            float tmp = visited[i];
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