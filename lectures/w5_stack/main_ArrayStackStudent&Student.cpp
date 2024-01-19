#include <iostream>
#include "ArrayStackStudent.hpp"

int main(){
    StudentStack stack;
    stack.push(Student(20201010,"나나나","스마트시스템소프트웨어학과"));
    stack.push(Student(20201011,"가가가","전자공학부"));
    stack.push(Student(20201012,"다다다","베어드교양학부"));
    stack.display();
    stack.pop();
    // std::cout << stack.pop() << "\n"; stack.pop()이 student 자료형이라 std::cout 사용 못함
    stack.display();    
    return 0;
}
