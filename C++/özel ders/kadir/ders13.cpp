//fonksiyonlarda overloading hatasını anlatımı

/*
Fonksiyon overloading(aşırı yükleme) , aynı isimde birden fazla fonksiyon tanımlamayı mümkün kılan ve her birinin
farklı parametre türlerine veya farklı sayıda parametreye sahip olmasını sağlayan bir c++ özelliğidir.
*/

#include <iostream>
using namespace std;

int topla(int a,int b){
    return a+b;
}


int topla(int a , int b , int c){
    return a + b + c;
}

double topla(double a , double b) {
    return a + b;
}


int main(){
    cout << topla(5,6)<<endl;
    cout << topla(5,6,7)<<endl;
    cout << topla(5.5,6.9)<<endl; 
    return 0; 
}
   
