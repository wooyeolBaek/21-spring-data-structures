#pragma once
#include <iostream>
#define MAX_LIST_SIZE 100000

inline void error(const char* str){
	std::cerr << str << "n";
	exit(1);
};

// Array 로 list 만들기
class ArrayList{
	private:
		int data[MAX_LIST_SIZE];
		size_t length; //size_t 오늘 배울 내용
		// => 사이즈 타입, unsigned int
		//다른점 == 32비트 OS및 컴파일러에서 uint32_t 즉, 32길이의 int임 
		//해석== 32비트형의 정수인데 u==unsigned 부호가 없다 => 양수만 존재
		//사실 int같은 건 C의 변수이고 cpp에서는 좀더 엄밀하게 정의한 변수들이 있음
		//64비트 OS및 컴파일러에서 uint_64t
		//차이가 나는 이유 ==size_t의 용도가 array의 maximum size정의 
		//따라서 시스템 dependence하게 시스템의 용량에 의존 
	public:
		ArrayList(void){ length = 0;}

		void insert(int pos, int e){
			if(!isFull() && pos >= 0 && pos <= length){
				for(int i = length; i > pos; i--){
					data[i] = data[i-1];
				}
				data[pos] = e;
				length++;
			}
			else{std::cout << "포화상태 또는 삽입 위치가 잘못 되었습니다.\n";}
		}
		void remove(int pos){
			if(!isEmpty() && pos >= 0 && pos < length){
				for(int i = pos + 1; i < length; i++){
					data[i-1]=data[i]; //데이터 왼쪽으로 옯기기
				}
				length--;
			}
			else{ std::cout << "공백상태 또는 삭제 위치가 잘못 되었습니다.\n";}
		}
		int getEntry(int pos){ return data[pos];}
		bool isEmpty(){ return length == 0;}
		bool isFull(){ return length == MAX_LIST_SIZE;}
		bool find(int item){
			for(int i = 0; i < length; i++){
				if(data[i] == item){return true;}
			}
			return false;
		}
		void replace(int pos, int e){
			if(!isEmpty() && pos >= 0 && pos < length){
				data[pos] = e;
			}
			else{ std::cout << "공백상태 또는 치환 위치가 잘못 되었습니다.\n";}
		}
		int size(){ return length;}
		void display(){
			std::cout << "Array List의 총 항목 수 : " << length;
			for(int i = 0; i < length; i++){
				std::cout << " [" << data[i] << "]";
			}
			std::cout << "\n";
		}
		void clear(){ 
		// clear는 어차피 동적할당 아니라 MAX_LIST_SIZE로 할당돼있어서 크게 어렵진 않을 거임
		length = 0; // length만 0으로 만들어주면됨 
		}
};
