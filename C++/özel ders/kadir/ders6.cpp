#include <iostream>
#include <string>
using namespace std;

//dizi işlemleri int ve float dizisi

int main(){
    int a[5] = {1,2,3,4,5};
    float b[5] = {1.2,3.5,5.6,7.123,9.1231232};

    for(int i=0;i<5;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int j=0;j<5;j++){
        cout << b[j] << " ";
    }
 cout << endl;
    double m[3];
    for(int k = 0 ; k<3  ;k++){
        cin>> m[k];
    }
   cout << endl;

    for( int k = 0 ; k<3  ;k++){
        cout << m[k];
    }



    return 0 ; 
}
