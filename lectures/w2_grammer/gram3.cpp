//
//  main.cpp
//  cpp_grammer_3
//
//  Created by Wooyeol Baek on 3/23/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/* 가상함수, 클래스 개념에서 사용되는 것 */
class SuperHero
{
    public : //변수는 아에 없고 메소드만 있게 만듦, 가상함수가 어떻게 작동하는지만 보이려고함
        void getFamily() { cout << "우리는 영웅입니다. \n"; } // 클래스 안의 getfamily라는 함수
        virtual void getClass() { cout << "나는 영웅입니다. \n"; } /* 클래스 안의 getClass라는 함수, virtual을 앞에 추가,
        상속받은 함수는 같은형태의 함수를 가지고 있을 때 상속받은 함수인지 검사를하고 상속받은 class이면 상속받은 class쪽에 있는 메소드를 우선적으로 사용한다. 이것을 가상함수라고 함, 상위변수(getClass())와 하위변수(getClass())가 완전히 같아야 사용 가능
*/
};
class Avengers : public SuperHero // avengers 는 superhero 클래스를 상속함
{
    public :
        void getClass() { cout << "나는 어벤져스입니다. \n"; }
};
class Ironman : public Avengers // avengers 는 superhero 클래스를 상속함
{
    public :
        void getClass() { cout << "나는 아이언맨입니다. \n"; }
        void getDerived() { cout << "나는 영웅이고 어벤져스입니다. \n"; }
};
void whatIsMyClass(SuperHero *superhero)
{
    superhero -> getClass(); // superhero의 클래스를 불러오는 함수
};


int main()
{
    SuperHero *superhero = new SuperHero;
    Avengers *avengers = new Avengers;
    superhero -> getClass();
    avengers -> getClass();
    
    whatIsMyClass(superhero);
    whatIsMyClass(avengers);
    
    Avengers spiderman;
    Ironman suit_mark1;
    Avengers *pSpiderman = &spiderman;
    Ironman *pIronman = &suit_mark1;
    
    pSpiderman -> getFamily();
    pSpiderman -> getClass();
    
    pIronman -> getFamily();
    pIronman -> getClass();
    /* 즉 자기한테 가장 중요한 속성이 가장 마지막에 상속된 속성 */
    

    return 0;
}
