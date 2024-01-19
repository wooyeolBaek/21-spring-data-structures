#pragma once
#include <iostream>


inline void error(const char* str){
	std::cerr << str << "n";
	exit(1);
};

// Array 로 list 만들기, 정적할당을 동적할당으로 바꿈 
class DArrayList{
	private:
    //ArrayList는 고정사이즈였지만
    //DArrayList는 동적사이즈가 되므로
    //data를 포인터로 정의 
		int*  data;
		size_t length;
        size_t current_size; //현재 할당된 사이즈를 알 수 있는 변수
		size_t resize_unit; //사이즈 조정 단위
	public:
		DArrayList(size_t init_size = 10){ 
    //생성자도 복잡해짐, 이제 void가 아니고 어떤 사이즈 존재, 입력할 떄 사이즈 변경 가능
            std::cout << "\n<Initialize to : " << init_size << "> "; //초기화할 때 출력
            data = new int[init_size]; //초기화한 사이즈만큼 할당
            current_size = init_size;
            resize_unit = init_size; //임의로 정하면 됨, resize_unit만큼씩 변경한다고 설정
            length = 0;
        }
        //동적할당 했으므로 소멸자 만들어서 확실하게 지워줘야함
        ~DArrayList(){ delete [] data; }

        //resize연산 추가
        void resize(size_t newsize){ //말했듯이 size_t는 unsigned integer
            std::cout << "\n<Resize to : " << newsize << "> ";
            int* temparray = new int[newsize]; //새로운 사이즈를 입력받아서 resize할 임시 array를 만들어 사이즈를 할당해줌  
            for(int i = 0; i < length; i++){  //temparray에 원해 데이터 다 복사
                temparray[i] = data[i];
            }
            delete [] data;
            current_size = newsize;
            data = temparray;
        }

		void insert(int pos, int e){
			if(pos >= 0 && pos <= length){ // isFull연산은 필요없어서 지움
				if(isFull()){ //데이터가 꽉 차있을 경우 자동으로 array사이즈를 늘려줌 
                    resize(current_size + resize_unit);
                }
                for(int i = length; i > pos; i--){
					data[i] = data[i-1];
				}
				data[pos] = e;
				length++;
			}
			else{std::cout << "삽입 위치가 잘못 되었습니다.\n";} //포화상태도 없으므로 지움
		}
		void remove(int pos){
			if(!isEmpty() && pos >= 0 && pos < length){
                if(current_size > resize_unit + length){ //굳이 안바꿔도되는데 메모리사용의 효율화를 위해 바꿈
                //전체 데이터가 차 있는 공간보다 resize_unit이상으로 여유공간이 남아있을 때 resize_unit 만큼 줄이기
                resize(current_size - resize_unit);
                } //메모리 효율화를 위해 사이즈를 계속 변화 시킴
				for(int i = pos + 1; i < length; i++){
					data[i-1]=data[i];
				}
				length--;
			}
			else{ std::cout << "공백상태 또는 삭제 위치가 잘못 되었습니다.\n";} //공백상태 오류는 여전히 존대 
		}
		int getEntry(int pos){ return data[pos];}
		bool isEmpty(){ return length == 0;}
		bool isFull(){ return length == current_size;} //현재 할당된 사이즈와 같아지면 꽉참
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
		void clear(){ //메모리 효율적 사용을 위해 메모리 할당량 조절 
            length = 0;
            resize(resize_unit); //메모리 할당량 줄일 수 있도록 설계 
        }
};
