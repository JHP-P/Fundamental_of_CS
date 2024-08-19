// 후위 표기 수식의 계산 함수와 테스트 프로그램
#include "03_7_OperandStack.h"
// 입력으로부터 후위 표기 수식을 읽어 계산하는 함수
double calcPostfixExpr( FILE *fp = stdin)   {
    char         c;
    OperandStack st;

    while ( ( c = getc(fp) ) != '\n' )
    {
        if (c == '+' || c == '-' || c == '*' || c == '/')   {
            double val2 = st.pop();
            double val1 = st.pop();
            switch(c){
                case '+': st.push( val1 + val2 ); break;
                case '-': st.push( val1 - val2 ); break;
                case '*': st.push( val1 * val2 ); break;
                case '/': st.push( val1 / val2 ); break;
            }
        }
        else if ( c>='0' && c <= '9') {
            ungetc(c, fp);
            double val;
            fscanf( fp, "%lf", &val );
            st.push( val );
        }
    }
    return (st.pop());
}

int main(){
    printf("수식 입력 (Postfix) = ");
    double res = calcPostfixExpr();      // PostFix수식계산
    printf("계산 결과 => %f\n", res);     // 결과를 화면에 출력
}