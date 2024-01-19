#pragma once
#include <string>
#include <iostream>
#include <fstream>


inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};

class line{
    protected:
        std::string data;
    public:
        line(std::string line = ""){ data = line;}//생성자

        void read(std::istream *is = &std::cin){ //데이터 읽기
        //객체를 istream의 어떤 포인터 *is를 받게함
        //입력이 안돼있을 경우 표준입력 받기
            std::getline(*is,data);
        }
        void display(std::ostream *os = &std::cout){ //데이터 출력
        //똑같은데 inputstream이 아니라 outputstream
        // 이렇게 스트림에 계속 출력하주는 것 만듦
            *os << data << "\n";
        }
        bool hasData(std::string str){ //이 데이터가 우리가 입력한 데이터와 같은 지 확인 
        //어떤 string을 받아서 같은지 확인 
            return str == data;
        }
};
// 다른 식으로 singly linked list를 구현
// linkedlist로 리스트 구현
class node: public line{ 
// node는 이제 int의 node가 아니라 line의 node 따라서 line을 상속함
    private:
        node* next; //다음번 노드를 포인트하는 next라는 포인터

    public:
        node(std::string str = ""): line(str){//노드 생성자
            next = nullptr;
        }

    //node class의 연산
        node* getLink(){return next;} //다음번 노드를 가리키는 포인터를 반환 
        std::string getData(){return data;} //노드 데이터 리턴 
        void setLink(node* target){next = target;} 
        //노드의 포인터를 하나 받아서 받은 노드의 포인터와 next노드의 포인터가 같아지게 함

        void insertNext(node* newnode){ //삽입연산
            if(newnode != nullptr){
                newnode->next = next; //A->B->C에서 newnode->C과정
                next = newnode; //A->B->C에서 A->newnode과정
            }    
        } //노드의 다음 자리에 새 노드 넣음

        node* removeNext(){ //다음노드 지우기
            node* removed = next;
            if(removed != nullptr){
                next = removed->next;
            }
            return removed; //removed가 마지막 노드여도 문제없이 반환
        }//노드의 다음 자리 노드를 지우는 연산
}; 

class l_hn_s_linked_list{ //line head node string linked list
    protected:
        node origin;
    public:
        l_hn_s_linked_list(): origin("head node"){}//생성자, 0으로 initialized 되는 노드
        ~l_hn_s_linked_list(){clear();} //소멸자

        void clear();//리스트를 지우는 연산
        node* getHead(); //첫 노드를 부르는 연산, 노드의 포인터로 리턴
        bool isEmpty(); //공백 확인

        node* getEntry(int pos); //pos위치 노드 조회연산
        void insert(int pos, node* n); //삽입연산
        void remove(int pos); //삭제연산
        node* find(std::string value); //검색연산
        void replace(int pos, node* n); // 치환연산
        size_t size(); //사이즈 반환
        void display(); //LinkedList의 전체내용 출력
};

void l_hn_s_linked_list::clear(){
    while(!isEmpty()){
        remove(0);
    }
} // 리스트를 지우는 연산

node* l_hn_s_linked_list::getHead(){
    return origin.getLink(); 
    //origin은 처음 initialize할때 head 노드 전에 있는 가상의 노드
    //따라서 origin의 다음 노드가 실제 linkedlist의 head 노드
} // 첫 노드를 부르는 연산

bool l_hn_s_linked_list::isEmpty(){
    return getHead() == nullptr;
} // 공백 확인

node* l_hn_s_linked_list::getEntry(int pos){
    node* n = &origin;
    for(int i = -1; i < pos; i++, n = n->getLink()){
        //시작점;종료조건;루프돌 때 마다 연산 => 사실 연산은 하나가 아니라 여러개 가능 
        if(n == nullptr){ break; }
    }
    return n;
} // 조회연산

void l_hn_s_linked_list::insert(int pos, node *n){
    node* prev = getEntry(pos - 1); //추가할 위치  이전의 노드포인터를 가져옴
    if(prev != nullptr){ // 이전 노드가 비어있을 경우 이전 노드 다음에 n을 추가해줌
        prev->insertNext(n);
    }
} // 삽입연산

void l_hn_s_linked_list::remove(int pos){
    node* prev = getEntry(pos - 1);
    delete prev->removeNext();
} // 삭제연산

node* l_hn_s_linked_list::find(std::string value){
    for(node *p = getHead() ; p != nullptr ; p = p->getLink()){
    //for문: 초기식;조건식;변화식
        if(p->getData() == value){ return p; }
    }
    return nullptr;
} // 검색연산 (value와 같은 값을 찾음). 가장 먼저 나오는 노드를 리턴
    
void l_hn_s_linked_list::replace(int pos, node *n){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        delete prev->removeNext();
        prev->insertNext(n);
    }        
} // 치환연산

size_t l_hn_s_linked_list::size(){
    int count = 0;
    for(node *p = getHead(); p != nullptr ; p = p->getLink()){
        count++;
    }
    return count;
} // 사이즈 구하기

void l_hn_s_linked_list::display(){
    std::cout << "전체 항목의 수: " << size() << ", ";
    for(node *p = getHead(); p != nullptr ; p = p->getLink()){
        std::cout << p->getData() << " ";
    }
    std::cout << "\n";
} // Linked List의 전체 내용 출력

//line editor만들기
class LineEditor : public l_hn_s_linked_list{
    public:
        void Display(std::ostream *os);
        void InsertLine();
        void DeleteLine();
        void ReplaceLine();
        void LoadFile(std::string fname);
        void SaveFile(std::string fname);
};
//headerfile 만들어서 하는게 좋음 
void LineEditor::Display(std::ostream *os = &std::cout){//아웃풋 스트림을 넣으면 아웃풋스트림으로 작동하고 아니면 표준출력으로 작동
    int i = 0;
    std::cout << "전체 항목의 수 : " << size() << ", ";
    for(node* p =getHead(); p != nullptr; p = p->getLink(), i++){
        std::cerr << i << " ";
        p->display(os);
    }
}
void LineEditor::InsertLine(){
    int position;
    std::string line; //입력한 데이터
    std::cout << " 입력행 번호: ";
    std::cin >> position;
    std::cin.sync(); //버퍼에 개행문자가 남아있음 -> getline()같은거는 개행문도 받음 그래서 input이 안들어오는 현상이 생김 그래서 비워주는게 필요
    // 그래서 사용하는게 cin.sync()나 cin.ignore() 사용 
    std::cin.clear();
    std::cout << " 입력할 내용: ";
    getline(std::cin, line);
    insert(position, new node(line));
}
void LineEditor::DeleteLine(){
    int position;
    std::cout << " 삭제행 번호: ";
    std::cin >> position;
    remove(position);
}
void LineEditor::ReplaceLine(){
    int position;
    std::string line; //입력한 데이터
    std::cout << " 변경행 번호: ";
    std::cin >> position;
    std::cin.sync();
    std::cin.clear();
    std::cout << " 변경할 내용: ";
    getline(std::cin, line);
    replace(position, new node(line));
}
void LineEditor::LoadFile(std::string fname){
    std::ifstream ifs(fname); //파일네임 불러오기
    std::string line; //버퍼용 스트링
    while(std::getline(ifs,line)){ //한줄씩 계속 받음
        insert(size(),new node(line)); //노드하나 라인하나이므로 사이즈는 현재 라인 수의 다음 것을 가리킴
    }
    ifs.close();
}
void LineEditor::SaveFile(std::string fname){
    std::ofstream ofs(fname); //출력 스트림
    if(ofs.good()){ //다 열려있는 경우만
        Display(&ofs); 
        ofs.close(); //파일 닫기
    }
}

