#include <bits/stdc++.h>
using namespace std;

//https://algoleague.com/problem/set-bits/submission/3a0c96be-a000-0725-69bc-9c217042bb59/validate

int main() {
    int N;
    cin >> N;
    bitset<32> ikiliTemel(N);
    int birRakamSayisi = ikiliTemel.count();
    cout << birRakamSayisi << endl;

    return 0;
}
