//POINTERS
#include <iostream>
#include <string.h>

using namespace std; 

/*
void switch_value_for_numbers(int *x ,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int a , b;
    cout << "enter numbers" << endl;
    cin >> a >> b ;
    cout << a << " " << b << endl;

    switch_value_for_numbers(&a,&b);
    cout << a << " " << b << endl;
}
-------------------------------------------------*/

int main(){
    char name[10] = "kaan";
    char *NameAdress = name ;
    char *NameAdress2 = &name[0];

    cout << *NameAdress << " " << *NameAdress2 << endl;

    for(int i = 0 ; i <strlen(name);i++){
        cout << *(NameAdress +i) ;
    }

}