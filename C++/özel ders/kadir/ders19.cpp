#include <iostream>
using namespace std;

//const = sabit. değiştirilemez.


//const ifadesini global değişkenlerde kullanımı.
const int Max_Size = 100;  


//const parametre kullanan fonksiyon
void printmesaj(const string& mesaj){
   
    cout << mesaj << endl;
}




int main(){
    cout << Max_Size <<endl;
    

    int num = 10; 
    const int* ptr1 = &num;  // pointer'ın gösterdiği değer değiştirelemz.
    int* const ptr2 = &num;  //pointer'in kendisi sabit.
    const int* const ptr3 = &num; //hem pointer sabit hem de gösterdiği değer değiştirelemez olduğunu söyler.

    string message = "merhaba arkadaşlar";
    printmesaj(message);



}
