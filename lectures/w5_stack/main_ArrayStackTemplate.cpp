#include <iostream>
#include "ArrayStackTemplate.hpp"
#include "Student.hpp"

int main(){
    ArrayStack<double> stack; //자료형=double
    for(int i = 0; i < 10; i++){
    stack.push(i);
    }
    stack.display();
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    stack.display();

    ArrayStack<Student> stack2;
    stack2.push((Student(20200001,"가가가","스시소")));
    stack2.push((Student(20200001,"나나나","법학과")));
    stack2.push((Student(20200001,"나나나","물리학과")));
    stack2.display();
    stack2.pop();
    stack2.display();
    /* display()가 작동안함 왜냐면, StudentStackTemplate에서 display에 << 를 사용해 출력해야하는데 
    이 연산자가 Student 자료형에 정의가 안되어 있음 => 연산자 오버로딩으로 정의해주면 됨 */


    return 0;
}
