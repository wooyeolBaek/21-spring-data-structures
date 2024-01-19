#include <iostream>
#include <random> //cpp.11 부터는 좋은 난수 생성 프로그램이 생김
#include <ctime> //time.h와 같음

#define MAX_QUEUE_SIZE 100

//난수 생성 프로그램, 파이썬과 같은 난수 생성, 기본적인 랜덤함수만큼 빠름
//2^19937 -1로 만듦
//생성함수, 뒤에 씨드?를 넣어 줘야하는데 가장 많이 사용하는 방식이 시간 넣는 방식 사용, unsigned int에 현재시각 time을 받는 생성함수
static std::mt19937 gen = std::mt19937((unsigned int)time(NULL)); 
static std::uniform_real_distribution<> dist(0,1);
//정수가 아니라 실수 형태의 난수를 생성해 주는 생성함수 uniform_real_distribution<> 
//dist(0,1)으로 0,1 사이의 수(double 변수) 생성 
//사용법: dist(gen) 이런식으로, mt19937fh 난수를 생성해서 dist(0,1)에 넣어 0부터 1사이의 수로 바꿔서 사용

inline void error(const char* str){
    std::cerr << str << "\n"; //에러의 경우 cerr로 출력
    exit(1);
};

struct Customer{ //고객 정보 자료형 만들기, Customer 구조체
    int id; //고객 id
    int tArrival; //도착 시간
    int tService; //서비스 받는 시간
    Customer(int i=0, int tArr=0,int tServ=0) //생성자 : id,tArrival, tService 0으로 초기화
        : id(i), tArrival(tArr), tService(tServ){}
    ~Customer(){} //소멸자
};

class CustomerQueue{
    private:
        int front;
        int rear;
        Customer data[MAX_QUEUE_SIZE]; //customer리스트
    public:
        CustomerQueue(){front=rear=0;} //초기화
        bool isEmpty(){return front == rear;}
        bool isFull(){return (rear+1) % MAX_QUEUE_SIZE == front;}
        void enqueue(Customer& val){ //맨뒤에 데이터 추가
            if(isFull()){
                error("ERROR : 큐가 포화상태입니다.\n");
            }
            else{
                rear = (rear+1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        Customer& dequeue(){
            if(isEmpty()){
                error("ERROR : 큐가 공백상태입니다. \n");
            }
            else{
                front = (front+1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }
};

//편의성을 위해 만듦, 굳이 이렇게 안하고 main함수 안에 만들어도 됨
class BankSimulator{
    private:
    //시뮬레이터에 입력하는 변수 세가지
        int nSimulation; //최대 몇번 시뮬레이션 할껀지, 즉 최대 몇번 쨰 시간까지 갈 껀지
        double probArrival; // 손님이 도착할 확률, 랜덤으로 줄 계획
        int tMaxService; //최대로 서비스 받는 시간, 이것도 uniform distribution해서 1부터 최대시간사이에서 정해줄 계획
    //받은 변수로 결과저장 변수도 채움 
        int totalWaitTime; //지금까지 얼마나 많은 사람들이 큐에 대기했는지,나중에 결과 확인 용
        int nCustomers; //손님이 얼마나 지나갔고 얼마나 서비스를 받았는지결과확인, 즉 방문한 손님 수
        int nServedCustomers; //위와 동일
        CustomerQueue que; //큐 만들기, 손님들 대기하는 큐
        bool isNewCustomer(){return dist(gen) < probArrival;} //손님이 올지 안올지 정하는 함수
        // 난수가 손님이 올 확률보다 작으면 손님이 오고 크면 손님이 옴 => 확률대로 손님이 옴
        int randServiceTime(){return (int)tMaxService*dist(gen);}//한사람이 얼마나 서비스를 해야하는지에 대한 시간을 랜덤으로 만들어 줌 
        //(int)는 정수로 반환, distribution은 0<=x<1인 수를 줌, 예시: 7*0.3=2.1 -> 2(정수 반환)
        void insertCustomer(int arrivalTime){ //손님이 도착하면 큐에 넣어주는 함수
            Customer a(++nCustomers, arrivalTime, randServiceTime());
            //a:현재 도착한 손님, 현재까지 방문한 손님 수 + 1번째 id를 가짐, 현재 도착시간 기록, 임의의 서비스시간 정해줌
            std::cout << "고객 " << a.id << "방문 (서비스 시간: " << a.tService << "분)\n";
            que.enqueue(a);
        }

    public:
        BankSimulator() : nCustomers(0), totalWaitTime(0), nServedCustomers(0){} //생성자
        void readSimulationParameters(){ 
            std::cout << "시뮬레이션 할 최대 시간 (예:10) = ";
            std::cin >> nSimulation; 
            std::cout << "단위시간에 도착하는 고객 수 (예:0.5) = ";
            std::cin >> probArrival; 
            std::cout << "한 고객에 대한 최대 서비스 시간 (예: 5) = ";
            std::cin >> tMaxService;

        }
        //시뮬레이터 돌리기
        void run(){
            int clock = 0;//처음 시간 
            int serviceTime  = -1; //서비스타임도 아무것도 안했으므로 -1
            while(clock < nSimulation){
                clock++;
                std::cout << "현재시각: " << clock << "\n";
                if(isNewCustomer()){insertCustomer(clock);}
                if(serviceTime > 0){serviceTime--;} 
                //serviceTime:개별고객이 서비스를 받는 시간, 0이 될때까지 빼줌
                else{ //serviceTime이 0이 되면
                    if(que.isEmpty()){continue;}
                    Customer a = que.dequeue();
                    nServedCustomers++;
                    totalWaitTime += clock-a.tArrival;
                    std::cout << "고객 " << a.id << "서비스 시작";
                    std::cout << "(대기시간: " << clock-a.tArrival << "분)";
                    serviceTime = a.tService-1; // 위에 과정들을 거치면서 1분 소요했으니까 -1해줌
                }
            }

        }
        void printStat(){//최종적으로 시뮬레이션 결과를 출력하는 함수
            std::cout << "---------------------------------------------------------\n";
            std::cout << "서비스 받은 고객 수: " << nServedCustomers << "명 \n"; 
            std::cout << "전체 대기 시간: " << totalWaitTime << "분 \n";
            std::cout << "서비스 받은 고객 평균 대기 시간: " << (double)totalWaitTime/nServedCustomers << "분/명 \n";
            std::cout << "현재 대기 고객 수: " << nCustomers - nServedCustomers << "명 \n";
        }
};

int main(){
    BankSimulator sim; //simulator 돌리기
    sim.readSimulationParameters(); //parameter읽기
    sim.run();
    sim.printStat();
    return 0;
}