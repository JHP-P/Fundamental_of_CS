checkMatching(expr)

while (입력 expr의 끝이 아니면) do
    /* code */
    ch expr의 다음 글자;
    switch(ch)
        case '(': case '[': case '{'
            ch를 스택에 삽입;
            break;
        caes ')': case ']': case'}':
            if (스택이 비어있으면)
                then 오류;
                else 스택에서 open_ch를 꺼냄
                    if (ch와 open_ch가 같은 짝이 아니면)
                        then 오류 보고;
            break;
if(스택이 비어있지 않으면)
    then 오류 보고;