#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/weird-mean-calculation-2/detail

int main() {
// write your code here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, sum = 0; 
    cin >> N;
    set<int> scores;
    for (int i = 0; i < N; i++){
        int temp; 
        cin >> temp;
        scores.insert(temp);
    }
    for(auto score : scores) sum+=score;
    cout<<round(sum/scores.size());
    return 0;
}
