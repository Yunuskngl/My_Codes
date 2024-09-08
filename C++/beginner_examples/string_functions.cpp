#include <iostream>
#include <string>
using namespace std;

int main(){
    string example;
    string name =  "YnsKngl";
    string name2 = "ZeynpAsln";
    string copy ;
    getline(cin,example); // bu fonksiyon boşluklu input girsek bile tamamını alıyor.
    copy.assign(name);  // bu fonksiyon copy değerine name değerini gönderir.
    name.at(0); // bu fonksiyon ile string içindeki hangi indexi istiyorsak onu alabiliriz.
    name.length(); //bu fonksiyon ile string uzunluğunu buluruz.
    name.substr(2,3); // bu fonksiyon ile 2. indexten başlayıp 3 harf kadar yazdırırız.
    name2.swap(name); // bu fonksiyon ile name ve name2 değerlerini değiştiririz.
    name.erase(2,3); // 2 indexten başlayıp 3 karakter siler.
    name.find("Kn"); // bu "Kn" harfleri kaçıncı indexten başlıyor onu bulur.
    name.replace(0,4,"Zeynep"); //bu fonksiyonu kullanırsak ZeynepKngl olarak değiştiririz.
    
}