#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
    ll size, count = 0;
    cin >> size;
    vector<ll> arr(size);

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int j = 0; j < size - 1; j++) {
        for (int m = j + 1; m < size; m++) {
            if (arr[j] == arr[m]) {
                arr[m]++;
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
