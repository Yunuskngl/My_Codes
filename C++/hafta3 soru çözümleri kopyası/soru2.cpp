/*
Farklı data typeları için (Char,int,float,double) değişken tanımlayıp değer ataması yapınız hem bu değerleri hem de bellekteki değerlerini yazdırınız.*/
#include <iostream>
using namespace std;
int main(){
    char *c = new char('a');
    int *i = new int(10);
    float *f = new float(10.5);
    double *d = new double(10.5);

    cout << "c: " << *c << endl;
    cout << "i: " << *i << endl;
    cout << "f: " << *f << endl;
    cout << "d: " << *d << endl;

    cout << "c: " << &c << endl;
    cout << "i: " << &i << endl;
    cout << "f: " << &f << endl;
    cout << "d: " << &d << endl;


    return 0;
}
