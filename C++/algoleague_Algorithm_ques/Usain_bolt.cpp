//SOLUTION:

//https://algoleague.com/problem/usain-bolt/detail

/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int record = arr[0];
    int sayac = 0 ; 
    for(int j=1 ; j<n; j++){
        if(record < arr[j]){
            sayac++;
            record = arr[j];
        }
    }
    cout<<sayac;
	return 0;
}
*/