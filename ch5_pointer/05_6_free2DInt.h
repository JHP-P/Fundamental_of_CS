// int형 2차원 배열 동적 해제 함수
void free2DInt (int **mat, int rows, int cols = 0){
    if ( mat != NULL ) {
        for( int i=0; i<rows; i++)
            delete [] mat[i];
        delete [] mat;
    }
}