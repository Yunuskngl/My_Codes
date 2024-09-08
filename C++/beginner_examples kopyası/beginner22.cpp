#include <iostream>
using namespace std;
//Exceptions:
int main(){
    string websitesi;
    cin>>websitesi;
    try{
        if(websitesi != "google.com"){
            throw 404;
        }
        else{
            cout<<"Sayfa yukleniyor..."<< endl;
        }

    }catch(int hatakodu){
        cout<<"Aradiginiz websitesi bulunamadi. Hata Kodu :" << hatakodu << endl;
    }
}