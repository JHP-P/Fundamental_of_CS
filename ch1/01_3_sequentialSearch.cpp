int sequentialSearch(int list[], int n, int key)
{
    for (int i=0; i<n; i++)
        if(list[i]==key)
            return i;   // 탐색에 성공하면 키 값의 인덱스 반환
        
    return -1;          // 탐색에 실패하면 -1 반환
}