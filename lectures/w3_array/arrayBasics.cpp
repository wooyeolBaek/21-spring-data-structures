#include <iostream>
#define MAX_SIZE 10

//1차원 배열 
void sub(int x, int arr[]){ //배열을 parameter로 받는 함수, 사실상 arr[]의 주소를 받는것임
    x = 10;
    arr[0] = 10;
    for(int i=0; i<MAX_SIZE; i++){
        std::cout << &arr[i] << "\n";
    }//arr과 main의 list의 주소는 같음
}
//즉, 배열을 parameter로 받으면 배열의 주소가 파라미터로 넘어감
//다시 말하면, 배열의 이름은 "포인터" 와 같은 역할은 함

int main(){//메인 함수
    int var;
    int list[MAX_SIZE]; //배열은 정해진 크기로만 초기화가 가능함
    //가변 길이로 쓰기 위해서는 C++의 표준 자료형중 <vector>를 쓰면 됨, std::vector 가변길이 가능

    var = 0;
    list[0] = 0;
    sub(var, list);
    std::cout << var << "\t" << list[0] << "\n";
    //var는 그대로 0이지만, list[0]은 10이 됐음
    //var은 값을 받고, list는 주소를 받아서 함수가 끝나면 바뀐 var는 사라지고, 바뀐 list[0]때문에 list의 주소도 바뀌어서 남기 때문
    
    for(int i=0; i<MAX_SIZE; i++){
        std::cout << &list[i] << "\n";
    }
    //똑같이 sub를 call할때 arr의 주소를 반환하는 과정이 한번 있고
    //list에 대해 주소를 반환하는 과정들이 나옴
    //=> 완전히 같은 주소로 출력됨(헥스, 16진수), int의 size가 4라 4씩 증가하는 구조 

    double list2[MAX_SIZE];
    for(int i=0; i<MAX_SIZE; i++){
        std::cout << &list2[i] << "\n";
    }
    // double의 size는 8 => 주소가 8바이트씩 증가
    // 즉 리스트에서 각 인덱스는 메모리 주소를 정확하게 그 어레이의 변수가 가지고 있는 변수의 자료형의 사이즈 만큼 증가한다.

    return 0;
}