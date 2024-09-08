#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/guls-problem/submission/3a0cbec6-3ef6-250d-ca11-b21190ef0c16/validate

int main() {
// write your code here
    vector <int> a(7);
    for(int i=0 ; i< 7 ; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(a[0] + a[1] == a[2]) cout<<a[3];
    else cout<<a[2];
    

	return 0;
}