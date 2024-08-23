// LinkedStack.h : 연결된 스택 클래스 구현
#include "Node.h"   // Node 클래스 포함
class LinkedStack {
    Node*   top;    // 헤드 포인터
public:
    LinkedStack() { top=NULL; }     // constructor
    ~LinkedStack() {while(!isEmpty()) delete pop(); } // destructor
    bool isEmpty() { return top==NULL; }
    void push( Node *p ) {
        if( isEmpty() ) top = p;
        else {
            p->setLink(top);
            top = p;
        }
    }
    Node* pop() {
        if (isEmpty() ) return NULL;
        Node *p = top;
        top = top->getLink();
        return p;
    }
    Node* peek()    {return top;}
    void display() {                        // 화면 출력
        printf("[LinkedStack]\n");
        for( Node *p = top; p != NULL; p=p->getLink() )
            p->display();
        printf( "\n");
    }
};