#include <iostream>
#include <vector>
#include <chrono>

struct node{
    int data;
    node* next;
};

class s_linked_list{
    protected:
        node* head;
        node* tail;
        int size = 0;
    public:
        s_linked_list(){ //생성자
            head = nullptr;
            tail = nullptr;
        }
        ~s_linked_list(){ //소멸자
            delete_list();
        }
        //삽입연산
        void push_back(int n){
            node *tmp = new node;
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
        //삭제연산
        void delete_list(){
            node* ptr = head;
            while(ptr != nullptr){
                head = ptr->next;
                delete ptr;
                ptr = head;
            }
            size = 0;
            std::cout << "리스트가 삭제되었습니다." << "\n";
        }
        //사이즈
        int Size(){
            return size;
        }
        //n번째 원소
        int element(int n){
            node* ptr = head;
            for(int i = 0; i < n; i++){
                ptr = ptr->next;
            }
            return ptr->data;
        }
    
//과제함수 1번
        void generateList(int n){
            std::cout << "Linked List = {";
            for(int i = 0; i < n; i++){
                node* tmp = new node;
                tmp->data = i;
                if(i+1 < n){
                    std::cout << tmp->data << ", ";
                }
                else{
                    std::cout << tmp->data << "}\n";
                }
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
        }
        
};
//과제함수 2번
void CopyLS2DA(int arr[], s_linked_list &linked_list){
    std::cout << "Array = {";
    for(int i = 0; i < linked_list.Size(); i++){
        if(i < linked_list.Size()-1){
        arr[i] = linked_list.element(i);
        std::cout << arr[i] << ", ";
        }
        else{
            arr[i] = linked_list.element(i);
            std::cout << arr[i] << "}\n";
        }
    }
}


int main(){
    s_linked_list linked_list;
    linked_list.generateList(10);
    
    //동적할당
    int length = linked_list.Size();
    int* arr = new int[length];

    CopyLS2DA(arr,linked_list);
    
    
    delete[]arr;
    return 0;
}
