#include <iostream>

int* alloc2DInt(int rows, int cols){
    //동적할당으로 2차원 배열 만들기
    //포인터의 포인터, ** 만들기
    if(rows <= 0 || cols <= 0){
        return nullptr;
    }
    int** mat = new int* [rows]; //int 포인터를 저장할 배열 만듦
    for(int i=0; i<rows; i++){
        mat[i]=new int [cols]; //실제 각 행의 데이터를 저장할 배열 만듦
    }
    return *mat; //오류떠서 바꿈
}

void free2DInt(int **mat, int rows, int cols = 0){
    //할당된 메모리 해제 중요, 안할 시 메모리 누수 발생
    if(mat != nullptr){
        for(int i=0; i<rows; i++){
            delete [] mat[i]; // array를 지울 때 delete [] 잊지 않기
        }
        delete [] mat;
    }
}

void set2DRandom(int** mat, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void print2DInt(int** mat, int rows, int cols){
    std::cout << "행의 수 = " << rows << ", 열의 수 = " << cols << "\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int** mat;
    int rows, cols;
    std::cout << "행과 열의 크기를 입력하시오: ";
    std::cin >> rows >> cols;
    *mat = alloc2DInt(rows, cols);
    set2DRandom(mat, rows, cols);
    print2DInt(mat, rows, cols);
    free2DInt(mat, rows, cols);
    return 0;


}