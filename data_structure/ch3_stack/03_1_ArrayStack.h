// ArrayStack.h : 배열을 이용한 int 스택 클래스
#include <cstdio>
#include <cstdlib>

// 오류처리함수
inline void error(char *message){
    printf("%s\n", message);
    exit(1);
}

const int MAX_STACK_SIZE = 20;
class ArrayStack
{
    int top;
    int data[MAX_STACK_SIZE];
public:
    ArrayStack() {top = -1;}
    ~ArrayStack(){}
    bool isEmpty()  {return top==-1;}
    bool isFull()   {return top == MAX_STACK_SIZE-1;}

    void push (int e){                      // 맨 위에 항복 삽입
        if (isFull()) error ("스택 포화 에러");
        data[++top] = e;
    }

    int pop () {                            // 맨 위의 요소를 삭제하고 반환
        if (isEmpty()) error ("스택 공백 에러");
        return data[top--];
    }

    int peek (){                             // 삭제하지 않고 요소 반환
        if (isEmpty()) error ("스택 공백 에러");
        return data[top];
    }

    void display () {                         // 스택 내용을 화면에 출력
        printf("[스택 항목의 수 = %2d] ==> ", top+1);
        for (int i=0; i<=top; i++)
            printf("<%2d>", data[i]);
    }
};