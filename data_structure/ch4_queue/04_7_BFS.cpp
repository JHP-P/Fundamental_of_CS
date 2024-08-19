// STL의 큐를 이용한 미로 탐색 프로그램(그래프 탐색 - 너비 우선 탐색 'BFS, Breadth First Searchs)
#include "Location2D.h"     // 위치 클래스 포함
#include <queue>            // STL의 queue 템플릿 파일 포함
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
    queue<Location2D> locQueue;                 // 위치 큐 객체 생성
    Location2D entry(1, 0);                     // 입구 객체
    locQueue.push( entry );                     // 큐에 입구 위치 삽입

    while ( locQueue.empty() == false ) {       // 큐가 비어있지 않는 동안
        Location2D here = locQueue.front();     // 큐의 front 상단 객체 복사
        locQueue.pop();                         // 큐 상단 객체 삭제
        int r = here.row;                       
        int c = here.col;
        printf("(%d,%d) ", r, c);
        if(map[r][c] == 'x') {
            printf(" 미로 탐색 성공\n");
            return 0;
        }
        else {                                  // 출구가 아니면 현재 위치를
            map[r][c] = '.';                    // 현재 위치를 "지나옴" 처리"
            if( isValidLoc( r-1, c) ) locQueue.push(Location2D(r-1, c));
            if( isValidLoc( r+1, c) ) locQueue.push(Location2D(r+1, c));
            if( isValidLoc( r, c-1) ) locQueue.push(Location2D(r, c-1));
            if( isValidLoc( r, c+1) ) locQueue.push(Location2D(r, c+1));
        }
    }
    printf("미로 탐색 실패\n");
}