// 학생 정보를 나타내는 클래스
#include <cstdio>
#include <cstdlib>
#include <cstring>          // C헤더파일
#define MAX_STRING  100
class Student{
    int id;                 // 학번
    char name[MAX_STRING];  // 이름
    char dept[MAX_STRING];  // 소속 학과
public:
    Student(int i=0, char* n="", char* d="") { set (i, n, d); }
    void set(int i, char* n, char* d){
        id = i;
        strcpy(name, n);
        strcpy(dept, d);
    }
    void display(){
        printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
    }
};