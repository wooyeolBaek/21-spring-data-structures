#include <iostream>

void hanoiTower(int n, char from, char tmp, char to){
    if(n==1){
        std::cout << "원판 1을 " << from << " 에서 " << to << "로 옮깁니다. \n";
    }
    else{
        hanoiTower(n-1, from, to, tmp);
        std::cout << "원판 " << n << "을 " << from << " 에서 " << to << "로 옮깁니다. \n";
        hanoiTower(n-1, tmp, from, to);
    }
}

int hanoiTower2(int n, char from, char tmp, char to){
    if(n==1){
        //std::cout << "원판 1을 " << from << " 에서 " << to << "로 옮깁니다. \n";
        return 1;
    }
    else{
        int val1 = hanoiTower2(n-1, from, to, tmp);
        //std::cout << "원판 " << n << "을 " << from << "에서 " << to << "로 옯깁니다. \n";
        int val2 = hanoiTower2(n-1, tmp, from, to);
        return val1 + val2;
    }
}

int main(){
    std::cout << "하노이 타워 1  \n";
    hanoiTower(4, 'A', 'B', 'C');
    std::cout << "\n";
    std::cout << "하노이 타워 2  \n";
    std::cout << hanoiTower2(10, 'A', 'B', 'C') << "\n";
    return 0;
}