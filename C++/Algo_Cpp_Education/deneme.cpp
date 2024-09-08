#include <iostream>
using namespace std;

void toplama (int a, int b, int c);{
    int toplam = a + b + c;
   
}
int main(){
    int a, b, c;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    toplama(a, b, c);
    cout << "Toplam: " << toplama << endl;
    return 0;
}