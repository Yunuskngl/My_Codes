#include <iostream>
using namespace std;

class kitap{
    public:
    string isim;
    public:
    void bilgilerisöyle(){
        cout << isim << endl;
    }
};
class roman : public kitap{
    public:
    string romantipi;
    public:
    roman(string isim , string romantipi){
        this->isim = isim;
        this->romantipi = romantipi;
    }
    void bilgilerisöyle(){
        cout << isim << " " << romantipi << endl;
    }

};

int main(){
    roman r1("Dokuzuncu hariciye kogusu","uzun");
    r1.bilgilerisöyle();

    /*iki tane bilgilersöyle fonksiyonu olduğundan biz sadece kitap classının  içindeki bilgilerisöyle fonksiyonunu kullanmak için aşağıdaki işlemi yaparız.*/
    
    kitap *k1;
    k1 =  &r1;                      // Bu şekilde pointer kullanırız.
    k1->bilgilerisöyle();

}