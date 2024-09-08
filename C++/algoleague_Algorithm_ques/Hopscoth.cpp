#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/hopscotch/detail

int main() {
    long long a,b,temp,c;
    cin>>a;
    cin>>b;
    if(b>a){
        
        temp = b%a-1;
        b= temp + 1;
        if(b%2 == 0){
            b = b/2;
            b = b*3;
            cout<<b-1 << " " <<b;
        }
        else if(b%2 == 1){
            b=b-1;
            b = b/2;
            b = b*3;
            cout<<b+1;
        }
    }
    else{
        if(b%2 == 0){
            b = b/2;
            b = b*3;
            cout<<b -1 << " " <<b;
        }
        else if(b%2 == 1){
            b=b-1;
            b = b/2;
            b = b*3;
            cout<<b+1;
        }
    }
    
	return 0;
}