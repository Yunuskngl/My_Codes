#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/stringer-things/detail

int main() {
    int n;
    cin >> n ; 
    char b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    
    char temp;
    temp = b[0];
    cout<<temp;
    for(int i=1;i<n;i++){
        if(b[i] != temp){
            cout << b[i];
            temp=b[i];
        }
    }

	return 0;
}
