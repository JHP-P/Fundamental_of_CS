// CircularQueue.h 배열을 이용한 원형 큐 클래스
#include <cstdio>
#include <cstdlib>
#define MAX_QUEUE_SIZE  100
inline void error(char* str) {
    printf("%s\n", str);
    exit(1);
}
// Customer.h : 하나의 고객 정보를 관리하기 위한 클래스
struct Customer {
    int id;
    int tArrival;
    int tService;
    Customer( int i = 0, int tArr = 0, int tServ = 0)
        : id(i), tArrival(tArr), tService(tServ) {}
};
class CircularQueue {
    protected:
    int front;                      // 첫 번째 요소 앞의 위치
    int rear;                       // 마지막 요소 위치
    Customer data[MAX_QUEUE_SIZE];       // 요소의 배열
public:
    CircularQueue() { front = rear = 0;}
    bool isEmpty()  { return front == rear; }
    bool isFull()   { return (rear+1) % MAX_QUEUE_SIZE == front; }
    void enqueue( Customer val ) {       // 큐에 삽입
        if( isFull() )
            error(" error: 큐가 포화상태입니다.\n");
        else {
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    Customer dequeue(){      // 첫 항목을 큐에서 빼서 반환
        if(isEmpty())
            error(" error: 큐가 공백상태입니다.\n");
        else {
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
    }
            }
    Customer peek(){     // 첫 항목을 큐에서 빼지 않고 반환
        if(isEmpty())
            error("Error: 큐가 공백상태입니다.\n");
        else
            return data[(front+1) % MAX_QUEUE_SIZE];
    }
    void display(){     // 큐의 모든 내용을 순서대로 출력
        printf("큐 내용 : ");
        int maxi = (front <rear) ? rear : rear+MAX_QUEUE_SIZE;
        for(int i = front+1 ; i<=maxi ; i++)
            printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
        printf( "\n");
    }
};