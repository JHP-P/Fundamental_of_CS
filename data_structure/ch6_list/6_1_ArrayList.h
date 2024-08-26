#include <cstdio>
#define MAX_LIXT_SIZE 100

class ArrayList {
    int data[MAX_LIXT_SIZE];
    int length;
public:
    ArrayList(void) {length=0;}

    // 삽입 연산: 리스트의 pos번째에 항목 e 추가
    void insert( int pos, int e) 
        {
        if( !isFull() && pos >= 0 && pos<=length )
        {
            for( int i=length ; i>pos ; i--)
                data[i] = data[i-1];    // 뒤로 한칸씩 밀기
            data[pos] = e;              // 
            length++;
        }
        else printf("포화상태 오류 또는 삽입 위치 오류");
    }

    // 삭제 연산: pos번째에 항목을 리스트에서 제거
    void remove( int pos) 
    {
        if ( !isEmpty() && 0<=pos && pos<length)
        {
            for(int i = pos + 1 ; i < length ; i++)
                data[i-1] = data[i];
            length--;
        }
        else printf("공백상태 오류 도는 삭제위치 오류");
    }

    int getEntry(int pos) { return data[pos];}
    bool isEmpty(){ return length==0;}
    bool isFull(){ return length==MAX_LIXT_SIZE;}
    bool find( int item )   // item 항목 유무 검사
    {
        for(int i = 0; i < length ; i++)
            if(data[i] == item) return true;
        return false;
    }
    void replace(int pos, int e)    // pos위치의 요소 변경
    {
        data[pos] = e;
    }
    int size() { return length; }   // 리스트의 길이 반환
    void display()                  // 화면에 출력
    {
        printf( "[배열로 구현한 리스트 전체항목 수 = %2d] : ", size());
        for( int i=0; i < size(); i++)
            printf( "[%2d] ", data[i]);
        printf( "\n");
    }
    void clear()
    { length = 0;}  // 모든 요소 제거
};