// matematiksel işlemler

#include <iostream>
using namespace std;

int main(){
    int a = 10, b= 4 ;
    cout << "a+b = " << (a+b) << endl;
    cout << "a-b = " << (a-b) << endl;
    cout << "a*b = " << (a*b) << endl;
    cout << "a/b = " << (a/b) << endl;
    cout << "a%b = " << (a%b) << endl;

    float c = 10.0 , d = 4.1;
    cout << "c+d = " << (c+d) << endl;
    cout << "c-d = " << (float)c - (float)d << endl;
    cout << "c*d = " << (c*d) << endl;
    cout << "c/d = " << (c/d) << endl;
    cout << "c%d = " << (int)c % (int)d << endl;

    int e = 20;
    e++;
    ++e;
    cout << "e  = " << e << endl;

    int f=10;
    f--;
    --f;
    cout << "f = " << f << endl;

    f*=2;  // f = f*2;
    cout << "f = " << f << endl;

    



    return 0 ; 
}