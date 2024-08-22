// Node.h : 연결된 스택을 위한 노드 클래스 구현 파일
#include "03_3_Student.h"
class Node : public Student {   // Student를 상속하여 구현함
    Node*   link;               // 다음 노드를 가리키는 포인터 변수
public:
    Node( int id=0, char* name="", char* dept="" )
        : Student(id, name, dept) { link = NULL; }
    ~Node(void) {}
    Node* getLink() {return link;}
    void setLink( Node *p ) { link = p; }
};