//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

//https://algoleague.com/problem/ice-cream-yum-yum/detail

#include <iostream>

int main() {
    using namespace std;

    int min;
    int n;
    int sum = 0;
    
    cin >> n;
    int arr[n];

    cin >> arr[0];
    min = arr[0];
    sum += arr[0];

    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    cout << sum - min;

    return 0;
}