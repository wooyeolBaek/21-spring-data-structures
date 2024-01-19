#include <iostream>
#include "LinkedListStack.hpp"

/* 순서만 뒤집힌 상태로 데이터가 동일하게 나옴
객체지향언어에서는 실제 구현체에 상관없이 인터페이스(API)만 같으면 
정확하게 같은 결과를 낼 수 있어야함 => 따라서 list나 array의 안에 구현된 것을 몰라도 쓸 수 있는 것
=> 이게 객체지향언어의 핵심이고 생산성을 가장 높혀주는 것, 만들긴 힘들지만 재사용은 쉬움 
헤더파일을 만드는 이유 : 장기적으로 사용  */

int main(){
    LinkedlistStack stack; 
    for(int i = 0; i < 10; i++){
    stack.push(i);
    }
    stack.display();
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    stack.display();

    return 0;
}
