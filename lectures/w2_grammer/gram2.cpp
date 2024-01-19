//
//  main.cpp
//  DS_lecture3_1
//
//  Created by Wooyeol Baek on 3/17/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/* 클래스 */

class Animal
{
    private: //변수는 일반적으로 외부 접근이 안되도록 private으로 정의함 : 인캡슐레이션이라고 함
        int height;
        int weight;
        string name;
        
        static int numberOfAnimals;//static변수는 정적으로 정의된 변수라서 함수가 처음 불러졌을때부터 프로그램 전체에서도 유지가 됨
    
    public:
        int getHeight(){ return height; }
        int getWeight(){ return weight; }
        string getName(){ return name; }
        void setHeight(int newval){ height = newval;}
        void setWeight(int newval){ weight = newval;}
        void setName(string newval){ name = newval;}
    
        void setAll(int, int, string); //전체를 한번에 set하는 함수
    
        Animal(int, int, string); // 생성자 만들기
        ~Animal(); //소멸자 만들기
    
        Animal();
    
        static int getNumberOfAnimals(){ return numberOfAnimals; }
        void toString();
};

int Animal :: numberOfAnimals = 0;

Animal :: Animal(int height, int weight, string name) // 생성자 정의
{
    this -> height = height; // height 변수를 입력받은 height변수로 치환하라의 의미
    this -> weight = weight;
    this -> name = name;
    Animal :: numberOfAnimals ++;
}
// 소멸자 정의
Animal :: ~Animal()
{
    cout << "Animal " << this -> name << " 잘가요. \n";
}

// 아무것도 없었을 때 입력하는 함수
Animal :: Animal()
{
    Animal :: numberOfAnimals++;
}
//Animal 의 정보를 출력하는 함수

void Animal :: toString()
{
    cout << "이 동물의 이름은" << this -> name << "이고, 키는 " << this -> height << "이며, 몸무게는 " << this -> weight << "입니다. \n";
}

// 강아지라는 특별한 동물의 클래서 정의 : 상속
class Dog : public Animal
{
    private :
        string sound = "멍멍";
    
    public :
    void doBark(){ cout << sound << "\n"; }
    Dog(int, int, string, string);
    Dog() : Animal(){};
    
    void toString();
};
//이니셜라이져 정의
Dog :: Dog(int height, int weight, string name, string bark) : Animal(height, weight, name)
{
    this -> sound = bark;
}
// toString 정의
void Dog :: toString()
{
    cout << "이 동물의 이름은" << this -> getName() << "이고, 키는 " << this -> getHeight() << "이며, 몸무게는 " << this -> getWeight() << "이며 " << sound << "라고 짖습니다. \n";
}

int main()
{
    Animal spider; // 거미 만들기
    spider.setHeight(60);
    spider.setWeight(20);
    spider.setName("Peter Parker");
    cout << "현재 동물의 수는? " << Animal :: getNumberOfAnimals() << "\n";
    cout << "이 동물의 이름은" << spider.getName() << "이고, 키는 " << spider.getHeight() << "이며, 몸무게는 " << spider.getWeight() << "입니다. \n";
    
    Animal ant(5, 1, "Scott Lang"); // 개미 만들기, 다른방식
    cout << "현재 동물의 수는? " << Animal :: getNumberOfAnimals() << "\n";
    cout << "이 동물의 이름은" << ant.getName() << "이고, 키는 " << ant.getHeight() << "이며, 몸무게는 " << ant.getWeight() << "입니다. \n";
    //개 만들기
    Dog dog(40, 12, "Mike", "왈왈");
    cout << "현재 동물의 수는? " << Animal :: getNumberOfAnimals() << "\n";
    dog.doBark();
    spider.toString();
    dog.toString();
    /* 똑같은 toString이라는 메소드를 썼는데 출력이 다름 : 함수 오버라이딩이라고 함*/
    dog.Animal::toString(); // 개인데 출력을 다른 동물처럼 하고싶을 경우
    
    return 0;
}
