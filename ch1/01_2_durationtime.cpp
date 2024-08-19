#include <cstdio>
#include <cstdlib>
#include <ctime>
int main(void)
{
    clock_t start, finish;
    double duration;
    start = clock();
        // 실행시간을 측정하고자 하는 코드
        // 화면 출력문은 제외시켜야 함에 유의할 것
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f 초입니다.\n", duration);

    return 0;
}