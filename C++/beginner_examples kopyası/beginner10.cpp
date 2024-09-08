#include <iostream>
using namespace std;
#define size 5

int main(){    
    int *ptr1 = new int[size];
    *ptr1 = 10;
    *(ptr1+1) = 20;
    *(ptr1+2) = 30;
    *(ptr1+3) = 40;
    *(ptr1+4) = 50;

    for(int i=0;i<size;i++){
        cout << *(ptr1 + i) << endl;
    }

    delete [] ptr1; // bu şekilde ptr1 değerlerini sıfırlarız.

    for(int i=0;i<size;i++){
        cout << *(ptr1 + i) << endl;
    }

    ptr1 = nullptr; // bu şekilde ptr1 i tamamen silebiliriz ve yeni atama yapamayız.

    for(int i=0;i<size;i++){
        cout << *(ptr1 + i) << endl;
    }

    

}