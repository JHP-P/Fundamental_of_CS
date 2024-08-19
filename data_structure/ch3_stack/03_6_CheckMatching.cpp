// 괄호 검사 프로그램
#include "03_1_ArrayStack.h"

// 주어진 파일을 읽어 괄호 매칭을 검사하고 결과를 출력하는 함수
bool checkMatching(char* filename){
    FILE *fp = fopen(filename, "r");
    if(fp==NULL)
        error("Error: 파일이 존재하지 않습니다.");

    int nLine = 1;  // 읽은 라인의 개수
    int nChar = 0;  // 읽은 문자 개수
    ArrayStack stack;   // 스택 객체
    char ch;

    while ((ch=getc(fp)) !=EOF){
        if(ch=='\n') nLine++;
        nChar++;
        if(ch=='[' || ch=='(' || ch=='{')
            stack.push(ch);
        else if (ch==']' || ch==')' || ch=='}') {
            int prev = stack.pop();
            if ( (ch==']' && prev !='[' )
            ||   (ch==')' && prev !='(' )
            ||   (ch=='}' && prev !='{' )) break;
        }
    }
    fclose(fp);
    printf("[%s] 파일 검사결과:\n", filename );
    if (!stack.isEmpty())
        printf("Error: 문제발견! (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
    else
        printf("  OK: 괄호닫기 정상 (라인수=%d, 문자수=%d)\n\n", nLine, nChar);
    return stack.isEmpty();
}
// 주함수 : ArrayStack.h, CheckMatching.cpp의 두 파일 검사
int main(){
    checkMatching("03_1_ArrayStack.h");
    checkMatching("03_6_CheckMatching.cpp");
}