#include <iostream>
#include <array>

// 2d array
// 2차원 영상에서 최대 밝기 값을 찾아 반환하는 함수
int findMaxPixel(int a[][5], int h, int w){//array의 길이, [5]는 무조껀 채워야함
    int maxVal = 0; //영상의 최소 밝기 = 0
    for(int i = 0; i < h; i++){// nested loop, for 문 여러개로 만들어진 루프, 이해편하도록 이런식으로 쓰는 것, 포인터 사용하면 1d으로 할 수 있음
        for(int j = 0; j < w; j++){
            if(maxVal < a[i][j]){
                maxVal = a[i][j];
            }
        }
    }
    return maxVal;
}

//표준자료형으로 만들어보기
//표준자료형은 내부 변수로 다시 표준자료형을 가질 수 있음
template<std::size_t x_size, std::size_t y_size>
int findMaxPixelSTD(std::array<std::array<int, x_size>, y_size> &a){
    int maxVal = 0;
    for(int i = 0; i < x_size; i++){
        for(int j = 0; j < y_size; j++){
            if(maxVal < a[i][j]){
                maxVal = a[i][j];
            }
        }
    }
    return maxVal;
}

int main()
{
    int img[4][5] =
    {
        {3, 24, 82, 12, 22},
        {34, 7, 12, 19, 21},
        {99, 7, 65, 73, 58},
        {20, 7, 9, 48, 29}
    };
    
    int maxPixel = findMaxPixel(img, 4, 5);
    std::cout << maxPixel << "\n"; // 출력
    
    //표준자료형
    int maxPixel_2 = findMaxPixel(img, 4, 5);
    std::cout << maxPixel << "\n"; // 출력
    
    std::array < std::array < int, 5>, 4> std_img = {{ //표준자료형일때는 {{ 두개써야함
        {3, 24, 82, 12, 22},
        {34, 7, 12, 19, 21},
        {99, 7, 65, 73, 58},
        {20, 7, 9, 48, 29}
    }};
    
    maxPixel_2 = findMaxPixelSTD(std_img); //사이즈 안넣어도 됨, std_img => 사이즈 넣으려면 (img, 4,5)
    std::cout << maxPixel << "\n";
}
