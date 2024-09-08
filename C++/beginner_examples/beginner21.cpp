#include<iostream>
using namespace std;

namespace kendikutuphanem{
    float pi=3.145;
    int toplama(int a ,int b){   //bu şekilde kendi namespaceimizi hazırlayabiliriz.
        return a+b;
    }
    float daireçevresihesaplama(float r){
        return 2*pi*r;
    }
    string sayinformations(string name,string surname){
            return name + " " + surname;
    }

}
int main(){
    using namespace kendikutuphanem;
    cout << daireçevresihesaplama(6.0) << endl;

    int a=20;
    int b=25;
    {
        int a=40;         // bu kod bloğunda geçici olarak değer değiştirme yapabiliriz.
        int b=50;
        cout <<a << endl << b << endl ;
    } 
    cout <<a << endl << b << endl ;
}
