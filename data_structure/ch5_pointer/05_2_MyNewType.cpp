// 클래스의 객체를 포인터로 조작하는 프로그램
#include <cstdio>
struct MyNewType {
    int i;
    float f;
};
int main(){
    MyNewType s, *ps;
    ps = &s;            // 객체 s의 주소를 ps에 저장
    ps -> i = 2;        // (*ps).i = 2; 와 동일
    ps -> f = 3.14f;    // (*ps).f = 3.14f;와 동일
}