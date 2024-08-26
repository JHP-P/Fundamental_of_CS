// ArrayList.cpp : 배열을 이용한 리스트 클래스 테스트 프로그램
#include "6_1_ArrayList.h"
int main()
{
    ArrayList list;
    list.insert( 0, 10 );
    list.insert( 0, 20 );
    list.insert( 1, 30 );
    list.insert( list.size(), 40 );
    list.insert( 2, 50 );
    list.display();

    list.remove (2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.replace(1, 90);
    list.display();

    list.clear();
    list.display();
}