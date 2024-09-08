#include <iostream>
#define size 5
using namespace std;

void scan_number(int *a ){
    for(int i = 0 ; i< size ; i++){
        cout<< "please enter number: " << endl;
        cin >> *(a+i) ;   
    }
}
void print_number(int *a){
    for(int i = 0 ; i< size ; i++){
        cout<< "number: " << *(a+i)  << endl;
    }
}

int main(){
    int Numbers[size]; 
    int *a = Numbers;
    scan_number(a);
    print_number(a);
    

return 0;}