// 리스트의 pos번째에 요소 e 추가
void insert( int pos, int e )
{
    if( !isFull() && pos >= 0 && pos<=length )
    {
        for( int i=length ; i>pos ; i--)
            data[i] = data[i-1];    // 뒤로 한칸씩 밀기
        data[pos] = e;              // 
        length++;
    }
    else error("포화상태 오류 또는 삽입 위치 오류");
}