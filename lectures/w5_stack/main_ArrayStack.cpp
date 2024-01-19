#include <iostream>
#include "ArrayStack.hpp"

int main(){
    ArrayStack stack;
    for(int i = 1; i < 10; i++){
        stack.push(i);
    }
    stack.display();
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    std::cout << stack.pop() << "\n";
    stack.display();
    
    
    return 0;
}
