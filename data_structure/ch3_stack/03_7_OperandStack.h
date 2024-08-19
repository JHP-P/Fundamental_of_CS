// 후위 표기 수식의 계산을 위한 피연산자 스택 클래스  // OperandStack.h : 피연산자 스택 클래스
#include <cstdio>
#include <cstdlib>
const int MAX_STACK_SIZE = 100; // 스택의 최대 크기 설정
inline void error(char *str) { printf("%s\n", str); exit(1);}
class OperandStack 
{
    double  data[MAX_STACK_SIZE];   // 요소의 배열
    int     top;                    // 요소의 개수
public:
    OperandStack() { top = -1; }  // 스택 생성자
    bool isEmpty()  { return top == -1; }
    bool isFull()   { return top == MAX_STACK_SIZE-1; }
    void push (double e) {
        if( isFull() ) error ("스택 포화 에러");
        data[++top] = e;
    }
    double pop () {
        if (isEmpty()) error ("스택 공백 에러");
        return data[top--];
    }
};