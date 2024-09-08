#include <iostream> 
#include <stdlib.h>
#include <time.h>
// C dilindeki tüm kütüphaneler burada da kullanılabilir.
using namespace std;

int main(){
    string isim = "kaan academy";
    for(char character  : isim)   
        cout << character <<endl;
//bu şekilde bir string içindeki tüm karakterleri tek tek yazdırabiliriz.

    return 0 ; 
}
