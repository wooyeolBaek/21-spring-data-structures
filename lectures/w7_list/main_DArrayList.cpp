#include "DArrayList.hpp"
#include <chrono>
#include <iostream>

int main(){
	DArrayList list (10); //10개 할당

    /*
    for(int i = 0; i < 20; i++){ //10개 할당 했지만 20개 까지 채우기
        list.insert(list.size(), i);
        if(i%10 == 9){
            list.display(); //증가연산이 작동하는지 확인
        }
    }

    for(int i = 0; i < 20; i++){//삭제
        list.remove(list.size()-1);
        if(i%10 == 9){ //10번째마다 한번씩 전체 데이터 출력 
            list.display();
        }
    }
    list.display();
    */
    //이렇게하면 크기를 조절할 때 마다 오버헤드가 생김 

//같은 것을 크기를 100으로 바꿨을 때, 매 스탭마다 시간 재보기 
    for(int i = 0; i < 100; i++){
        auto start = std::chrono::steady_clock::now();
        list.insert(list.size(), i);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns \n";
    }
    std::cout << "\n";

    for(int i = 0; i < 100; i++){
        auto start = std::chrono::steady_clock::now();
        list.remove(list.size()-1);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns \n";
    }
//이렇게되면 10번에 한번 씩 리스트를 재할당해서 사이즈 조절하는 스탭이 생김 
//사이즈 조절할 떄만 시간이 몇 배로 많이걸리고 나어지는 거의 안걸림 
//그럼에도 불구하고 메모리 사용이 효율적이고 
//적정한 수준에서의 resize를 정해주면 효율적으로 사용 가능 
//사이즈를 크기가 아니라 비율로 증가 감소도 가능 

    list.clear();
    list.display();

    return 0;
}