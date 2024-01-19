#include <iostream>
#include "CircularQueue.hpp"

#define MAX_QUEUE_SIZE 100 //여기서 정의한 경우 전역에 걸쳐 사용 가능

int main(){
    CircularQueue que;
    for(int i = 1; i < 10; i++){
        que.enqueue(i);
    }
    que.display();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.display();


    return 0;
}