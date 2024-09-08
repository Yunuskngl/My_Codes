#include <iostream>
#include <string>

using namespace std;


//depodaki ürün sorusu. stok adetini ürün eklemek , çıkarmak için switch case kullancaz
//en son stok adetini yazdırcaz.

int main(){
    int stokadet;
    char islem;
    
    cout << "stok adetini giriniz : "<<endl;
    cin >> stokadet;

    cout << "depodan ürün çıkarmak için - ,  ürün eklemek için + giriniz" << endl;
    cin>> islem;

    switch (islem){
        case '-':
            int cikarilacak;
            cout << "çıkarılacak ürün adedini giriniz : " << endl;
            cin >> cikarilacak;
            if(cikarilacak > stokadet){
                cout <<  "stok yetersiz!!!" << endl;
            }
            else{
                stokadet -= cikarilacak;
                cout <<" stok adeti : " << stokadet << endl;
            }
            break;

        case '+':
            int eklenecek;
            cout << "eklenecek ürün adeditini giriniz:" ;
            cin >> eklenecek;
            stokadet += eklenecek;
            cout <<" stok adeti : " << stokadet << endl;
            break;
        default:
            cout<< "hatalı işlem" << endl;
            break;
    }

//switch case kullancaksak char, int gibi sabit veri yapıuları kullanılır.
//onun harici veri yapıları if else ile daha doğru bir şekilde kullanılır.




}