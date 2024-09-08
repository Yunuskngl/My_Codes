// switch case işlemleri ile devam edicez.

#include <iostream>
#include <string>

using namespace std;

int main(){
    int a;
    cout <<"bir sayi girin: "<< endl;
    cin >> a;

    switch (a){
        case 1:
            cout<< "a 1'e eşittir. " << endl;
            break;
        case 2:
            cout<< "a 2'e eşittir. " << endl;
            break;
        case 3:
            cout<< "a 2'e eşittir. " << endl;
            break;
        case 4:
            cout<< "a 4'e eşittir. " << endl;
            break;
        case 5:
            cout<< "a 5'e eşittir. " << endl;
            break;
        default:
            cout<< "A hiç bişete eşit değil"<< endl;
            
    }
}