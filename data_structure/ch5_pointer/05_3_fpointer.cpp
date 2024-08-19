// 함수 포인터
#include <cstdio>
void foo( int a){
    printf("foo : %d\n", a);
}
int main(){
    // fp는 함수의 주소를 담는 Pointer type이다.
    void (*fp)(int);
    fp = foo;
    fp(10);          // == foo(10)
    (*fp)(10);       // == fp(10)
}