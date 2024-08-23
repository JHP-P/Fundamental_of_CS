// LinkedStack.cpp : linkedstack class
#include "05_9_LinkedStack.h"
int main()
{
    LinkedStack stack;
    stack.push( new Node(20121111, "홍길동", "ComputerEngineering"));
    stack.push( new Node(20112222, "이순신", "MechatronicsEngineering"));
    stack.push( new Node(20103333, "이원복", "법학과"));
    stack.display();

    Node *node = stack.pop();
    printf("[Pop항목]\n]");
    node->display();
    printf("\n");
    delete node;
    stack.display();
}