#include <iostream>
#include <string>
using namespace std;

int main() {
    string first,second,a,c,d,e,g,m,n,x;
    cin >> first >> second;
    c = first[0];
    d = second[second.size()-1];
    e = c+d;
    a = first + second ;
    cout << first.size() << " " << second.size()<<endl;
    cout << a<<endl; 
    for(int i=0;i<second.size()-1;i++){
        cout << second[i];
    }
    for(int j=1;j<first.size();j++){
        cout << first[j];
    }
    cout << " "<< e ; 
   
    return 0;
}