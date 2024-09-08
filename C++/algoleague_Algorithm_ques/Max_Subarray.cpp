#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/max-subarray-2/detail

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int arr1[n - k + 1]; 
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (i >= k) {
            sum -= arr[i - k];
        }
        if (i >= k - 1) {
            arr1[i - k + 1] = sum;
        }
    }
    int max_sum = arr1[0];
    for (int j = 1; j < (n - k + 1); j++) { 
        if (arr1[j] > max_sum) {
            max_sum = arr1[j];
        }
    }
    cout << max_sum;

return 0;}