#include <iostream>
using namespace std;

string notharfiniver(int sayi){
    if(sayi > 90) return "AA";
    else if(sayi > 75) return "BB";
    else if(sayi > 50) return "CC";
    else return "FF";
}

int main(){
    float vizenotu , finalnotu ; 
    float ortalama ; 

    cout << "once vize sonra final notunu giriniz : " << endl;
    cin >>vizenotu >>finalnotu;

    ortalama  =  vizenotu * 0.4 + finalnotu * 0.6 ; 
    cout << "ortalama : "<< ortalama << endl;
    cout << notharfiniver(ortalama);

    return 0;

}