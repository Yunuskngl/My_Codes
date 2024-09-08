#include <iostream>
#include <fstream>
//DOSYA YAZMA
using namespace std;

int main(){
    ofstream dosya("C:\\Users\\YNS\\Desktop\\deneme.txt");
  //ofstream dosya("C:\\Users\\YNS\\Desktop\\deneme.txt",std::ios_base::app);   eğer üzerine ekleme yapmak istersek bu şekilde yaparız.


    dosya << "ben bu dosyayi basarili bir sekilde olusturdum 15258 . * 3" << endl;
}