#include "ArrayList.hpp"
#include <chrono> //실험하려고 부름

int main(){
	ArrayList list;
	list.insert(0,10);
	list.insert(0,20);
	list.insert(1,30);
	list.insert(list.size(),40);
	list.insert(2, 50);
	list.display();

	list.remove(2);
	list.remove(list.size()-1);
	list.remove(0);
	list.replace(1,90);
	list.display();

	//실험
	ArrayList list2;
	auto end = std::chrono::steady_clock::now(); //cpp형식으로 현재시간 불러오기
	auto start = std::chrono::steady_clock::now(); 
	for(int i = 0; i < 10000; i++){
		list2.insert(0,0); //삽입연산, 
		//list2.insert(list2.size(),0);으로하면 복사가 필요없으므로 시간이 거의 비슷하게 나옴
		if(i % 1000 == 999){//매 천번째마다 지우는 시간 체크해서 반환해줌 
			end = std::chrono::steady_clock::now(); //다시 종료시간 체크
			std::cout << i << "번째 삽입 : ";
			std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns \n";
			//duration_cast는 시간 차이를 계산 두 시간, start와 end의 시간 차이를 chrono에서 받은 자료형으로 계산 후 특정 타임 유인수로 변경해줌 
			start = std::chrono::steady_clock::now(); //start 초기화
		}
	}

	start = std::chrono::steady_clock::now(); //start 초기화
	for(int i = 0; i < 10000; i++){
		list2.remove(0); //삭제연산
		//list2.remove(list2.size()-1);으로하면 복사가 필요없으므로 시간이 거의 비슷하게 나옴
		if(i % 1000 == 999){//매 천번째마다 삭제하는 시간 체크해서 반환
			end = std::chrono::steady_clock::now(); //다시 종료시간 체크
			std::cout << i << "번째 삭제 : ";
			std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns \n";
			//duration_cast는 시간 차이를 계산 두 시간, start와 end의 시간 차이를 chrono에서 받은 자료형으로 계산 후 특정 타임 유인수로 변경해줌 
			start = std::chrono::steady_clock::now(); //start 초기화
		}
	}
	//실험 결과
	//삽입이 진행될 수록 진행시간이 느려짐 
	//삽입이 진행될 수록 진행시간이 빨라짐 
	return 0;
}