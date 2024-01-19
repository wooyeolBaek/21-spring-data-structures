#pragma once
#include <iostream>
#include <string>
//학생자료형 정의
class Student{
    protected:
        int id; //학번
        std::string name; // 이름
        std::string dept; // 학과
    public:
        Student(int i=0, std::string nam="", std::string dep=""){
            set(i, nam, dep);
        }
        void set(int i, std::string nam, std::string dep){
            id = i;
            name = nam;
            dept = dep;
        }
        void display(){
            std::cout << "학번 : " << id << " 성명 : " << name << " 학과 : " << dept << "\n";
        } 
        std::string contents(){//컨텐츠, 컨텐츠 전체를 string으로 넘겨줌, 단순자료형이 아니라 나중에 출력할 떄 필요할지도 몰라서 만듦
            std::string str;
            str = "학번 : " + std::to_string(id) + " 성명 : "+ name + " 학과 : " + dept;
            return str;
        }
        //연산자 오버로딩, ArrayStackTemplate에서 사용
        friend std::ostream& operator<<(std::ostream& os, Student& st);
};
std::ostream& operator<<(std::ostream& os, Student& st){
    os << st.contents();
    return os;
}