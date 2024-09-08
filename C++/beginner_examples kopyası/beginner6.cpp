//const ifadesi : sabit kavram.
// makrolar 
#include <iostream>
using namespace std;
using std :: cin; // bu şekilde de kütüphane içinden tek bir fonksiyon kullanabilriz.
int main(){
    const int number = 1 ; //bu sayiyi artık değiştiremezsin .

    int x,y,t;
    x = 7; 
    y = 6;

    t = (x > y) ? x : y ;  // makro
    //burda parantez içindeki değeri kontrol eder eğer true ise
    //x değerini eğer false ise y değerini t'ye eşitler.
    cout << t; 
    return 0 ; 




}