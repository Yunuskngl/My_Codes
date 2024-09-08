//hesap makinesi yap döngü , if else 

#include <iostream>
using namespace std;

int main(){
    int a,b;
    char islem;
    cout << "birinci sayiyi giriniz : ";
    cin >> a;
    cout << "ikinci sayisi giriniz: ";
    cin >> b;
    cout << "islemi giriniz : ";
    cin >> islem;

    while(1){
        if(islem == '+')  cout << "toplam : " << a+b << endl;
        else if(islem == '-') cout << "fark: " << a-b << endl;
        else if(islem == '*') cout << "carpim: " << a*b << endl;
        else if(islem == '/') cout << "bölüm : " << a/b << endl;
        else{
            cout << "hatali islem" << endl;
        
        }

        cout << "birinci sayiyi giriniz : " ;
        cin >>a;
        cout << "ikinci sayiyi giriniz : ";
        cin >> b;
        cout << "islemi giriniz: ";
        cin >> islem;
        if(islem == 'q'){
            break;
        }

    }
    return 0;
}

