// 포인터를 함수의 파라미터로 사용하여 두 변수의 값 교체
#include <cstdio>
void swap(int* px, int* py){
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main(){
    int a = 1, b = 2;
    printf("swap을 호출하기 전 : a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("swap을 호출한 다음 : a = %d, b = %d\n", a, b);
}