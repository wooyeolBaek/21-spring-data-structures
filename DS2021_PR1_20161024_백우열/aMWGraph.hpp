#pragma once
#include "aMGraph.hpp"
#define MAX_VTXS 10000


class AdjMatWGraph : public AdjMatGraph{
    
    public:
        AdjMatWGraph(){}
        ~AdjMatWGraph(){}

        
        bool hasEdge(int i, int j){ return (getEdge(i, j)!=0); }//i, j의 가중치가 INF보다 작은경우 반환

        bool isLinked(int u, int v){
            if(adj[u][v]==0 && adj[v][u]==0){ 
                return false; 
            }
            return true;
        }

        void insertVertex(int id, std::string name){
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
        
        void loadLinks(std::string filename){
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
                insertEdge(getVerByNum(src), getVerByNum(tar), wgt);
                insertEdge(getVerByNum(tar), getVerByNum(src), wgt);
            }    
            ifs.close();
        }

        void loadDirLinks(std::string filename){
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
                insertEdge(getVerByNum(src), getVerByNum(tar),wgt);
            }    
            ifs.close();
        }

        void loadDirLinksNotSelf(std::string filename){
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
                    insertEdge(getVerByNum(src), getVerByNum(tar),wgt);
                }
            }    
            ifs.close();
        }

        void randomWalker(int i, int n, float q){
            // std::cout << "start:" << getVertex(i) << " -> \n";
            visited[i];
            while((n-1)!=0){
                if(q>dist(gen) || outDeg[i]==0){
                    int j;
                    j= (int)(dist(gen)*(size-1))+1;//0~7,size=8 => 0~6 => 1~7
                    i = (i+j)%size;
                    // std::cout << i << "jump:" << getVertex(i) << " -> \n"; 
                }
                else{
                    int sum=0;
                    Node* w=adjL[i];
                    for(Node* u=adjL[i]; u!=nullptr; u=u->getLink()){
                        sum+=u->getWgt();
                    }
                    int p = (int)(dist(gen)*sum);
                    while(w->getLink()!=nullptr && p>0){
                        w = w->getLink();
                        p-=w->getWgt();
                    }
                    i = w->getId();
                    // std::cout << "move:" << getVertex(i) << "->\n";
                }
                visited[i]++;
                n--;
                }
                // std::cout << "end\n";
        }
};