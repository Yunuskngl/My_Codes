#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>


//kelimelerin içindeki her harfin sıralanması

//aaadaerfd
using namespace std;



int main(){

    string kelime;
    cout<< "kelimeyi giriniz: ";
    cin >> kelime;

    printf("%d\n",kelime[0]);
/*    for(int i = 0 ; i < kelime.length() ; i++){
        for(int j = i+1 ; j<kelime.length() ; j++){
            if(kelime[i]> kelime[j]){
                char bosdeger = kelime[i];
                kelime[i] = kelime[j];
                kelime[j] = bosdeger;

            }
        }
    }*/

    sort(kelime.begin(),kelime.end());

    cout << "sıralanmış kelime : " << kelime << endl;
    return 0;
}