#include <iostream>
#include <vector>
#include <array> //array 표준자료형으로도 있음

/*
 변수의 이름 정하는 방법
 1. 카멜케이스 (lower 카멜케이스): lowerCamelCase형태
 2. Upper 카멜케이스 / 파스칼케이스 : UpperCamelCase 형태
 3. 스네이크케이스 : snake_case 형태로 _활용
 4. 헝가리안 표기법 : 변수 앞에 변수의 타입을 씀, char 타입이면: chAaaBbb, double이면: dbAaaBbb, boolean이면: b형태
 */


//1d 배열에서 최대값을 받아 반환하는 함수
int findMaxVal(int a[], int len){
    std::cout << a << "\n"; //주소값 출력
    int maxVal = a[0]; // 첫번째값 = 임시 저장하는 최대값
    for(int i = 1; i < len; i++){
        if( maxVal < a[i]){
            maxVal = a[i];
        }
    }
    return maxVal;
}
//배열의 함수는 무조건 배열의 길이를 같이 받아야함
//배열의 길이를 나중에 확인하는게 불가능하기 때문

// 같은 것 벡터로 만들어보기
int findMaxValueVector(std::vector<int> &v)
{
    int maxVal = v[0];
    for(int i = 1; i < v.size(); i++)
    {
        if( maxVal < v[i])
        {
            maxVal = v[i];
        }
    }
    return maxVal;
}
//C++ 11 이후에 std::array가 있음
//이건 size를 같이 인수로 엄겨줄 필요가 없음
//대신 template으로 함수를 만들어야함

// array함수 정의
template<std::size_t SIZE> // SIZE를 정수로 넣을거 아니면 이런식으로 변수로 지정해주어야 작동하고 변경도 가능
int findMaxValueSTD(std::array<int, SIZE> &a) //SIZE를 모르는 상태여도 이런식으로 루프를 돌릴 수 있음
{
    int maxVal = a[0];
    for(int i = 1; i < a.size(); i++)
    {
        if(maxVal < a[i])
        {
            maxVal = a[i];
        }
    }
    return maxVal;
}



int main()
{
    //main함수는 컴파일러가 제일먼저 실행하는 함수
    int arr[10] = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
    int maxVal = findMaxVal(arr, 10);
    std::cout << "array의 최대 값은 : " << maxVal << "\n";
    
    std::vector<int> v_arr = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
    int v_maxVal = findMaxValueVector(v_arr);
    std::cout << "vector의 최대 값은 : " << v_maxVal << "\n";

    std::array<int, 10> s_arr = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
    int s_maxVal = findMaxValueSTD(s_arr);
    std::cout << "array의 최대 값은 : " << s_maxVal << "\n";
    
}
