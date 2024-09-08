#include <iostream>
#include <string>

using namespace std;

//parametresiz bir fonksiyon tanımı 
void helloworld(){
    cout << "merhaba , dünya " << endl;
}

//parametre alan ve geri dönüş değeri olmayan bir fonksiyon tanımı 
void printmessage(string mesaj){
    cout << "mesaj" << mesaj << endl;
}

//iki parametre alan ve toplamlarını geri döndüren bir fonksiyon
float add(float a , float b){
    return a+b;
}

//referans parametre kullanan bir fonksiyon tanımı 
void increment(int &value){
    value++;

}

//default parametre kullanan bir fonksiyon tanımı
void selamlama(string name = "Ziyaretçi"){
    cout << "merhaba, " << name << "!" << endl;
}

int main(){
    helloworld();
    string a = "kadir ve ynus";
    printmessage(a);
    printmessage("ders işlemek");

    int sonuc = add(5.4,6.3);
    cout << "toplam: " << sonuc << endl;

    int num = 10;
    increment(num);
    cout << " arttırılmış değer : " << num << endl;


    selamlama();
    selamlama("ahmet")






    
}
