//çok boyutlu arrayler matris

#include <iostream>


using namespace std;

int main(){
    int matris[3][3];
    int i,j;

    for(i = 0 ; i<3; i++){
        for(j= 0 ; j<3 ; j++){
            cout <<"lütfen matris elemanlarını giriniz[" << i << "][" << j << "] : ";
            cin>> matris[i][j];
        }
    }

    cout << "matrisin elemanları : " << endl;
    for(i=0; i<3 ; i++){
        for(j=0 ; j<3; j++){
            cout << matris[i][j] << " ";
        }
        cout<< endl;
    }
    


    return 0;
}