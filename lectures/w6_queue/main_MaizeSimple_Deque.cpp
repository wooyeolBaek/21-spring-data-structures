//Queue랑 int main 전까지 다 똑같음
#include <iostream>
#include <queue> //큐를 규현 안하고 표준자료형에 있는 걸로 씀

struct Location2D{ //지난번 미로에서 만든거 그대로 가져옴
    int row;
    int col;
    Location2D(int r=0, int c=0){row = r; col = c;}
    bool isNeighbor(Location2D &p){
        return((row == p.row && (col == p.col-1 || col == p.col+1))
        || (col == p.col && (row == p.row-1 || row == p.row+1)));
    }// == 오퍼레이터를 연산자 오버로딩을 통해 2d 비교로 사용합니다.
    bool operator == (Location2D &p){return row == p.row && col == p.col;}
};
 
 const int MAZE_SIZE = 6; //w5_stack/location에서 만든거 그대로 가져옴
char map[MAZE_SIZE][MAZE_SIZE] = {//입구 = e, 출구 = x, 갈 수 있는 곳 = 0, 못 가는 곳 = 1
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '1', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '0', '0'},
    {'1', '0', '1', '0', '1', 'x'},
    {'1', '1', '1', '1', '1', '1'}
};
bool isValidLoc(int r, int c){//이거도 그대로 가져옴
    if(r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE){return false;}
    else{return map[r][c] == '0' || map[r][c] == 'x';}
}

int main(){
    std::deque<Location2D> locDeque; //자료형만 deque로 바뀜
    Location2D entry(1,0); //entry(시작점,현재위치)만들기
    locDeque.push_front(entry); // 시작점, entry 넣기
    while(locDeque.empty() == false){
        Location2D here = locDeque.front();//너비 우선 탐색
        locDeque.pop_front(); 

        int r = here.row;
        int c = here.col;
    std::cout << "(" << r << "," << c << ") ";

    if(map[r][c] == 'x'){
        std::cout << "탈출에 성공했습니다. \n";
        return 0;
    }
    else{
        map[r][c] = '.'; //현재위치 .로 바꾸기, 이미 갔다고 표시하는 것
        //이동 가능한 이웃, 우선순위대로 기록
        //너비우선탐색
        if(isValidLoc(r-1,c)){locDeque.push_back(Location2D(r-1,c));}
        if(isValidLoc(r+1,c)){locDeque.push_back(Location2D(r+1,c));}
        if(isValidLoc(r,c-1)){locDeque.push_back(Location2D(r,c-1));}
        if(isValidLoc(r,c+1)){locDeque.push_back(Location2D(r,c+1));}
        /* 깊이우선탐색 
        if(isValidLoc(r-1,c)){locDeque.push_front(Location2D(r-1,c));}
        if(isValidLoc(r+1,c)){locDeque.push_front(Location2D(r+1,c));}
        if(isValidLoc(r,c-1)){locDeque.push_front(Location2D(r,c-1));}
        if(isValidLoc(r,c+1)){locDeque.push_front(Location2D(r,c+1));}
        */
    }


    }

    return 0;
}
