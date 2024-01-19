//this-> 사용하는 이유

#include <iostream>

template <typename T> //대신 template <class T>를 써도 되는데 조금 다르게 작동하긴 함
class Base{
    public:
    Base(){std::cout << "Base init\n";}
    ~Base(){}
    void f(){
        std::cerr << "Base<T>::f\n";
    }
};

void f(){//전역함수, independent name
    std::cout << "Global Function f()\n";
}

template <typename T>
class Derived: public Base<T>{
    public:
        Derived(){std::cout << "Derived init\n";} //상속받은 함수가 초기화
        //초기화할때 Derived() : Base<T>() {std::cout << "Derived init\n;"}
        //새 변수가 없을 경우 이런 식으로 할필요는 없음
        //왜냐면 자식 클래스의 생성자를 호출하면 무조껀 부모 클래스의 생성자도 같이 옴
        ~Derived(){}
        void g(){
            std::cerr << "Derived<T>::g\n";
            //f(); 를 사용하면 함수가 base T의 함수인 것을 모르기 때문에, 전역함수 global function f()를 호출
            this->f(); //Base<T>::f(); 로도 사용가능
            //this->를 쓰는 이유:
            //함수 같은 것들은 두가지 이름이 있음: ?
            //1. dependent name, T에 대해서 바뀌는 것
            //2. independent name, T에 대해서 바뀌지 않는 것
        }
};

int main(){
    Derived<float> df;
    df.g();
    Derived<int> di;
    di.g();

    return 0;
}