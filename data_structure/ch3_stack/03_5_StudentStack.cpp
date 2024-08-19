#include "03_4_StudentStack.h"
int main(){
    StudentStack stack;
    stack.display();
    stack.push( Student(20071111, "홍길동", "컴퓨터과학과"));
    stack.push( Student(20071222, "이순신", "전자공학과"));
    stack.push( Student(20071333, "이이", "기계공학과"));
    stack.display();
    stack.pop();
    stack.display();
}