// random sayı üreten algoritmayı .

#include <iostream>
#include <time.h>

using namespace std;

int main(){
    int x;
    srand(time(0));
    x= rand();

   // -- 0 ile 37594 

    cout << x; 
}