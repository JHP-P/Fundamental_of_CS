#include "02_7_Polynomial.h"
int main(){
    Polynomial a, b, c;
    a.read();
    b.read();
    c.add (a, b);
    a.display("A = ");
    b.display("B = ");
    c.display("A+B = ");
}