#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

//https://algoleague.com/problem/divisort/detail

int main() {
// write your code here
    ios::sync_with_stdio(0);
    cout.tie(0);
    ll num;
    cin>>num;
    vector<ll>arr;
    for(ll i=1;i*i <=num;i++){
        if(num%i == 0){
            arr.push_back(i);
            if (i != num / i) {
                arr.push_back(num / i);
            }
        }
    }sort(arr.begin(),arr.end());
    for(const auto &elements : arr){
        cout<<elements<<" ";
    }
	return 0;
}