//fonksiyonlar konusunun anlatımı

#include <iostream>
using namespace std;

//void fonksiyonu : eğer main içinden bu fonksiyon çağrılırsa geri dönüş veya herhangi bir tekrarlama olmadan direkt fonksiyon bloğu çalışır.

void printmesaj(){
    cout<< "hello kadir!!" <<endl;
}

//int , float , char  ... fonksiyonları
int add(int a,int b){
    return a+b;
}


int main(){
    printmesaj();

    /*  */
    int sonuc = add(5,3);
    sonuc*=2;
    cout<< sonuc << endl;
  
    cout << add(5,3) <<endl;
}