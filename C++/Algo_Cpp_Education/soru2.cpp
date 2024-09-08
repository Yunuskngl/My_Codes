/*Kullanıcıdan iki adet 3x3 boyutunda matris girmesini isteyiniz ve bu iki matrisi yazdırınız.Ardından bu iki matrisin toplamını başka bir matrise aktarıp yeni matrisi de ekrana yazdırınız. (Fonksiyon kullanılacak)*/

#include <iostream>
using namespace std;

void matrisGir(int matris[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << i + 1 << ". satir " << j + 1 << ". sutun elemanini giriniz: ";
            cin >> matris[i][j];
        }
    }
}

void matrisYaz(int matris[3][3]){
    cout << "Matris: " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << matris[i][j] << " ";
        }
        cout << endl;
    }
}

void matrisTopla(int matris1[3][3], int matris2[3][3], int matris3[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matris3[i][j] = matris1[i][j] + matris2[i][j];
        }
    }
}


int main(){
    int matris1[3][3], matris2[3][3], matris3[3][3];
    cout << "1. matrisi giriniz: " << endl;
    matrisGir(matris1);
    cout << "2. matrisi giriniz: " << endl;
    matrisGir(matris2);
    matrisYaz(matris1);
    matrisYaz(matris2);
    matrisTopla(matris1, matris2, matris3);
    matrisYaz(matris3);
    return 0;
}

