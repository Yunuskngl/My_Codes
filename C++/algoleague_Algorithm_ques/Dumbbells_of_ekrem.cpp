#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/dumbbells-of-ekrem-2/detail

int main() {
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    int Sum[n];
    Sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        Sum[i] = Sum[i - 1] + arr[i];
    }

    for (int j = 0; j < q; j++) {
        int l, k;
        cin >> l >> k;
        int sum = (l > 1) ? (Sum[k - 1] - Sum[l - 2]) : Sum[k - 1];

        cout << sum << endl;
    }

    return 0;
}