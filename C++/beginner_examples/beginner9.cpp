#include <iostream>
using namespace std;
#define size 5

int main(){
    int *ptr = new int;  // new int fonksiyonu ile bir int değer kadar yer ayırdık.
    *ptr = 5;
    cout << *ptr << endl;
    delete ptr ; //delete ptr ile bu pointer içindeki değeri silebiliriz ama hala o adrese yeni atama yapabiliriz.
    *ptr = 12; // yeni atama yapabiliriz delete ptr dedikten sonra 
    cout << *ptr << endl; 
    ptr = nullptr;  //ptr tamamen silmek istersek de nullptr kullanmalıyız. Bundan sonra bu ptr ile işlem yapamaz hale geliriz.
    
    int *ptr1 = new int[size];
    *ptr1 = 10;
    *(ptr1+1) = 20;
    *(ptr1+2) = 30;
    *(ptr1+3) = 40;
    *(ptr1+4) = 50;

    for(int i=0;i<size;i++){
        cout << *(ptr1 + i) << endl;
    }

    delete [] ptr1;

    for(int i=0;i<size;i++){
        cout << *(ptr1 + i) << endl;
    }


    

}
