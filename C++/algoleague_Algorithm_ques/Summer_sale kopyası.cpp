#include <bits/stdc++.h>
#define ll long long
using namespace std;

//https://algoleague.com/problem/summer-sale/detail

int main() {
// write your code here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0 ; i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll q;
    cin>>q;
    for(ll m=0 ; m<q;m++){
        ll target;
        cin>>target;
        auto a = lower_bound(arr.begin(),arr.end(),k-target);
        auto b = upper_bound(arr.begin(),arr.end(),k+target);
        cout<<b-a<<endl;
    }
	return 0;
}
