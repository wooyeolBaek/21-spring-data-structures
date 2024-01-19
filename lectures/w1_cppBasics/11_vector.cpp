//C++의 vector
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void){
    vector <int> lottoNumVec(6);
    int lottoNumArray[6] = {10,23,25,31,38,40};
    lottoNumVec.insert(lottoNumVec.begin(), lottoNumArray, lottoNumArray + 3); //앞의 3개만 복사
    cout << lottoNumVec[2] << "\n"; //2자리의 값
    cout << lottoNumVec.at(2) << "\n"; //2자리의 값

    lottoNumVec.insert(lottoNumVec.begin()+4, 44);//앞에 3개만 복사
    for(int i; i < 10; i++){
        cout << i << "번 째 값 :" << lottoNumVec.at(i) << "\n";
    }
    cout << lottoNumVec.at(4) << "\n";

    cout << lottoNumVec.size() << "\n"; //Vector의 값을 추출
    lottoNumVec.push_back(45); //앞의 3개만 복사
    cout << lottoNumVec.size() << "\n";
    cout << lottoNumVec.back() << "\n"; //마지막 값을 출력
    cout << lottoNumVec.front() << "\n"; //처음 값을 출력
    cout << lottoNumVec.empty() << "\n"; //비어있으면 true(1), 차있으면 flase(0)

    return 0;

    
}