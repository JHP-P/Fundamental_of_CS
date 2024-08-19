// 2차원 배열 동적 할당 프로그램
#include <cstdio>
#include <cstdlib>
// int형 2차원 배열 동적 할당
int** alloc2DInt (int rows, int cols){
    if( rows <= 0 || cols <= 0 ) return NULL;

    int** mat = new int* [ rows ];  // 포인터 변수를 저장할 배열
    for (int i=0; i<rows; i++)
        mat[i] = new int [cols];    // 실제 각 행의 데이터를 저장할 배열
    return mat;
}
void free2DInt ( int **m, int r, int c = 0 ) {
    if ( m != NULL ) {
        for( int i=0; i<r; i++)
            delete [] m[i];
        delete [] m;
    }
}
void set2DRandom ( int **mat, int rows, int cols){
    for ( int i=0 ; i<rows ; i++ )
    for ( int j=0 ; j<rows ; j++ )
        mat[i][j] = rand()%100;
}
// 2차원 배열을 화면으로 보기 좋게 출력하는 함수
void print2DInt ( int **mat, int rows, int cols){
    printf("행의 수 = %d, 열의 수 = %d\n", rows, cols);
    for ( int i=0 ; i<rows ; i++ ){
        for ( int j=0 ; j<rows ; j++ )
            printf("%4d", mat[i][j]);
        printf( "\n" );
    }
}
// 주 함수 : 2차원 배열 동적 할당 테스트
int main(){
    int **mat;
    int rows, cols;

    printf( "행과 열의 크기를 입력하시오: ");
    scanf("%d%d", &rows, &cols);

    mat = alloc2DInt( rows, cols );
    set2DRandom( mat, rows, cols );
    print2DInt( mat, rows, cols );
    free2DInt( mat, rows, cols);
}