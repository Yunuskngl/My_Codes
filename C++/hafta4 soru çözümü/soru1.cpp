/*
Üç adet ürünümüz var : Kitap,Temel Gıda ve Lüks.Devlet her üç gruba farklı oranlarda vergi uyguluyor. Kitap için %4.0 , Temel gıda için için %5.6, Lüks için %19.6 olarak uygulanıyor. Her ürünün bir kodu var : Kitap kodu 0 ; Temel gıda kodu 1 ; lüks ürün kodu 2.Kullanıcıdan istediğiniz ürünün kodunu ve fiyatını isteyen daha sonra Switch case yapısını kullanarak son fiyatını ekrana bastıran bir c++ programı yazınız. */

#include <iostream>
using namespace std;

int main()
{
    int kod;
    float fiyat;  
    cout << "Urun kodunu giriniz: ";
    cin >> kod;
    cout << "Urun fiyatini giriniz: ";
    cin >> fiyat;
    switch (kod){
    case 0:
        cout << "Kitap icin vergi orani: " << fiyat * 0.04 << endl;
        break;
    case 1:
        cout << "Temel gida icin vergi orani: " << fiyat * 0.056 << endl;
        break;
    case 2:
        cout << "Lüks icin vergi orani: " << fiyat * 0.196 << endl;
        break;
    default:
        cout << "Hatali kod girdiniz." << endl;
        break;
    }
    return 0;
}

