// int형 2차원 배열 동적 할당 함수
int** alloc2DInt (int rows, int cols)
{
    if( rows <= 0 || cols <= 0 ) return NULL;

    int** mat = new int* [ rows ];  // 포인터 변수를 저장할 배열
    for (int i=0; i<rows; i++)
        mat[i] = new int [cols];    // 실제 각 행의 데이터를 저장할 배열
    return mat;
}