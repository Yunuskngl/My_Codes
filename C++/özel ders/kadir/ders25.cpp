// tahmin oyunu : 

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
int main(){

    // rastgele sayı üreticisi : 
    srand(static_cast <unsigned>(time(0)));  // vector yapısı kullanılarak yazılmış bir srand fonksiyonu
    // Rastgele sayiyi 1 - 100 arasında üret :
    int target  = rand() % 100 +1;
    int tahmin; 
    int hak = 5; 
    bool kazanma = false; 
    cout << "tahmin oyununa hoş geldiniz : " << endl;
    cout << " 1 ile 100 arasında bir sayı tuttum. bakalım tahmin edelim ? ";
    while(hak > 0 ){
        cout << "tahmininizi giriniz : (KALAN HAKLAR : " << hak << "):";
        cin >>tahmin;
        if(tahmin < 1  || tahmin >100) {
           cout << "lütfen 1 ile 100 arasında sayi giriniz : " << endl;
           continue;
        }
        if(tahmin == target) {
            cout << "tebrikler doğru tahmin.... " << endl;
            kazanma = true;
            break;
        }
        else{
            if(abs(tahmin-target) <= target*0.1){
                cout << "çok yakın!!"<< endl;
            }
            else if(abs(tahmin -target) <= target * 0.2){
                cout << "yakın!!!" << endl;
            }
            else{
                cout << "uzak!!" << endl;

            }

            if (tahmin > target ){
                cout << "daha düşük bir sayı giriniz." << endl;

            }
            else{
                cout << "daha yüksek bir sayi giriniz." << endl;
            }
        }
        hak--;

    }
    if(!kazanma){
        cout << "malesef hakkınız bitti."<< endl;
    }







}

