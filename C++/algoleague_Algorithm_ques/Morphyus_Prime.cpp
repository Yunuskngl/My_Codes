#include <bits/stdc++.h>
#define ll long long 
using namespace std;

//https://algoleague.com/problem/morphyus-prime/detail

bool control(int num){
    
    while(num>0){
            int i = num%10;
            if(i != 2 && i != 3 && i != 5 && i != 7 ){
                return false; 
            }
            num/=10;
    }
    return true;
}

int main() {
// write your code here
    ll num,i=2,counter=0,flag = 0;
    cin>>num;
    
    while(i<=num){
        if(control(i)){
            counter++;
        }
        i++;
    }
    cout << counter ; 

	return 0;
}