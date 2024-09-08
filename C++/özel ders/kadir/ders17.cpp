#include <iostream>
using namespace std;

int main(){
    //basit bir değişken tanımlama
    int num = 10;

    //bu sayının adresini tutacak bir ptr tanımlayalım .
    int *ptr = &num;

    //pointer ile değişkenin adresini ve değerini yazdırma
    cout << num << endl;
    cout << &num << endl;
    cout << *ptr << endl;
    cout << ptr << endl;

    //ptr kullanarak değişkenin adresini değiştirmek istiyorum.
    *ptr  = 20;
    cout << num << " " << *ptr << endl;

    //bir dizi tanımlama
    int arr[5] = {1,2,3,4,5};

    //dizinin ilk elemanını tutan bir ptr tanımlicam
    int *arrptr  = arr;   // arr aslında &arr[0] anlamına gelir.

    //pointer aritmatiği ile dizi elemanlarına erişme
    cout << "dizinin ilk elemanı : " << *arrptr << endl;
    cout << "dizinin ikinci elemanı : " << *(arrptr+1) << endl;
    cout << "dizinin üçüncü elemanı : " << *(arrptr +2)<< endl;

    //dizinin elemanlarına ptr ile erişim ve değişim
    *(arrptr +3) = 10;
    cout << arr[3] << " " << *(arrptr +3) << endl;

    //NULL pointer kullanımı 
    int *nullPtr = nullptr;
    if (nullPtr == nullptr) {
        cout << "nullPtr herhangi bir adres göstermiyor" << endl;
    }





}