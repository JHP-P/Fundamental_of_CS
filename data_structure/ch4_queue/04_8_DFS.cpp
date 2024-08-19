// STL의 덱을 이용한 미로 탐색 프로그램(깊이 우선 탐색, DFS-Depth First Search)
#include "Location2D.h"                 // 위치 클래스 포함
#include <deque>                        // STL의 deque 템플릿 파일 포함
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
int main(){
    deque<Location2D> locDeque;             // 위치 덱 객체 생성
    Location2D entry(1, 0);                 // 입구 객체
    locDeque.push_front(entry);             // 덱에 입구 위치 삽입

    while (locDeque.empty() == false) {
        Location2D here = locDeque.front();
        locDeque.pop_front();
        int r = here.row;                       
        int c = here.col;
        printf("(%d,%d) ", r, c);
        if(map[r][c] == 'x') {
            printf(" 미로 탐색 성공\n");
            return 0;
        }
        else {
            map[r][c] = '.';
            if(isValidLoc(r-1, c)) locDeque.push_front(Location2D(r-1, c));
            if(isValidLoc(r+1, c)) locDeque.push_front(Location2D(r+1, c));
            if(isValidLoc(r, c-1)) locDeque.push_front(Location2D(r, c-1));
            if(isValidLoc(r, c+1)) locDeque.push_front(Location2D(r, c+1));
        }
    }
    printf("미로탐색실패\n");
}