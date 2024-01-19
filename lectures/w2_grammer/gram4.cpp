//
//  main.cpp
//  cpp_grammer_4
//
//  Created by Wooyeol Baek on 3/23/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/* 다양성 */

class Superhero
{
    public :
    virtual void shoutSound() { cout << "우리는 영웅입니다.\n"; }
};
class Avengers : public Superhero
{
    public :
    void shoutSound() { cout << "우리는 어벤져스입니다. \n"; }
};
class JusticeLeague : public Superhero
{
    public :
    void shoutSound() { cout << "우리는 저스티스리그입니다. \n"; }
};




/* 자료구조를 클래스로 정의하는 법*/
class Car
{
    public:
        virtual int getNumWheels() = 0;
        virtual int getNumDoors() = 0;
};
class SUV: public Car
{
    public:
        int getNumWheels(){ cout << "SUV의 바퀴는 4개입니다\n"; }
        int getNumDoors(){ cout << "SUV의 문은 5개입니다\n"; }
};

int main()
{
    /* superhero포인터로 shoutsound라는 함수 호출함
     어떤거는 어벤져스라고 호출되고 어떤거는 저스티스리그라고 호출이 됨, 이 것을 cpp의 다용성이라고함,
     주어진 크래스에 따라서, 서브클래스에따라서 반응을 다르게 할 수 있게 만듦, 프로그램을 유연하게 만들어주는 성질 */
    Superhero* pIronman = new Avengers;
    Superhero* pSuperman = new JusticeLeague;
    pIronman -> shoutSound();
    pSuperman -> shoutSound();
    
    
    
    
    /* 자료구조를 클래스로 정의하는 법*/
    Car * suv = new SUV();
    suv -> getNumDoors();
    return 0;
}
