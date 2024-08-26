#include "Node.h"
class StudentQueue {
    Node*   front;
    Node*   rear;
public:
    StudentQueue() : front(NULL), rear(NULL) {}
    ~StudentQueue() { while(!isEmpty())
        delete dequeue(); 
    }
    bool isEmpty() { return front == NULL; }
    void enqueue (Node* n)
    {
        if( isEmpty())
            front = rear = n;
        else 
        {
            rear->setLink(n);
            rear = n;
        }
    }
    Node* dequeue()
    {
        if (isEmpty() )
            return NULL;
        Node* p = front;
        front = front->getLink();
        if ( front == NULL )
            rear = NULL; return p;
    }
    void display() {
        printf( "[전체 학생 정보]\n");
        for( Node* p = front; p != NULL ; p=p->getLink() )
        p->display();
        printf( "\n");
    }
};

// #include "05_StudentQueue.h"
int main()
{
    StudentQueue que;
    que.enqueue( new Node(20111111, "홍길동", "컴퓨터과학과"));
    que.enqueue( new Node(20222222, "리순신", "전기전자공학부"));
    que.enqueue( new Node(20112233, "강감찬", "법학과"));
    que.display();
    delete que.dequeue();
    que.display();
}