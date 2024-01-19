#include <iostream>
#include <vector>
#include <chrono>

struct node{
    int data;
    node* next;
};
//node == 한개의 자료
//template <T> 로 여러 자료형을 한번만 정의할 수 있음

class s_linked_list{
    protected:
        node* head;
        node* tail;
        int size = 0;
    public:
        s_linked_list(){
            head = nullptr;
            tail = nullptr;
        }
        ~s_linked_list(){
            delete_list();
        }

        //삽입연산들
        void push_front(int n);
        void push_back(int n);
        void insert_node_at(int idx, int n);

        //삭제연산들
        int pop_front();
        int pop_back();
        int pop_node_at(int idx);
        void remove_node(int n);
        void delete_list();

        //대입
        void replace_value_at(int idx, int n);

        //검색 및 표시
        int Size();
        void display_contents();
        int search_value(int n);
};

void s_linked_list::push_front(int n){
    node* ptr = new node;
    ptr->next = head;
    ptr->data = n;
    head = ptr;
    if(ptr->next == nullptr){
        tail = ptr;
    }
    size++;
}

void s_linked_list::push_back(int n){
    node* tmp = new node;
    tmp->data = n;
    tmp->next = nullptr;
    if(head == nullptr){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
    size++;
}

void s_linked_list::insert_node_at(int idx, int n){
    if(size < idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다.\n";
    }
    else if(idx == 0){
        push_front(n);
    }
    else if(idx == size){
        push_back(n);
    }
    else{
        node* ptr = head; // 노드 ptr == 노드 head
        node* tmp = ptr; //노드 tmp == 노드 ptr
        node* new_node = new node; //새 노드 정의
        new_node->data = n; //새 노드의 data = n
        new_node->next = nullptr;//새 노드의 next는 일단 비워두기
        for(int i=0; i < idx; i++){
            tmp = ptr; //들어갈 노드의 직전 노드 위치
            ptr = ptr->next; //들어갈 노드의 위치
        }
        tmp->next = new_node;
        new_node->next = ptr;
        size++; 
    }
}

//삭제연산
int s_linked_list::pop_front(){
    if(head == nullptr){
        std::cout << "linked list가 비어있습니다.\n";
        exit(1);
    }
    node* ptr = head; //head를 ptr노드로 옮기기
    int value = head->data; //head의 data를 value로 옮기기
    head = ptr->next; //ptr의 next를 head로 놓기
    if(head == nullptr){tail == nullptr;} //head가 비어있으면 tail도 비우기
    delete ptr; //ptr노드 지우기
    size--;
    return value;
}

int s_linked_list::pop_back(){
    if(size == 0){
        std::cout << "linked list가 비어있습니다. \n";
        exit(1);
    }
    node* ptr = head;
    node* tmp = new node;
    while(ptr->next != nullptr){
        tmp = ptr;
        ptr = ptr->next;
    }
    int value = ptr->data;
    if(ptr == head){
        head = nullptr;
        tail = nullptr;
    }
    else{
        tail = tmp;
        tail->next = nullptr;
    }
    delete ptr;
    size--;
    return value;
}

int s_linked_list::pop_node_at(int idx){
    int value = -1;
    if(size <= idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다.\n";
    }
    else if(size == 0){
        std::cout << "linked list가 비어있습니다.\n";
        exit(1);
    }
    else if(idx == 0){
        value = pop_front();
    }
    else if(idx == size-1){
        value = pop_back();
    }
    else{
        node* ptr = head;
        node* tmp = ptr;
        for(int i=0; i<idx; i++){
            tmp = ptr;
            ptr = ptr->next;
        }
        value = ptr->data;
        tmp->next = ptr->next;
        size--;
        delete ptr;
        ptr = nullptr;
    }
    return value;
}

void s_linked_list::remove_node(int n){
    node* ptr = head;
    node* tmp = ptr;
    while(ptr != nullptr){
        if(ptr->data == n){
            break;
        }
        else{
            tmp = ptr;
            ptr = ptr->next; //ptr == 다음 노드
        }
    }
    if(ptr == nullptr){
        std::cout << n << "값의 노드는 존재하지 않습니다.\n";
    }
    else if(size == 1){
        head = nullptr;
        tail = nullptr;
    }
    else{
        size--;
        std::cout << ptr->data << "값의 노드를 하나 지웁니다.\n";
        tmp->next = ptr->next;
        if(ptr == tail){
            tail = tmp;
        }
        delete ptr; //동적할당 해제
    }
}

void s_linked_list::delete_list(){
    node* ptr = head;
    while(ptr != nullptr){
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    size = 0;
    std::cout << "리스트가 삭제되었습니다. \n";
}

//대입
void s_linked_list::replace_value_at(int idx, int n){
    node* ptr = head;
    if(size == 0){
        std::cout << "linked list가 비어있습니다. \n";
        exit(1);
    }
    else if(size <= idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다.\n";
    }
    else{
        for(int i=0; i<idx; i++){
            ptr = ptr->next;
        }
        ptr->data = n;
    }
}

//검색 및 표시
int s_linked_list::Size(){
    return size;
}

void s_linked_list::display_contents(){
    node* ptr = head;
    while(ptr != nullptr){
        std::cout << ptr->data << "->";
        ptr = ptr->next;
    }
    std::cout << "nullptr" << "\n";
}

int s_linked_list::search_value(int n){
    node* ptr = head;
    int idx = 0;
    bool isFind = false;
    while(ptr != nullptr){
        if(ptr->data == n){
            std::cout << n << " 은 " << idx << " 에 있습니다. \n";
            isFind = true;
            break;
        }
        ptr = ptr->next;
        idx++;
    }
    if(isFind == false){
        std::cout << n << " 은 리스트 안에 있습니다.\n";
        return -1;
    }
    else{
        return idx;
    }
}

int main(){
    s_linked_list sl_list;
    sl_list.push_front(1);
    std::cout << sl_list.pop_back() << "\n";

    sl_list.push_back(10);
    sl_list.push_back(11);
    sl_list.push_back(14);
    sl_list.push_back(18);
    sl_list.push_back(20);
    sl_list.push_back(27);
    sl_list.display_contents();

    sl_list.insert_node_at(2, 7);
    sl_list.display_contents();

    sl_list.push_front(15);
    sl_list.display_contents();

    sl_list.search_value(10);
    sl_list.search_value(20);

    std::cout << sl_list.pop_back() << " deleted at back\n";
    sl_list.display_contents();

    std::cout << sl_list.pop_front() << " deleted at front\n";
    sl_list.display_contents();

    std::cout << sl_list.pop_node_at(3) << " deleted at 3\n";
    sl_list.display_contents();

    sl_list.remove_node(7);
    sl_list.display_contents();
    std::cout << "리스트의 크기는" << sl_list.Size() << "\n";

    //실험: 시간 측정
    s_linked_list sl_list2;
    sl_list2.push_back(10);
    sl_list2.push_back(11);
    sl_list2.push_back(14);
    sl_list2.push_back(18);
    sl_list2.push_back(20);
    sl_list2.push_back(27);
    int max_iter = 100000;

    auto start = std::chrono::steady_clock::now(); //auto는 변수 타입을 추론함, 이 수업에서는 잘 안쓸꺼임
    for(int i=0; i<max_iter; i++){
        sl_list2.insert_node_at(2, 7);
    }
    auto end = std::chrono::steady_clock::now();
    auto etime = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    std::cout << "single linked list 삽입 실행시간 : " << etime << "\n";

/*
    start = std::chrono::steady_clock::now();
    std::vector<int> v_list2 = {10,11,14,18,20,17};
    for(int i=0; i<max_iter; i++){
        v_list2.insert(v_list2.begin()+2, 7);
    }
    end = std::chrono::steady_clock::now();
    etime = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    std::cout << "std::vector 삽입 실행시간 : " << etime << "\n";

    s_linked_list sl_list3;
    sl_list3.push_back(10);
    sl_list3.push_back(11);
    sl_list3.push_back(14);
    sl_list3.push_back(18);
    sl_list3.push_back(20);
    sl_list3.push_back(27);

    start = std::chrono::steady_clock::now();
    for(int i=0; i<max_iter; i++){
        sl_list3.replace_value_at(5, 7);
    }
    end = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    std::cout << "single linked list 대입 실행시간 : " << etime << "\n";

    start = std::chrono::steady_clock::now();
    std::vector<int> v_list3 = {10,11,14,18,20,17};
    for(int i=0; i<max_iter; i++){
        v_list3[5] = 7;
    }
    end = std::chrono::steady_clock::now();
    etime = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    std::cout << "std::vector 대입 실행시간 : " << etime << "\n";
*/
    return 0;
}
