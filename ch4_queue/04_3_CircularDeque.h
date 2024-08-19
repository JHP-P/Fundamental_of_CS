// CircularDeque.h : CircularQueue클래스를 상속해서 구현한 원형 덱 클래스
#include "04_1_CircularQueue.h"

class CircularDeque : public CircularQueue {
public:
    CircularDeque() {}
    void addRear(int val)   { enqueue(val);}        // enqueue() 호출
    int deleteFront()       { return dequeue(); }   // dequeue() 호출
    int getFront()          { return peek(); }      // peek() 호출
    void addFront( int val ) {                      // 전단에 삽입
        if( isFull() )
            error(" error: 덱이 포화상태입니다.\n ");
        else {
            data[front] = val;
            front = (front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        }
    }
    int deleteRear() {                              // 후단에서 삭제
        if( isEmpty() )
            error(" Error: 덱이 공백상태입니다.\n");
        else{
            int ret = data[rear];
            rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            return ret;
        }
    }
    int getRear(){          // 후단에서 peek
        if( isEmpty() )
            error(" ERROR: 덱이 공백 상태입니다.\n");
        else return data[rear];    
    }
    void display(){                 // 04_1_CircularQueue::display()를 재정의  
        printf( "덱의 내용 : ");    // 이 출력 코드만 다름
        int maxi = (front<rear) ? rear : rear+MAX_QUEUE_SIZE;
        for (int i = front+1; i <=maxi; i++)
            printf( "[%2d] ", data[i%MAX_QUEUE_SIZE]);
        printf("\n");
    }
};
