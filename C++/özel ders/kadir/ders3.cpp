// string işlemleri : 

#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "hello world kadir selam ders işliyoruz cart curt";
    cout << str << endl;  // printf("%s",str)

    string isim;
    string  soyisim;
    string yas ;

    cout << "Lütfen isminizi , soyisiminizi ,yaşınızı giriniz : ";
    cin >> isim >> soyisim >> yas;

    cout << "merhaba " << isim << " " << soyisim << " " << yas << " yaşındasınız" << endl;

    
}
