// Node.h : 연결리스트로 구현된 리스트를 위한 노드 클래스
#include <cstdio>
class Node
{
    Node* link;
    int data;
public:
    Node( int val = 0) : data(val), link(NULL) {}
    Node* getLink() 
    {
        return link;
    }
    
    void setLink(Node* next)
    {
        link = next;
    }
    
    void display()
    {
        printf(" <%2d>", data);
    }
    
    bool hasData(int val)
    {
        return data == val;
    }

    // 자신의 다음에 새 노드 n을 삽입하는 function
    void insertNext( Node *n)
    {
        if( n != NULL)
        {
            n->link = link;
            link = n;
        }
    }

    // 자신의 다음 노드를 리스트에서 삭제하는 function
    Node* removeNext()
    {
        Node* removed = link;
        if(removed != NULL)
            link = removed->link;
        return removed;
    }
};