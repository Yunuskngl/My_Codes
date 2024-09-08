//sayıların sıralanması 
#include <iostream>
#include <string>
using namespace std;
int main(){
    int dizi[5];
    int temp;
    for(int i=0;i<5;i++){
        cout << i+1 << ".sayıyı giriniz: "<< endl;
        cin>> dizi[i];
    }
    /*
    for(int i=0;i<5;i++){   // 4 7  8  9 10
        for(int j=i+1 ; j<5; j++){
            if(dizi[i]>dizi[j]){
                temp = dizi[i];  // temp 7 
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }

        }
    }*/
    sort(dizi,dizi+5);
    cout<< "Siralanmiş dizi : " << endl;
    for(int i=0;i<5;i++){
        cout<<dizi[i]<< " "; 
    } 
    return 0;
}
