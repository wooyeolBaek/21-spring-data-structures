#include <stack>
#include <iostream>

const int MAZE_SIZE = 6;
//정방형의 미로 정의
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '1', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '0', '0'},
    {'1', '0', '1', '0', '1', 'x'},
    {'1', '1', '1', '1', '1', '1'}
    //이렇게 하는 이유는, 출구를 따로 표시해 주기 위해서
    //입구 = e, 출구 = x, 갈 수 있는 곳 = 0, 못 가는 곳 = 1
};

struct Location2D{
    int row;
    int col; // row,col은 임의의 좌표
    Location2D(int r = 0, int c = 0){ 
        row = r; 
        col = c;
    }
    bool isNeighbor(Location2D &p){ //이웃에 있는지 검사하는 알고리즘, Location2D의 어떤 포인터(p)에 대해서
    // row와col이 있는 어떤 자료형에 
        return((row == p.row && col ==  p.col-1) ||
        (row == p.row && col == p.col+1) ||
        (row == p.row-1 && col == p.col) ||
        (row == p.row+1 && col == p.col)
        ); //특정 위치가 주어진 점과 이웃하냐 아니냐하는 것은 col과 row가 하나씩만 차이나면 됨
    }
    //오퍼레이터를 연산자 오버로딩으로 2d비교로 사용
    bool operator == (Location2D &p){ 
    //Locations의 두개의 좌표를 각각 비교는 귀찮으니까, 2D Location이 같은지 확인하는 좌표를 만듦
        return row == p.row && col == p.col; 
        //row로 같고 col도 같을 때만 참값을 반환하는 operator 연산자 오버로딩
    }
};

//이동할 수 있는 위치인지 확인
bool isValidLoc(int r, int c){
    if(r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE){
        return false; // 범위밖의 r,c걸러내기
    }
    else return map[r][c] == '0' || map[r][c] == 'x';
    //지나 갈 수 있는 길은 참값 반환 
}

int main(){ //스택을 쓰는데 템플릿과 아주 유사하게 사용 가능
    std::stack<Location2D> locStack;
    Location2D entry(1,0); // e위치, 출발
    locStack.push(entry); //현재위치 넣기 
    while(locStack.empty() == false){ //비어있지 않는 동안
        Location2D here = locStack.top(); //현재위치는 항상 최상단 
        locStack.pop(); // 표준자료형 stack이라 pop, top따로 써줘야함
        int r = here.row; //현재의 row
        int c = here.col; //현재의 col

        std::cout << "(" << r << ", " << c << ") ";  //현재 위치 출력
        if(map[r][c] == 'x'){//현재 위치가 x 라면
            std::cout << "탈출에 성공했습니다. \n";
            return 0;
        }
        else{
            map[r][c] = '.'; // 갔다온 점 표시해주기
            if(isValidLoc(r-1, c)){ locStack.push(Location2D(r-1, c));}  //내 주변이 갈 수 있는지 없는지 확인
            if(isValidLoc(r+1, c)){ locStack.push(Location2D(r+1, c));}
            if(isValidLoc(r, c-1)){ locStack.push(Location2D(r, c-1));}
            if(isValidLoc(r, c+1)){ locStack.push(Location2D(r, c+1));}
        }//안가봤는데 갈 수 있는 곳 스택에 집어 넣기
    }
    std::cout << "탈출에 실패했습니다. \n";
    return 0;
}
