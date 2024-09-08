//SOLUTION:

//https://algoleague.com/problem/an-easy-magic-trick/detail

/*
#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

int main() {
// write your code here
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll num;
    cin>>num;
    vector <ll> arr(1024);
    for(int i  = 1 ; i<=1024 ; i++) cin>>arr[i];
   
    ll right = 1024;
    ll left = 1;

    while(right>=left){
        ll mid = (right + left)/2;
        if(num < arr[mid]){
            right = mid-1;
            cout<<mid<<" "<<arr[mid]<<"\n";
        }
        else if(num == arr[mid]){
            cout << mid << " " << arr[mid] << "\n"; 
            return 0;
        }
        else{
            left = mid+1;
            cout<<mid<<" "<<arr[mid]<<"\n";
        }
    }
    

	return 0;
}*/