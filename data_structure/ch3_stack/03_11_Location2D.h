// STL을 이용한 미로 탐색 프로그램
#include "Location2D.h"
#include <stack>
using namespace std;
const   int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};
// (r, c)가 갈 수 있는 위치인지 검사하는 함수
// (r, c)가 배열안에 있고, 값이 갈 수 있는 위치 '0'이거나 출구 'x'이어야 함
bool isValidLoc( int r, int c ) {
    if( r<0 || c<0 || r>=MAZE_SIZE || c>=MAZE_SIZE ) return false;
    else return map[r][c] == '0' || map[r][c] == 'x' ;
}
// 미로 탐색 프로그램 주 함수
int main() {
    stack<Location2D> locStack;
    Location2D entry(1, 0);
    locStack.push(entry);

    while (locStack.empty() == false) {
        Location2D here = locStack.top();
        locStack.pop();

        int r = here.row;
        int c = here.col;
        printf("(%d,%d) ", r, c);
        if(map[r][c] == 'x') {
            printf(" 미로 탐색 성공\n");
            return 0;
        }
        else {
            map[r][c] = '.';
            if( isValidLoc( r-1, c ) ) locStack.push(Location2D(r-1, c));
            if( isValidLoc( r+1, c ) ) locStack.push(Location2D(r+1, c));
            if( isValidLoc( r, c-1 ) ) locStack.push(Location2D(r, c-1));
            if( isValidLoc( r, c+1 ) ) locStack.push(Location2D(r, c+1));
        }
    }
    printf("미로 탐색 실패\n");
}