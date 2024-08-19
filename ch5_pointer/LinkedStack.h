// LinkedStack.h : 연결리스트로 구현된 스택클래스 (연결된 스택 클래스 구현)
#include "Node.h"   
class LinkedStack {
    Node*   top;
public:
    LinkedStack()   { top = NULL; }
    ~LinkedStack()  { while( !isEmpty()) delete pop(); }
    
}