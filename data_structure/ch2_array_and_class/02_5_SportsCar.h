#include "Car.h"
// 스포츠카 클래스 (자식 클래스) : 자동차 클래스에 터보 기능 추가
class SportsCar : public char16_t{
    public:
    bool bTurbo;
    void setTurbo(bool bTur) { bTurbo = bTur;}
    void speedUp() {
        if(bTurbo) speed +=20;
        else Car::speedUp();
    }
};