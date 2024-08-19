class Car{
protected:
    int speed;
    int name[]
public:
    int gear;
    Car(){}
    ~Car(){}
    Car(int s, int g, char* n)  // 매개변수가 있는 생성자
        : speed(s), gear(g) {   // 멤버 초기화 리스트(멤버변수 초기화)
            strcpy(name, n);    // 생성자 함수 몸체 (name 멤버 초기화)
    }
    void changeGear(int g=4){   // 기어 단수를 변경하는 멤버 함수
        gear = g;
    }
    void speedUp(){
        speed +=5;
    }
    void display(){
        printf("[%s] : 기어=&d단 속도=%dkmph\n", name, gear, speed);
    }
    void whereAmI() {printf("객체 주소 = %x\n", this)}  // this 포인터
}