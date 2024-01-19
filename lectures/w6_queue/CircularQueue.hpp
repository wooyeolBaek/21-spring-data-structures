#include <iostream>

#define MAX_QUEUE_SIZE 100 //여기서 정의한 경우 전역에 걸쳐 사용 가능

inline void error(const char* str){
    std::cerr << str << "\n"; //에러의 경우 std::cerr(표준에러출력)로 출력, std::cout(표준출력)과 다름
    exit(1);
};

class CircularQueue{
    protected:
        int front; //맨 앞
        int rear; //맨 뒤
        int data[MAX_QUEUE_SIZE];
    public:
        CircularQueue(){front = rear =0;}
        ~CircularQueue(){}; 
        bool isEmpty(){return front == rear;}
        bool isFull(){return (rear+1) % MAX_QUEUE_SIZE == front;}
        void enqueue(int val){ //맨뒤에 데이터 추가
            if(isFull()){
                error("ERROR : 큐가 포화상태입니다.\n");
            }
            else{
                rear = (rear+1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        int dequeue(){
            if(isEmpty()){
                error("ERROR : 큐가 공백상태입니다. \n");
                return 0; // 이상해서 내가 넣음
            }
            else{
                front = (front+1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }
        int peek(){
            if(isEmpty()){
                error("ERROR : 큐가 공백상태입니다. \n");
                return 0; // 이상해서 내가 넣음
            }
            else{
                return data[(front+1) % MAX_QUEUE_SIZE];
            }
        }
        void display(){
            std::cout << "Queue 안에는 : ";
            int maxi =(front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            //논리연산 ? 참값 : 거짓값 
            for(int i = front+1; i <= maxi; i++){
                std::cout << data[i % MAX_QUEUE_SIZE] << " ";
            }  
            std::cout << "\n";
        }
};