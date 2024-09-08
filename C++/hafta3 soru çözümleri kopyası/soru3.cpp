/*
Kullanıcıdan iki değer alın .Bunları recursive fonksiyon ile içine atıp pointer kullanarak ikisinin değerini değiştirerek yazdırınız. */
#include <iostream>
using namespace std;
void degistir(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a,b;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    degistir(&a,&b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}
