// LinkedQueue.h : 연결된 큐 클래스
#include "Node.h"
class LinkedQueue
{
    Node*   front;
    Node*   rear;
    public:
    LinkedQueue(): front(NULL), rear(NULL)
    { }
    ~LinkedQueue()
    { while(!isEmpty())
        delete dequeue(); 
    }

    // 삽입연산: 연결된 큐의 맨 뒤에 노드 삽입
    void enqueue (Node* p)
    {
        if( isEmpty())
            front = rear = p;
        else {
            rear->setLink(p);
            rear = p;
        }
    }

    // 삭제 연산: 연결된 큐의 맨 앞 노드르르 삭제
    Node* dequeue() {
        if (isEmpty() )
            return NULL;
        Node* p = front;
        front = front->getLink();
        if ( front == NULL )
            rear = NULL; return p;
    }

    Node* peek()
    {
        return front;
    }
    void display()
    {
        printf( "[큐내용] : ");
        for (Node* p = front; p != NULL; p=p->getLink())
            p->display();
        printf( "\n");
    }
};