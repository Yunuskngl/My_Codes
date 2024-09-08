#include <iostream>
using namespace std;
//Templates

template <class rtype>

rtype sayinformations(rtype name,rtype surname){
    return name + " " + surname;
}
int main(){
    cout<<sayinformations<string>("Kaan","Academy")<<endl;
return 0;}
