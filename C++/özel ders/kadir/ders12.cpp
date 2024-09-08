//fonksiyon eğer int main altında yazılırsa.


#include <iostream>
using namespace std;


void printmesaj();  // ben printmesaj adında bir void fonksiyonu kullanıcam.

int main(){

    printmesaj();
    return 0;
}

void printmesaj(){
    cout<< "hello"<<endl;
}