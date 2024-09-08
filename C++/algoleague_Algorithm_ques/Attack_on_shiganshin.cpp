//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
// write your code here
    ll size1,size2,counter = 0; 
    cin>>size1>>size2;
    vector<ll>team1(size1);
    vector<ll>team2(size2);
    
    for(int i=0;i<size1;i++){
        cin>>team1[i];
    }
    for(int j=0;j<size2;j++){
        cin>>team2[j];
    }
    sort(team1.begin(),team1.end());
    sort(team2.begin(),team2.end());
    
    for(int k=0;k<size2;k++){
        counter = 0;
        for(int m=0;m<size1;m++){
            if(team2[k] > team1[m]) counter++;
        }
        cout<< counter << " " ; 
    }
	return 0;
}