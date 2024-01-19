//Doubly linked list를 구현해 보고, 기존 구현한 Single Linked List와 삽입/삭제 연산의 속도를 비교
#include "w8_singleLinkedList.hpp"
#include "w8_dLinkedList.hpp"



int main(){
    //실험: 시간 측정
    s_linked_list<int> sl_list;
    d_linked_list<int> dl_list;
    for(int i=0; i<10; i++){
        sl_list.push_back(i);
        dl_list.push_back(i);
    }
    int max_iterS = 100000;
    int max_iterD = 100000;
    
    //insert_node_at 측정
    //single linked list 측정
    auto startS1 = std::chrono::steady_clock::now();
    for(int i=0; i<max_iterS; i++){
        sl_list.insert_node_at(2, 7);
    }
    auto endS1 = std::chrono::steady_clock::now();
    auto etimeS1 = std::chrono::duration_cast<std::chrono::microseconds>(endS1-startS1).count();
    std::cout << "single linked list 삽입 실행시간 : " << etimeS1 << "\n";

    //double linked list 측정
    auto startD1 = std::chrono::steady_clock::now();
    for(int i=0; i<max_iterD; i++){
        sl_list.insert_node_at(2, 7);
    }
    auto endD1 = std::chrono::steady_clock::now();
    auto etimeD1 = std::chrono::duration_cast<std::chrono::microseconds>(endD1-startD1).count();
    std::cout << "double linked list 삭제 실행시간 : " << etimeD1 << "\n";

    if(etimeD1 > etimeS1){
        std::cout << "double linked list의 삽입 시간이 더 오래 걸립니다.\n";
    }
    else if(etimeD1 < etimeS1){
        std::cout << "single linked list의 삽입 시간이 더 오래 걸립니다.\n";
    }
    else{
        std::cout << "걸린 시간이 같습니다.\n";
    }

    //pop_node_at 측정
    //single linked list 측정
    auto startS2 = std::chrono::steady_clock::now();
    for(int i=0; i<max_iterS; i++){
        sl_list.pop_node_at(0);
    }
    auto endS2 = std::chrono::steady_clock::now();
    auto etimeS2 = std::chrono::duration_cast<std::chrono::microseconds>(endS2-startS2).count();
    std::cout << "single linked list 삽입 실행시간 : " << etimeS2 << "\n";

    //double linked list 측정
    auto startD2 = std::chrono::steady_clock::now();
    for(int i=0; i<max_iterD; i++){
        sl_list.pop_node_at(0);
    }
    auto endD2 = std::chrono::steady_clock::now();
    auto etimeD2 = std::chrono::duration_cast<std::chrono::microseconds>(endD2-startD2).count();
    std::cout << "double linked list 삭제 실행시간 : " << etimeD2 << "\n";

    if(etimeD2 > etimeS2){
        std::cout << "double linked list의 삭제 시간이 더 오래 걸립니다.\n";
    }
    else if(etimeD2 < etimeS2){
        std::cout << "single linked list의 삭제 시간이 더 오래 걸립니다.\n";
    }
    else{
        std::cout << "걸린 시간이 같습니다.\n";
    }

    return 0;
}