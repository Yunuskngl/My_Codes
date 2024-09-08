#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/swimming-melih/detail


int main() {
    int size;
    cin >> size;
    vector<int> arr(size * 2);
    for (int i = 0; i < size*2; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int temp;
    int cost = 0;
    for (int h = 0; h < size*2; h+=2) {
        temp = arr[h + 1] - arr[h];
        cost += temp;
    }
    cout << cost;
    return 0;
}

