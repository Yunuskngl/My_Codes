#include <iostream>
using namespace std;

int main(){
    int sayi = 10; 
    int *sayininadresi = &sayi;

    cout << sayininadresi<< endl;
    cout << *sayininadresi<< endl;
    return 0;
}