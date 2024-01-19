#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int main()
{
  //난수로 배열 만들기
    int myArr[20];
    cout << "myArray = [";
    for(int i = 0; i < 20; ++i)
    {
        myArr[i] = (rand() % 100);
        cout << myArr[i] << ", ";
    }
    cout << "]" << "\n";
    
    // 배열의 최대값 찾기
    int max = myArr[0];
    int num;

    for(int i = 0; i < 20; ++i)
    {
        if(max < myArr[i])
        {
            max = myArr[i];
            num = i;
        }
        else
        {
        }
    }
    cout << "myArray 는 " << max << "의 최댓값을 " << num << "자리에서 가집니다." << "\n";
    
    
    
    return 0;
}
