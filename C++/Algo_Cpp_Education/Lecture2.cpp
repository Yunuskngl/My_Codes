#include <iostream>
using namespace std;
//DİZİLER;

int main() {
    // Tek boyutlu dizi
    int tekBoyutluDizi[5] = {10, 20, 30, 40, 50};
    cout << "Tek boyutlu dizi elemanlari:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << tekBoyutluDizi[i] << " ";
    }
    cout << endl;

    // İki boyutlu dizi
    int ikiBoyutluDizi[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Iki boyutlu dizi elemanlari:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << ikiBoyutluDizi[i][j] << " ";
        }
        cout << endl;
    }

    //Karakter Dizileri:

    // std::string kullanımı
    string metin = "Merhaba, dünya!";
    
    // Stringi ekrana yazdırma
    cout << "Metin: " << metin << endl;
    
    // Stringin uzunluğunu bulma
    cout << "Metin uzunlugu: " << metin.length() << " karakter" << endl;
    
    // String birleştirme
    string ekMetin = " Nasilsiniz?";
    string birlesikMetin = metin + ekMetin;
    cout << "Birlesik metin: " << birlesikMetin << endl;
    
    // Stringin belirli bir kısmını alma
    string altMetin = metin.substr(8, 5); // 8. karakterden başlayarak 5 karakter al
    cout << "Alt metin: " << altMetin << endl;
    
    // Stringde arama yapma
    string aranan = "dünya";
    size_t pozisyon = metin.find(aranan); // Aranan kelimenin başlangıç pozisyonunu bul
    if (pozisyon != string::npos) {
        cout << "'" << aranan << "' kelimesi bulundu. Pozisyon: " << pozisyon << endl;
    } else {
        cout << "'" << aranan << "' kelimesi bulunamadi." << endl;
    }
    
    //String fonksiyonları:
    string example;
    string name =  "SKYLABharika";
    string name2 = "ALGOLAB";
    string copy ;
    getline(cin,example); // bu fonksiyon boşluklu input girsek bile tamamını alıyor.
    copy.assign(name);  // bu fonksiyon copy değerine name değerini gönderir.
    name.at(0); // bu fonksiyon ile string içindeki hangi indexi istiyorsak onu alabiliriz.
    name.length(); //bu fonksiyon ile string uzunluğunu buluruz.
    name.substr(2,3); // bu fonksiyon ile 2. indexten başlayıp 3 harf kadar yazdırırız.
    name2.swap(name); // bu fonksiyon ile name ve name2 değerlerini değiştiririz.
    name.erase(2,3); // 2 indexten başlayıp 3 karakter siler.
    name.find("hari"); // bu "Kn" harfleri kaçıncı indexten başlıyor onu bulur.
    name.replace(0,5,"ALGOLAB"); //bu fonksiyonu kullanırsak ALGOLABharika olarak değiştiririz.

    return 0;
}