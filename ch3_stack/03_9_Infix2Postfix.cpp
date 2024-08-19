// 중위 표기 수식을 후위 표기로 변환하는 프로그램
#include "03_1_ArrayStack.h"    // 

// 객체의 우선순위 계산
inline int precedence( char op ) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;   // 우선순위 중간
        case '*': case '/': return 2;   // 우선순위 높음
    }
    return -1;
}
// 중위 표기 수식을 후위 표기 수식으로 변환하는 함수
void infix2Postfix(FILE *fp = stdin) {
    char        c, op;
    double      val;
    ArrayStack  st;

    while ( (c=getc(fp)) != '\n' ) {    // 엔터 문자 입력 전까지
        // 피연산자면 -> 그대로 출력
        if ((c>='0' && c<='9')) {       // 연산항(숫자)의 시작이면
            ungetc( c, fp );            // 문자를 돌려놓고
            fscanf( fp, "%lf", &val);   // double로 다시 읽음
            printf("%4.1f ", val);
        }
        // '(' 이면 -> 스택에 삽입
        else if ( c=='(' ) st.push( c );
        // ')'이면 -> '('가 나올때까지 연산자 출력
        else if (c == ')' ) {
            while (!st.isEmpty()) {
                op = st.pop();
                if ( op=='(') break;
                else printf( "%c ", op );
            }
        }
        // 연산자('+', '-', '/', '*'이면 -> 우선순위 비교처리
        else if ( c == '+' || c == '-' || c == '*' || c == '/' ) {
            while (!st.isEmpty()) {
                op = st.peek();
                if ( precedence(c) <= precedence(op)) {
                    printf( "%c ", op );
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }
    while (!st.isEmpty())
        printf( "%c ", st.pop());
    printf( "\n");
}
int main() {
    printf("수식입력 (Infix) = ");
    infix2Postfix();                // infix 수식을 postfix로 변환
}