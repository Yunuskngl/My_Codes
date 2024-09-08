#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/meme-man/detail

long long n,x,y;
long long f(long long q){
    if(!q) return 1;
    if(q<0) return 0 ; 
    return f(q-x) + f(q-y);
}
int main() {
    cin >>n>>x>>y;
    cout << f(n);

	return 0;
}
