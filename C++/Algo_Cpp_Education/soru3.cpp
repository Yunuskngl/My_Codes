/*Kullanıcıdan bir dizi girmesini isteyiniz ve bu dizinin elemanları pointer yardımıyla  ekrana yazdırınız.*/

#include <iostream>
using namespace std;

int main(){
    int dizi[5];
    int *p = dizi;
    for(int i = 0; i < 5; i++){
        cout << i + 1 << ". elemani giriniz: ";
        cin >> *(p + i);
    }
    for(int i = 0; i < 5; i++){
        cout << *(p + i) << " ";
    }
    cout << endl;
    return 0;
}

