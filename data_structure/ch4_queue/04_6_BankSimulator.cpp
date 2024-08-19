// 은행 서비스 시뮬레이션 테스트 프로그램
#include <ctime>
#include <cstdio>
#include "04_5_BankSimulator.h"
int main(){
    srand( (unsigned int) time(NULL));
    BankSimulator sim;                  // 시뮬레이터 객체 생성
    sim.readSimulationParameters();     // 시뮬레이션 파라미터 설정
    sim.run();                          // 시뮬레이션 시작
    sim.printStat();                    // 시뮬레이션 결과 출력
}