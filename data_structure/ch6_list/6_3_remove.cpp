// 리스트의 pos번째 요소 삭제
void remove (int pos)
{
    if ( !isEmpty() && 0<= && pos<length)
    {
        for(int i = pos + 1 ; i < length ; i++)
            data[i-1] = data[i];
        length--;
    }
    else error("공백상태 오류 도는 삭제위치 오류")
}