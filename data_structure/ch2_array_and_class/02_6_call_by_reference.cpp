// 레퍼런스를 이용한 두 변수의 교환 함수
#include <cstdio>
void swap(int &x, int& y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
int main(){
    int a=1, b=2;
    printf("swap을 호출하기 전: a=%d, b=%d\n", a, b);
    swap(a, b);
    printf("swap을 호출한 다음: a=%d, b=%d\n", a, b);
}