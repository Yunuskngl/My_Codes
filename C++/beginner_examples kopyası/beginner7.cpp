//referans kavramı 
#include <iostream>
using namespace std;

void switch_with_reference(int &a,int &b){
    int temp;
    temp = a; 
    a = b; 
    b = temp;
}
int main(){
    int a = 123456;
    int b = 789101;
    
    cout << "number1 : " << a <<  endl << "number2 : " << b << endl;
    switch_with_reference(a,b);
    cout << "number1 : " << a  <<  endl << "number2 : " << b << endl; 



}
