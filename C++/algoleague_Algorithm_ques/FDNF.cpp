/*
Numbers with exactly 4 positive divisors are called FDNF numbers. For example 
6
 is a FDNF number because it has 4 divisors:
[
1
,
2
,
3
,
6
]

Given 
N
, find how many numbers are FDNF numbers in the range 
[
1
,
N
]
, inclusive.

Input Format
First and the only line contains 
N
, the upper bound

Output Format
Print number of FDNF numbers in the range 
[
1
,
N
]

Constraints
1
≤
N
≤
10
5

Sample Input 1 

7
Sample Output 1 

1
Explanation 1

The only FNDF number in the range is 6.*/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

/*
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;
    ll count=0;
    for(ll i=1;i<=n;i++){
        ll c=0;
        for(ll j=1;j<=sqrt(i);j++){
            if(i%j==0){
                if(i/j==j){
                    c++;
                }
                else{
                    c+=2;
                }
            }
        }
        if(c==4){
            count++;
        }
    }
    cout<<count;
    return 0;
}*/
