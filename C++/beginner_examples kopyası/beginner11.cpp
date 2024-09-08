#include <iostream>
#include <vector>
#include <bits/stdc++.h> // tüm cpp kütüphanelerini kullanmak için yazılır 
#define size1 3
using namespace std ; 

int main(){
    vector < int > v1(size1);
    vector < int > v2(size1);
    vector < int > v3;

    //cout << "vector boyu : " << v1.size() << endl;  // bu şekilde vectör boyunu alabiliriz.
    for(int i = 0 ; i < size1 ; i++){
        cin >> v1[i];
        v3.push_back(v1[i]);
    }
    for(int i = 0 ; i < size1 ; i++){
        cin >> v2[i];
        v3.push_back(v2[i]);  //buralarda v3 e ekleme yapıyoruz .
    }
    cout<<v3.size();
    for(int a=0 ; a < v3.size() ; a++) cout << v3[a] << " " ;

    /*
    -at() = Parametre olarak belirtilen index değerine karşılık gelen elemanı döndürür. örn: vect_int_item.at(0); ilk elemanı döndürür.
-front() = Vectorün en başında yer alan elemanı döndürür.
-back() = Vectorün en sonunda yer alan elemanı döndürür.
-swap() = Vectorler arasında elemanları değiş tokuş eder.
Örnek kullanım:
vector<int> vect1(10,44);
vector<int> vect2(15); //15 elemanlı.
vect1.swap(vect2);
Bu kullanım sonucunda vect1 içeriği eleman olarak 0(sıfır) değerleri,vect2 içeriği elemanları ise 44 değerler yer alacaktır.
Ayrıca swap sonucunda vectorlere ait eski boyutlar da yeni elemanlara göre değişecektir. Yani vect2 boyutu 10 olarak değişmiştir.
-push_back() = Vectorün sonuna eleman ekler.
-pop_back() = Vectorden son elemanı çıkarır/siler.
-empty() = Vectorün boş olup olmadığını belirleyen bir bool durum döndürür.
-insert() = Belirtilen bir pozisyona yeni eleman ekler.
-erase() = Belirtilen bir elemanı vectorden siler.
-resize() = Vectorün boyutunu değiştirir.
-clear() = Vectordeki tüm elemanları siler.
-size() = Vectordeki eleman sayısını belirtilen bir değer döndürür.
-capacity() = Vectorün mevcut kapasitesini belirten bir değer döndürür.
-assign() = Vecktore yeni değerler atamak için kullanılır. En temel haliyle iki adet parametre alır. İlk parametre eleman sayısı,ikinci parametrede atanacak değer belirlenir.*/ 




}