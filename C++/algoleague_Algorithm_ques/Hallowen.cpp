#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/cadilar-bayrami/detail

int main(){
    int size;
    
    cin>>size;
    int flag;
    //int sumcandy = 0 ;
    vector<int>childcandy(size);
    if(size==1){
        cout<<"1\n";
        return 0;
    }
    for(int i=0 ; i<size ; i++){
        cin>>childcandy[i];
        
    }
    sort(childcandy.begin(),childcandy.end());
    int ardacandy;
    cin >>ardacandy;
    int sum=0;
    for(int j=0 ; j<size-1 ; j++){
        flag = childcandy[size-1] - childcandy[j];
        sum += flag;
    }
    if(sum == ardacandy ){
        cout << 1;
        return 0;
    }
    if(ardacandy>sum && (ardacandy-sum)%size == 0){
        cout<<"1\n";
    }
    else{
        cout<<"0\n";
    }
    return 0;



}